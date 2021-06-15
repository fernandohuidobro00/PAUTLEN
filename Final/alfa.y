
%{	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "generacion.h"
	#include "tablaSimbolos.h"
	#include "alfa.h"
	#include "tablaHash.h"
	
	

	void yyerror(char *s);
	extern int yylex();

	extern FILE *yyin;
	extern FILE *yyout;
	extern int yyleng;
	extern int linea, columna, error;

        /*Guarda las ctes enteras en formato cadena para imprimirlas en fichero NASM*/
	char cte_entera[20]; 

	int tipo_actual=INT, clase_actual=VECTOR;

	int longitud;
	int tamanio_vector_actual;

	int pos_variable_local_actual=0;
	int num_variables_locales_actual=0;
	int num_parametros_actual = 0;
	int pos_parametro_actual = 0;

	INFO_SIMBOLO* simbolo;

	INFO_SIMBOLO insertar;



	/*REVISAR PONER ALGUNOS SOLO A 1*/
	int control_retorno=0;
	int contador_not=0;
	int contador_cmp=0;
    int contador_cond=0;
	int contador_bucle=0;
	int parametros=0;
	int es_funcion=0;
	int es_llamada=0;

	/*TABLA_HASH tablaGlobal = NULL;
	TABLA_HASH tablaLocal = NULL;*/

	tablaSimbolos tabla;	/* Tabla de simbolos*/
	tabla=CrearTablaGlobal();
%}

%union{
	tipo_atributos atributos;
}

%token  TOK_MAIN
%token  TOK_INT
%token  TOK_ARRAY
%token  TOK_BOOLEAN
%token  TOK_FUNCTION
%token  TOK_IF
%token  TOK_ELSE
%token  TOK_WHILE
%token  TOK_SCANF
%token  TOK_PRINTF
%token  TOK_RETURN

%token  TOK_PUNTOYCOMA
%token  TOK_COMA
%token  TOK_LLAVEIZQUIERDA
%token  TOK_LLAVEDERECHA
%token  TOK_PARENTESISIZQUIERDO
%token  TOK_PARENTESISDERECHO
%token  TOK_CORCHETEIZQUIERDO
%token  TOK_CORCHETEDERECHO
%token  TOK_MAS
%token  TOK_MENOS
%token  TOK_DIVISION
%token  TOK_ASTERISCO
%token  TOK_AND
%token  TOK_OR
%token  TOK_ASIGNACION
%token  TOK_IGUAL
%token  TOK_NOT
%token  TOK_DISTINTO
%token  TOK_MENORIGUAL
%token  TOK_MAYORIGUAL
%token  TOK_MENOR
%token  TOK_MAYOR

%token  TOK_TRUE
%token  TOK_FALSE

%token TOK_ERROR


%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_IDENTIFICADOR


%type <atributos> condicional
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> identificador


%type <atributos> if_exp
%type <atributos> if_exp_sentencias

%type <atributos> while
%type <atributos> while_exp

%type <atributos> fn_name
%type <atributos> fn_declaration

%type <atributos> call_func

/*por prioridad, preguntar a alfonso, el ultimo*/

%left TOK_MAS TOK_MENOS TOK_OR
%left TOK_ASTERISCO TOK_DIVISION TOK_AND

%right TOK_NOT MENOSU



%start programa

%%
programa:   TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones escritura1 funciones escritura2 sentencias TOK_LLAVEDERECHA {
				fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
				fprintf( yyout, ";escribir_fin\n" );
       				escribir_fin( yyout );
				}
;


escritura_inicial: {
                 fprintf(yyout, ";escribir_subseccion_data\n" );
                 escribir_subseccion_data(yyout);
                 fprintf(yyout, ";escribir_cabecera_bss\n" );
                 escribir_cabecera_bss(yyout);
               }
  ;

escritura1: {
              fprintf( yyout, ";escribir_segmento_codigo\n" );
              escribir_segmento_codigo( yyout );
						}
  ;
escritura2: {
	      fprintf( yyout, ";escribir_inicio_main\n" );
              escribir_inicio_main( yyout );
}
	;


/*REGLA PR 2*/
declaraciones: declaracion {
			fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");
			}

/*REGLA PR 3*/
		| declaracion declaraciones {
				fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
		}
;

/*REGLA PR 4*/
declaracion: clase identificadores TOK_PUNTOYCOMA {
					fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
					}
;

/*REGLA PR 5,7*/
clase: clase_escalar {

			clase_actual = ESCALAR;
			fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");
			}
;


clase: clase_vector {
	
			clase_actual = VECTOR;
			clase_vector {fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");
			
			}
;

/*REGLA PR 9*/
clase_escalar:tipo {
			fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");
			}
;

/*REGLA PR 10,11*/
tipo: TOK_INT {
				tipo_actual = INT;
				fprintf(yyout, ";R10:\t<tipo> ::= int\n");
				}
;

tipo: TOK_BOOLEAN
		 	{
		 			tipo_actual = BOOLEAN;
					fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");
			}
;


/*REGLA PR 15*/
clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {
					fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");

					/*$4 tiene el tamaño del vector. Comprobaciones semanticas*/  /*diapositiva 31*/
					tamanio_vector_actual = $4.valor_entero;
  					if(tamanio_vector_actual<1 || tamanio_vector_actual > MAX_TAMANIO_VECTOR) {
    					fprintf(ERR_OUT, "****Error semantico en lin %d: El tamanio del vector incorrecto.\n", linea);
    					return -1;
  				}
				}
;

/*REGLA PR 18,19*/
identificadores: identificador {
					fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");
					}

					| identificador TOK_COMA identificadores {
						fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
					}
;



/*REGLA PR 20*/
funciones: funcion funciones {
					fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
					}
					|  {
						fprintf(yyout, ";R21:\t<funciones> ::=\n");
						}
;



fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR {
    control_retorno = 0;
    es_funcion=1;
    simbolo = UsoLocal($3.lexema);
    if(simbolo != NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Declaracion duplicada.\n", linea);
      return -1;
    }

    insertar.lexema = $3.lexema;
    insertar.categoria = FUNCION;
    insertar.clase = ESCALAR;
    insertar.tipo = tipo_actual;

    strcpy($$.lexema, $3.lexema);
    $$.tipo = tipo_actual;

    DeclararFuncion($3.lexema, &insertar);
    num_variables_locales_actual=0;
    pos_variable_local_actual=0;   
    num_parametros_actual = 0;
    pos_parametro_actual = 0;
};



fn_declaration : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion {
  /* Actualizar atributo num_parametros */
    simbolo = UsoLocal($1.lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Declaracion duplicada.\n", linea);
      return -1;
    }
    simbolo->valor1 = num_parametros_actual;
    strcpy($$.lexema, $1.lexema);
    $$.tipo = $1.tipo;
    declararFuncion(yyout, $1.lexema, num_variables_locales_actual);
};
/*REGLA PR 22*/

funcion: fn_declaration sentencias TOK_LLAVEDERECHA {
  if(control_retorno==0) {
    fprintf(ERR_OUT, "****Error semantico en lin %d: Funcion %s sin sentencia de retorno.\n", linea, $1.lexema);
    return -1;
  }
  CerrarFuncion();
 
  simbolo = UsoLocal($1.lexema);
  if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Declaracion duplicada.\n", linea);
      return -1;
  }
  simbolo->valor1 = num_parametros_actual;
  es_funcion = 0;
  fprintf(yyout, ";R22:\t<funcion> ::=function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");}

;


/*REGLA PR 23,24*/

parametros_funcion: parametro_funcion resto_parametros_funcion {
				fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
				}


			|  {
				fprintf(yyout, ";R24:\t<parametros_funcion> :=\n");
			}
;

/*REGLA PR 25,26*/
resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {
				fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
				}

				|  {
				fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");
				}
;


/*REGLA PR 27*/
parametro_funcion: tipo identificador {
			num_parametros_actual++;
  			pos_parametro_actual++;
  			fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
			}
;

idpf : TOK_IDENTIFICADOR {
    simbolo = UsoLocal($1.lexema);
    if(simbolo != NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: En declaracion\n", linea);
      return -1;
    }
    insertar.lexema = $1.lexema;
    insertar.categoria = PARAMETRO;
    insertar.clase = ESCALAR;
    insertar.tipo = tipo_actual;
    insertar.valor1 = num_parametros_actual;

    Declarar($1.lexema, &insertar);
};

/*REGLA PR 28,29*/
declaraciones_funcion: declaraciones {
				fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
				}

			|  {
			fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");
			}
;

/*REGLA PR 30,31*/
sentencias: sentencia {
				fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");
				}

				| sentencia sentencias {
					fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
				}
;

/*REGLA PR 32,33*/
sentencia: sentencia_simple TOK_PUNTOYCOMA {
				fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
				}

				| bloque {
				fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
				}
;

/*REGLA PR 34, 35,36,38*/
sentencia_simple: asignacion {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
		| lectura {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
		| escritura {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
		| retorno_funcion {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
;


/*REGLA PR 40,41*/
bloque: condicional {fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");}
	| bucle {fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");}
;

/*REGLA PR 43,44*/
asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp  {
    simbolo = UsoLocal($1.lexema);
    if(simbolo==NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
      return -1;
    } else {
      if(simbolo->categoria == FUNCION) {
        fprintf(ERR_OUT, "****Error semantico en lin %d: Asignacion incompatible.\n", linea);
        return -1;
      }
      if(simbolo->clase == VECTOR) {
        fprintf(ERR_OUT, "****Error semantico en lin %d: Asignacion incompatible.\n", linea);
        return -1;
      }
      if(simbolo->tipo != $3.tipo) {
        fprintf(ERR_OUT, "****Error semantico en lin %d: Asignacion incompatible.\n", linea);
        return -1;

        }
      if (UsoGlobal($1.lexema) == NULL) {
        if(simbolo->categoria == PARAMETRO) {

          escribirParametro(yyout,simbolo->valor1,num_parametros_actual);
        } else {
          escribirVariableLocal(yyout,simbolo->valor1+1);
        }
                asignarDestinoEnPila(yyout,$3.es_direccion);

      } else {
        asignar(yyout, $1.lexema, $3.es_direccion?0:1);
        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    }
  }
}

          | elemento_vector TOK_ASIGNACION exp {
            if($1.tipo != $3.tipo) {
              fprintf(ERR_OUT, "****Error semantico en lin %d: Asignacion incompatible.\n", linea);
              return -1;
            }
		
		asignar_vector(yyout, $3.es_direccion);
            fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
          ;

/*REGLA PR 48*/
elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
		 simbolo = UsoLocal($1.lexema);
	   if(simbolo == NULL) {
				 fprintf(ERR_OUT, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
				 return -1;
			}
			if(simbolo->categoria == FUNCION) { 
					fprintf(ERR_OUT,"****Error semantico en lin %d: Identificador no valido\n", linea);
					return -1;
			}
			$$.tipo = simbolo->tipo;
			$$.es_direccion = 1;

			if($3.tipo != INT) {
				 fprintf(ERR_OUT, "****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", linea);
				 return -1;
			 }
			 escribir_operando_array(yyout, $1.lexema, $3.es_direccion, simbolo->valor1);

					  fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
					               ;


/*REGLA PR 50,51*/
condicional: if_exp_sentencias TOK_LLAVEDERECHA {
		ifthenelse_fin(yyout, $1.etiqueta);
		fprintf(yyout,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
	}
	| if_exp_sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA{
		ifthenelse_fin(yyout, $1.etiqueta);
		fprintf(yyout,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
	}
;


if_exp: TOK_IF exp TOK_LLAVEIZQUIERDA {
    if($2.tipo != BOOLEAN) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Condicional con condicion de tipo int.\n", linea);
      return -1;
    }
    $$.etiqueta = contador_cond++;
    ifthen_inicio(yyout, $2.es_direccion, $$.etiqueta);
  }
	;

if_exp_sentencias:  if_exp sentencias {
	 $$.etiqueta = $1.etiqueta;
  	ifthenelse_fin_then(yyout, $$.etiqueta);

}
;


/*REGLA PR 52*/

bucle: while_exp sentencias TOK_LLAVEDERECHA {
  while_fin(yyout, $1.etiqueta);
  fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
     ;


while: TOK_WHILE {
  $$.etiqueta = contador_bucle++;
  while_inicio(yyout, $$.etiqueta);
}
;


while_exp: while exp TOK_LLAVEIZQUIERDA {
  if($2.tipo != BOOLEAN) {
    fprintf(ERR_OUT, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", linea);
    return -1;
  }
  
  $$.etiqueta = $1.etiqueta;
  while_exp_pila(yyout, $2.es_direccion, $1.etiqueta);
	
};

/*REGLA PR 54*/
lectura: TOK_SCANF TOK_IDENTIFICADOR {
    simbolo = UsoLocal($2.lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "*Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $2.lexema);
      return -1;
    }
    leer(yyout, $2.lexema, simbolo->tipo);
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
};


/*REGLA PR 56*/
escritura: TOK_PRINTF exp {
			escribir(yyout, ($2.es_direccion), ($2.tipo));
			fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
			}
;


/*REGLA PR 61*/
retorno_funcion: TOK_RETURN exp {
  if(!es_funcion) {
    fprintf(ERR_OUT, "****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una funcion.\n", linea);
    return -1;
  }

  control_retorno = 1;
  retornarFuncion(yyout, $2.es_direccion);
  fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");
	}
;

/*REGLA PR 72,73,74,75,76,77,78,79,80,81,82,83,85,88*/
exp: exp TOK_MAS exp {
  if($1.tipo!=INT || $3.tipo != INT) {
    fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  sumar(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
  $$.tipo = INT;

  fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
}

   | exp TOK_MENOS exp {
  if($1.tipo!=INT || $3.tipo != INT) {    /* no podemos restar no enteros */
    fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  $$.tipo = INT;
  restar(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
    fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
}

   | exp TOK_DIVISION exp {
  if($1.tipo!=INT || $3.tipo != INT) {
    /** ERROR **/
    fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  $$.tipo = INT;
  dividir(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
    fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
}

   | exp TOK_ASTERISCO exp {   /*MULTIPLICAR*/
  if($1.tipo!=INT || $3.tipo != INT) {
    fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  $$.tipo = INT;
  multiplicar(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
  $$.es_direccion = 0;
    fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
}

   | TOK_MENOS exp %prec MENOSU {
    if($2.tipo!=INT) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
      return -1;
    }
    $$.tipo = INT;
    cambiar_signo(yyout, $2.es_direccion?0:1);
    $$.es_direccion = 0;
    fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
}
   | exp TOK_AND exp {
    if($1.tipo!=BOOLEAN || $3.tipo != BOOLEAN) {    /*AND solo booleanos*/
      fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion logica con operandos int.\n", linea);
      return -1;
    }
    $$.tipo = BOOLEAN;
    y(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
    $$.es_direccion = 0;
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
}
   | exp TOK_OR exp {
    if($1.tipo!=BOOLEAN || $3.tipo != BOOLEAN) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion logica con operandos int.\n", linea);
      return -1;
    }
    $$.tipo = BOOLEAN;
    o(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1);
    $$.es_direccion = 0;
    fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
  }
   | TOK_NOT exp {
    if($2.tipo!=BOOLEAN) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Operacion logica con operandos int.\n", linea);
      return -1;
    }
    $$.tipo = BOOLEAN;
    contador_not++;
    no(yyout, $2.es_direccion?0:1, contador_not);
    $$.es_direccion = 0;
    fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
}
   | TOK_IDENTIFICADOR {
    strcpy($$.lexema, $1.lexema);
    simbolo = UsoLocal($1.lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", linea, $1.lexema);
      return -1;
    }
    if (UsoGlobal($1.lexema) == NULL) {
      /* Estamos en una funcion y la variable es local */
      if(simbolo->categoria == PARAMETRO) {
        escribir_elemento_funcion(yyout, (num_parametros_actual-simbolo->valor1)+1);
      } else {
        escribir_elemento_funcion(yyout, -(simbolo->valor1+1));
      }

    } else {
      if(simbolo->categoria==FUNCION) {
        
        fprintf(ERR_OUT,"Identificador no valido\n");
        return -1;
    }

    escribir_operando(yyout, $1.lexema, 1);

    }
    $$.es_direccion = 1;
    $$.tipo = simbolo->tipo;

    fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");

  }
   | constante {
    $$.tipo =$1.tipo;
    $$.es_direccion = $1.es_direccion;
    escribir_operando(yyout, $1.lexema, 0);
    fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
  }
   | TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
    $$.tipo =$2.tipo;
    $$.es_direccion = $2.es_direccion;
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
  }
   | TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {  /*comparaciones booleanas*/
    $$.tipo =BOOLEAN;
    $$.es_direccion = 0;
    fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
  }
   | elemento_vector {
    fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");

  }
   |  call_func lista_expresiones TOK_PARENTESISDERECHO {
    simbolo = UsoLocal($1.lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Funcion no declarada (%s).\n", linea, $1.lexema);
      return -1;
    }
    if(simbolo->categoria != FUNCION){
      fprintf(ERR_OUT, "****Error semantico en lin %d: El identificador no es una funcion (%s).\n", linea, $1.lexema);
      return -1;
    }
    if(simbolo->valor1 != parametros) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", linea);
      return -1;
    }
    es_llamada = 0;
    $$.tipo = simbolo->tipo;
    llamarFuncion(yyout, $1.lexema, simbolo->valor1);

    fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
   ;


call_func: TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO {
  if(es_llamada == 1) {
    fprintf(ERR_OUT, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
    return -1;
  }
  es_llamada = 1;
  parametros = 0;
  strcpy($$.lexema, $1.lexema);
}
;

/*REGLA PR 89,90*/
lista_expresiones: exp resto_lista_expresiones {
				es_llamada = 0;
				parametros++;
				fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
				}
		|  {
		es_llamada = 0;
		fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
		
		}
;

expf: exp {
  			operandoEnPilaAArgumento(yyout, $1.es_direccion);
};

/*REGLA PR 91,92*/
resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {
					parametros++;
					fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
					
					}
					|  {
						fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
						}
;


/*REGLA PR 93,94,95,96,97,98*/
comparacion: exp TOK_IGUAL exp {
	  if($1.tipo != INT || $3.tipo != INT) {
	    fprintf(ERR_OUT, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
	    return -1;
	  }
	  igual(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, contador_cmp++);

	  fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
	}
           | exp TOK_DISTINTO exp {
            if($1.tipo != INT || $3.tipo != INT) {
              fprintf(ERR_OUT, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
              return -1;
            }

            distinto(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
            }
           | exp TOK_MENORIGUAL exp {
            if($1.tipo != INT || $3.tipo != INT) {
              fprintf(ERR_OUT, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            menor_igual(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
           | exp TOK_MAYORIGUAL exp {
            if($1.tipo != INT || $3.tipo != INT) {
              fprintf(ERR_OUT, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            mayor_igual(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
           | exp TOK_MENOR exp {
            if($1.tipo != INT || $3.tipo != INT) {
              fprintf(ERR_OUT, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            menor(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");}
           | exp TOK_MAYOR exp {
            if($1.tipo != INT || $3.tipo != INT) {
              fprintf(ERR_OUT, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            mayor(yyout, $1.es_direccion?0:1, $3.es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");}
           ;




/*REGLA PR 99,100*/
constante: constante_logica {
		$$.tipo = $1.tipo;
    	$$.es_direccion = $1.es_direccion;
		strcpy($$.lexema, $1.lexema);
		fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");

		}
	| constante_entera {
		$$.tipo = $1.tipo;
    	$$.es_direccion = $1.es_direccion;
		strcpy($$.lexema, $1.lexema);
		fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
		}
;

/* REGLA PR 102,103 */
constante_logica: TOK_TRUE {
		$$.tipo = BOOLEAN;
        $$.es_direccion = 0;
		strcpy($$.lexema,"1");
		fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");

		}

		| TOK_FALSE {
			$$.tipo = BOOLEAN;
                   	$$.es_direccion = 0;
			strcpy($$.lexema,"0");
			fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");

			}
;

/* REGLA PR 104 */
constante_entera: TOK_CONSTANTE_ENTERA {

	$$.tipo = INT;
	$$.es_direccion = 0;
	/*$$.valor_entero = $1.valor_entero;*/
	fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");


	}
;

/*REGLA PR 108*/
identificador: TOK_IDENTIFICADOR {
    simbolo = UsoLocal($1.lexema);
    if((simbolo != NULL && !es_funcion) || (simbolo != NULL && EsLocal($1.lexema)) ) {
      fprintf(ERR_OUT, "****Error semantico en lin %d: Declaracion duplicada.\n", linea);
      return -1;
    }

    insertar.lexema = $1.lexema;
    insertar.categoria = VARIABLE;
    insertar.clase = clase_actual;
    insertar.tipo = tipo_actual;
    if(clase_actual == VECTOR) {
      insertar.valor1 = tamanio_vector_actual;

    } else {
      insertar.valor1 = 1;
    }
    if(es_funcion) {
      if(clase_actual == VECTOR) {
        fprintf(ERR_OUT, "****Error semantico en lin %d: Variable local de tipo no escalar.\n", linea);
        return -1;
      }
      insertar.valor1 = num_variables_locales_actual;
      num_variables_locales_actual++;
      pos_variable_local_actual++;
    } else {
      declarar_variable(yyout, $1.lexema, tipo_actual,  insertar.valor1);

    }

    Declarar($1.lexema, &insertar);


    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");}
;
             

%%

void yyerror (char *s){
	/*if(error == 0){
		fprintf(stderr,"**** Error sintáctico en [linea %d, columna %d]\n", linea, columna-yyleng);
	}

	error = 0;*/

	fprintf(stderr,"**** Error sintáctico en [linea %d, columna %d]\n", linea, columna-yyleng);
}
