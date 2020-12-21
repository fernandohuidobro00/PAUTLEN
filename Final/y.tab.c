/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "alfa.y" /* yacc.c:339  */
	
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

	int tipo_actual;
	int clase_actual;

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
	/*tablaSimbolos tabla;*/	/* Tabla de simbolos*/

#line 120 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_ARRAY = 260,
    TOK_BOOLEAN = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_LLAVEIZQUIERDA = 271,
    TOK_LLAVEDERECHA = 272,
    TOK_PARENTESISIZQUIERDO = 273,
    TOK_PARENTESISDERECHO = 274,
    TOK_CORCHETEIZQUIERDO = 275,
    TOK_CORCHETEDERECHO = 276,
    TOK_MAS = 277,
    TOK_MENOS = 278,
    TOK_DIVISION = 279,
    TOK_ASTERISCO = 280,
    TOK_AND = 281,
    TOK_OR = 282,
    TOK_ASIGNACION = 283,
    TOK_IGUAL = 284,
    TOK_NOT = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_TRUE = 291,
    TOK_FALSE = 292,
    TOK_ERROR = 293,
    TOK_CONSTANTE_ENTERA = 294,
    TOK_IDENTIFICADOR = 295,
    MENOSU = 296
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_ARRAY 260
#define TOK_BOOLEAN 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_LLAVEIZQUIERDA 271
#define TOK_LLAVEDERECHA 272
#define TOK_PARENTESISIZQUIERDO 273
#define TOK_PARENTESISDERECHO 274
#define TOK_CORCHETEIZQUIERDO 275
#define TOK_CORCHETEDERECHO 276
#define TOK_MAS 277
#define TOK_MENOS 278
#define TOK_DIVISION 279
#define TOK_ASTERISCO 280
#define TOK_AND 281
#define TOK_OR 282
#define TOK_ASIGNACION 283
#define TOK_IGUAL 284
#define TOK_NOT 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_TRUE 291
#define TOK_FALSE 292
#define TOK_ERROR 293
#define TOK_CONSTANTE_ENTERA 294
#define TOK_IDENTIFICADOR 295
#define MENOSU 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "alfa.y" /* yacc.c:355  */

	tipo_atributos atributos;

#line 246 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   144,   154,   162,   167,   173,   179,   185,
     191,   197,   202,   210,   223,   227,   235,   238,   245,   272,
     286,   344,   349,   355,   359,   366,   389,   393,   399,   403,
     409,   413,   419,   420,   421,   422,   427,   428,   432,   465,
     482,   509,   510,   539,   545,   552,   564,   582,   590,   603,
     616,   627,   639,   650,   660,   670,   681,   692,   723,   729,
     734,   740,   744,   782,   794,   797,   810,   814,   821,   832,
     841,   849,   857,   865,   888,   894,   903,   913,   924,   945
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_ARRAY",
  "TOK_BOOLEAN", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_LLAVEIZQUIERDA", "TOK_LLAVEDERECHA", "TOK_PARENTESISIZQUIERDO",
  "TOK_PARENTESISDERECHO", "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO",
  "TOK_MAS", "TOK_MENOS", "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND",
  "TOK_OR", "TOK_ASIGNACION", "TOK_IGUAL", "TOK_NOT", "TOK_DISTINTO",
  "TOK_MENORIGUAL", "TOK_MAYORIGUAL", "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE",
  "TOK_FALSE", "TOK_ERROR", "TOK_CONSTANTE_ENTERA", "TOK_IDENTIFICADOR",
  "MENOSU", "$accept", "programa", "escritura1", "escritura2",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "fn_name",
  "fn_declaration", "funcion", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "bloque", "asignacion",
  "elemento_vector", "condicional", "bucle", "while", "while_exp",
  "lectura", "escritura", "retorno_funcion", "exp", "call_func",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,    -8,    14,    29,   -35,   -35,     5,   -35,   -35,    29,
     -21,   -35,   -35,   -35,     3,    13,   -35,   -35,     8,    10,
     -12,     5,   -35,    36,    28,    13,   -35,   -21,   -35,     7,
       4,    28,     5,    41,    51,     6,    37,    37,   -16,    53,
      28,    57,   -35,   -35,    44,   -35,   -35,    37,    28,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,    58,   -21,    65,    71,
      37,   -35,   -35,    37,    37,    37,   -35,   -35,    -3,   -35,
     123,    37,   -35,   -35,   -35,   123,    37,    37,   -35,   -35,
     -35,    37,    26,    69,   -35,   -35,    72,     5,   -35,   110,
      73,    70,   -35,   -35,   -35,    37,    37,    37,    37,    37,
      37,   101,    74,   117,   123,   123,    78,   -35,    29,    71,
      94,   -35,    37,    37,    37,    37,    37,    37,   -35,    32,
      32,   -35,   -35,   -35,    32,    37,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,    28,   123,   123,   123,   123,   123,   123,
     101,    95,   -35,    81,    97,    28,   100,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    11,     0,    12,     3,     5,
       0,     8,    10,     9,     0,    17,     6,    79,     0,    14,
       0,     0,     4,     0,     0,    17,     7,     0,    78,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    31,    32,     0,    36,    37,     0,     0,    33,
      34,    35,    16,    15,    13,    18,     0,     0,     0,    24,
       0,    44,    46,     0,     0,     0,    76,    77,    57,    61,
      47,    65,    58,    74,    75,    48,     0,     0,    20,    29,
      30,     0,     0,     0,     2,    25,     0,     0,    21,     0,
       0,     0,    53,    56,    63,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    38,    39,     0,    43,    27,    24,
       0,    59,     0,     0,     0,     0,     0,     0,    60,    49,
      50,    51,    52,    54,    55,     0,    64,    62,    40,    45,
      26,    19,    23,     0,    68,    69,    70,    71,    72,    73,
      67,     0,    66,    41,     0,     0,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -35,   -35,    -7,   -35,   -35,   -35,     0,   -35,
      84,    89,   -35,   -35,   -35,   -35,     9,    33,   -35,   -30,
     -35,   -35,   -35,   -35,   -24,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,   -34,   -35,   -35,   -18,   -35,   -35,   -35,    99,
      96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    15,    31,     8,     9,    10,    11,    12,    13,
      18,    22,    23,    24,    25,    58,    88,    59,   131,    39,
      40,    41,    42,    43,    69,    45,    46,    47,    48,    49,
      50,    51,    70,    71,   102,   126,    91,    72,    73,    74,
      19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    56,    16,    75,    76,     1,    14,    44,     3,     5,
      79,     7,    77,    82,     4,    94,    44,    76,    83,    17,
      21,    30,    26,    20,    44,    27,    89,    28,    54,    90,
      92,    93,    57,     5,     6,     7,    33,   101,    34,    35,
      36,    37,   103,   104,    55,   106,    62,   105,    95,    96,
      97,    98,    99,   100,    32,    63,    97,    98,    99,    60,
      64,   119,   120,   121,   122,   123,   124,    65,    38,    61,
      78,    80,    81,    66,    67,    84,    28,    68,   134,   135,
     136,   137,   138,   139,    86,    87,   107,    57,   108,   118,
     144,   140,   111,   127,   129,    95,    96,    97,    98,    99,
     100,   130,   112,   141,   113,   114,   115,   116,   117,    44,
     133,    53,   143,   145,    52,   146,   125,   147,   132,    29,
     109,    44,   142,    95,    96,    97,    98,    99,   100,   110,
       0,     0,    95,    96,    97,    98,    99,   100,   128,    95,
      96,    97,    98,    99,   100,    95,    96,    97,    98,    99,
     100,     0,     0,    85
};

static const yytype_int16 yycheck[] =
{
      24,    31,     9,    37,    20,     3,     6,    31,    16,     4,
      40,     6,    28,    47,     0,    18,    40,    20,    48,    40,
       7,    21,    14,    20,    48,    15,    60,    39,    21,    63,
      64,    65,    32,     4,     5,     6,     8,    71,    10,    11,
      12,    13,    76,    77,    40,    19,    40,    81,    22,    23,
      24,    25,    26,    27,    18,    18,    24,    25,    26,    18,
      23,    95,    96,    97,    98,    99,   100,    30,    40,    18,
      17,    14,    28,    36,    37,    17,    39,    40,   112,   113,
     114,   115,   116,   117,    19,    14,    17,    87,    16,    19,
       9,   125,    19,    19,    16,    22,    23,    24,    25,    26,
      27,   108,    29,   133,    31,    32,    33,    34,    35,   133,
      16,    27,    17,    16,    25,   145,    15,    17,   109,    20,
      87,   145,   140,    22,    23,    24,    25,    26,    27,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    21,    22,
      23,    24,    25,    26,    27,    22,    23,    24,    25,    26,
      27,    -1,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    16,     0,     4,     5,     6,    46,    47,
      48,    49,    50,    51,    50,    44,    46,    40,    52,    82,
      20,     7,    53,    54,    55,    56,    14,    15,    39,    81,
      50,    45,    18,     8,    10,    11,    12,    13,    40,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    53,    52,    21,    40,    61,    50,    57,    59,
      18,    18,    40,    18,    23,    30,    36,    37,    40,    66,
      74,    75,    79,    80,    81,    74,    20,    28,    17,    61,
      14,    28,    74,    61,    17,    82,    19,    14,    58,    74,
      74,    78,    74,    74,    18,    22,    23,    24,    25,    26,
      27,    74,    76,    74,    74,    74,    19,    17,    16,    59,
      19,    19,    29,    31,    32,    33,    34,    35,    19,    74,
      74,    74,    74,    74,    74,    15,    77,    19,    21,    16,
      46,    60,    58,    16,    74,    74,    74,    74,    74,    74,
      74,    61,    77,    17,     9,    16,    61,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    46,    47,    48,    48,
      49,    50,    50,    51,    52,    52,    53,    53,    54,    55,
      56,    57,    57,    58,    58,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    67,    67,    68,    69,    70,    71,    72,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     5,     1,     3,     2,     0,     3,     6,
       3,     2,     0,     3,     0,     2,     1,     0,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     7,    11,     3,     2,     4,     2,     2,     2,     3,
       3,     3,     3,     2,     3,     3,     2,     1,     1,     3,
       3,     1,     3,     2,     2,     0,     3,     0,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 137 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
				fprintf( yyout, ";escribir_fin\n" );
       				escribir_fin( yyout );
				}
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 144 "alfa.y" /* yacc.c:1646  */
    {
              fprintf( yyout, ";escribir_segmento_codigo\n" );
              escribir_segmento_codigo( yyout );

						fprintf( yyout, ";escribir_subseccion_data\n" );
						escribir_subseccion_data( yyout );
						fprintf( yyout, ";escribir_cabecera_bss\n" );
						escribir_cabecera_bss( yyout );
						}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 154 "alfa.y" /* yacc.c:1646  */
    {
	      fprintf( yyout, ";escribir_inicio_main\n" );
              escribir_inicio_main( yyout );
}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 162 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");
			}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 167 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
		}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
					}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 179 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");
			clase_actual = ESCALAR;
			}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 185 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");
			clase_actual = VECTOR;
			}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 191 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");
			}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 197 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R10:\t<tipo> ::= int\n");
				tipo_actual = VECTOR;
				}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 202 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");
					tipo_actual = BOOLEANO;
					}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 210 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");

					/*$4 tiene el tamaño del vector. Comprobaciones semanticas*/  /*diapositiva 31*/
					tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
  					if(tamanio_vector_actual<1 || tamanio_vector_actual > MAX_TAMANIO_VECTOR) {
    					fprintf(ERR_OUT, "****Error semantico en lin %ld: El tamanio del vector incorrecto.\n", linea);
    					return -1;
  				}
				}
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 223 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");
					}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 227 "alfa.y" /* yacc.c:1646  */
    {
						fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
					}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 235 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
					}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 238 "alfa.y" /* yacc.c:1646  */
    {
						fprintf(yyout, ";R21:\t<funciones> ::=\n");
						}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 245 "alfa.y" /* yacc.c:1646  */
    {
    control_retorno = 0;
    es_funcion=1;
    simbolo = UsoLocal((yyvsp[0].atributos).lexema);
    if(simbolo != NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Declaracion duplicada.\n", linea);
      return -1;
    }

    insertar.lexema = (yyvsp[0].atributos).lexema;
    insertar.categoria = FUNCION;
    insertar.clase = ESCALAR;
    insertar.tipo = tipo_actual;

    strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    (yyval.atributos).tipo = tipo_actual;

    DeclararFuncion((yyvsp[0].atributos).lexema, &insertar);
    num_variables_locales_actual=0;
    pos_variable_local_actual=1;   /*cambiar a 0 alomejor*/
    num_parametros_actual = 0;
    pos_parametro_actual = 0;
    control_retorno=0;
}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 272 "alfa.y" /* yacc.c:1646  */
    {
  /* Actualizar atributo num_parametros */
    simbolo = UsoLocal((yyvsp[-5].atributos).lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Declaracion duplicada.\n", linea);
      return -1;
    }
    simbolo->valor1 = num_parametros_actual;
    strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
    (yyval.atributos).tipo = (yyvsp[-5].atributos).tipo;
    declararFuncion(yyout, (yyvsp[-5].atributos).lexema, num_variables_locales_actual);
}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 286 "alfa.y" /* yacc.c:1646  */
    {
  if(control_retorno==0) {
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Funcion %s sin sentencia de retorno.\n", linea, (yyvsp[-2].atributos).lexema);
    return -1;
  }
  CerrarFuncion();
	fprintf(yyout, "mov eax, 0\n");
	fprintf(yyout, "mov esp, ebp\n"); 
	fprintf(yyout, "pop ebp\n");
	fprintf(yyout, "ret\n");
  simbolo = UsoLocal((yyvsp[-2].atributos).lexema);
  if(simbolo == NULL) {
      /* TODO */
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Declaracion duplicada.\n", linea);
      return -1;
  }
  simbolo->valor1 = num_parametros_actual;
  es_funcion = 0;
  fprintf(yyout, ";R22:\t<funcion> ::=function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 344 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
				}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 349 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R24:\t<parametros_funcion> :=\n");
			}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 355 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
				}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 359 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");
				}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 366 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
			num_parametros_actual++;
  		pos_parametro_actual++;
			}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 389 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
				}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 393 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");
			}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 399 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");
				}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 403 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
				}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 409 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
				}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");
				}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 419 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 420 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 421 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 422 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 427 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 428 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 432 "alfa.y" /* yacc.c:1646  */
    {
    simbolo = UsoLocal((yyvsp[-2].atributos).lexema);
    if(simbolo==NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", linea, (yyvsp[-2].atributos).lexema);
      return -1;
    } else {
      if(simbolo->categoria == FUNCION) {
        fprintf(ERR_OUT, "****Error semantico en lin %ld: Asignacion incompatible.\n", linea);
        return -1;
      }
      if(simbolo->clase == VECTOR) {
        fprintf(ERR_OUT, "****Error semantico en lin %ld: Asignacion incompatible.\n", linea);
        return -1;
      }
      if(simbolo->tipo != (yyvsp[0].atributos).tipo) {
        fprintf(ERR_OUT, "****Error semantico en lin %ld: Asignacion incompatible.\n", linea);
        return -1;

        }
      if (UsoGlobal((yyvsp[-2].atributos).lexema) == NULL) {
        if(simbolo->categoria == PARAMETRO) {
          asignar_local(yyout, (num_parametros_actual-simbolo->valor1+1), (yyvsp[0].atributos).es_direccion?0:1);
        } else {
          asignar_local(yyout, -(simbolo->valor1+1), (yyvsp[0].atributos).es_direccion?0:1);
        }

      } else {
        asignar(yyout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion?0:1);
        fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    }
  }
}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 465 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo) {
              fprintf(ERR_OUT, "****Error semantico en lin %ld: Asignacion incompatible.\n", linea);
              return -1;
            }
		fprintf(yyout, "pop dword eax\n");
		if ((yyvsp[0].atributos).es_direccion==0) {
			fprintf(yyout, "mov eax, [eax]\n");
		}

		fprintf(yyout, "pop dword edx\n");

		fprintf(yyout, "mov [edx], eax\n");
            fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 482 "alfa.y" /* yacc.c:1646  */
    {
		 simbolo = UsoLocal((yyvsp[-3].atributos).lexema);
	   if(simbolo == NULL) {
				 fprintf(ERR_OUT, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", linea, (yyvsp[-3].atributos).lexema);
				 return -1;
			}
			if(simbolo->categoria == FUNCION) { /***REVISAR*/
					fprintf(ERR_OUT,"****Error semantico en lin %ld: Identificador no valido\n", linea);
					return -1;
			}
			if(simbolo->clase == ESCALAR) {
				  fprintf(ERR_OUT, "****Error semantico en lin %ld: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
					 return -1;
			}
			(yyval.atributos).tipo = simbolo->tipo;
			(yyval.atributos).es_direccion = 1;
			if((yyvsp[-1].atributos).tipo != ENTERO) {
				 fprintf(ERR_OUT, "****Error semantico en lin %ld: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", linea);
				 return -1;
			 }
			 escribir_elemento_vector(yyout, (yyvsp[-3].atributos).lexema, (yyvsp[-1].atributos).es_direccion, simbolo->valor1);

					  fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 509 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 510 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 539 "alfa.y" /* yacc.c:1646  */
    {
  while_fin(yyout, (yyvsp[-2].atributos).etiqueta);
  fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 545 "alfa.y" /* yacc.c:1646  */
    {
  (yyval.atributos).etiqueta = contador_bucle++;
  while_inicio(yyout, (yyval.atributos).etiqueta);
}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 552 "alfa.y" /* yacc.c:1646  */
    {
  if((yyvsp[-2].atributos).tipo != BOOLEANO) {
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Bucle con condicion de tipo int.\n", linea);
    return -1;
  }
  
  (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
  while_exp_pila(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[-3].atributos).etiqueta);
	
}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 564 "alfa.y" /* yacc.c:1646  */
    {
    simbolo = UsoLocal((yyvsp[0].atributos).lexema);   /*cambiar $2.lexema por $2.lexema */
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "*Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", linea, (yyvsp[0].atributos).lexema);
      return -1;
    }
    fprintf(ERR_OUT,"%s",simbolo->lexema);
    leer(yyout, (yyvsp[0].atributos).lexema, simbolo->tipo);
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");
}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 582 "alfa.y" /* yacc.c:1646  */
    {
			escribir(yyout, !((yyvsp[0].atributos).es_direccion), ((yyvsp[0].atributos).tipo));
			fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");
			}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 590 "alfa.y" /* yacc.c:1646  */
    {
  if(es_funcion==0) {
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Sentencia de retorno fuera del cuerpo de una funcion.\n", linea);
    return -1;
  }

  control_retorno = 1;
  retornarFuncion(yyout, (yyvsp[0].atributos).es_direccion);
  fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");
	}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 603 "alfa.y" /* yacc.c:1646  */
    {
  if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
    printf("%d",(yyvsp[-2].atributos).tipo);
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  sumar(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1);
  (yyval.atributos).es_direccion = 0;
  (yyval.atributos).tipo = ENTERO;

  fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 616 "alfa.y" /* yacc.c:1646  */
    {
  if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {    /* no podemos restar no enteros */
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  (yyval.atributos).tipo = ENTERO;
  restar(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1);
  (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 627 "alfa.y" /* yacc.c:1646  */
    {
  if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
    /** ERROR **/
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  (yyval.atributos).tipo = ENTERO;
  dividir(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1);
  (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 639 "alfa.y" /* yacc.c:1646  */
    {   /*MULTIPLICAR*/
  if((yyvsp[-2].atributos).tipo!=ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
    fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", linea);
    return -1;
  }
  (yyval.atributos).tipo = ENTERO;
  multiplicar(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1);
  (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 650 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[0].atributos).tipo!=ENTERO) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion aritmetica con operandos boolean.\n", linea);
      return -1;
    }
    (yyval.atributos).tipo = ENTERO;
    cambiar_signo(yyout, (yyvsp[0].atributos).es_direccion?0:1);
    (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 660 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].atributos).tipo!=BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO) {    /*AND solo booleanos*/
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion logica con operandos int.\n", linea);
      return -1;
    }
    (yyval.atributos).tipo = BOOLEANO;
    y(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1);
    (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 670 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].atributos).tipo!=BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion logica con operandos int.\n", linea);
      return -1;
    }
    (yyval.atributos).tipo = BOOLEANO;
    o(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1);
    (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
  }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 681 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[0].atributos).tipo!=BOOLEANO) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Operacion logica con operandos int.\n", linea);
      return -1;
    }
    (yyval.atributos).tipo = BOOLEANO;
    contador_not++;
    no(yyout, (yyvsp[0].atributos).es_direccion?0:1, contador_not);
    (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 692 "alfa.y" /* yacc.c:1646  */
    {
    strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    simbolo = UsoLocal((yyvsp[0].atributos).lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Acceso a variable no declarada (%s).\n", linea, (yyvsp[0].atributos).lexema);
      return -1;
    }
    if (UsoGlobal((yyvsp[0].atributos).lexema) == NULL) {
      /* Estamos en una funcion y la variable es local */
      if(simbolo->categoria == PARAMETRO) {
        escribir_elemento_funcion(yyout, (num_parametros_actual-simbolo->valor1)+1);
      } else {
        escribir_elemento_funcion(yyout, -(simbolo->valor1+1));
      }

    } else {
      if(simbolo->categoria==FUNCION) {
        /* NUNCA SUCEDE */
        fprintf(ERR_OUT,"Identificador no valido\n");
        return -1;
    }

    escribir_operando(yyout, (yyvsp[0].atributos).lexema, 1);

    }
    (yyval.atributos).es_direccion = 1;
    (yyval.atributos).tipo = simbolo->tipo;

    fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");

  }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 723 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).tipo =(yyvsp[0].atributos).tipo;
    (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
    escribir_operando(yyout, (yyvsp[0].atributos).lexema, 0);
    fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
  }
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 729 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).tipo =(yyvsp[-1].atributos).tipo;
    (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
  }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 734 "alfa.y" /* yacc.c:1646  */
    {  /*comparaciones booleanas*/
    (yyval.atributos).tipo =BOOLEANO;
    (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
    fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
  }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 740 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");

  }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 744 "alfa.y" /* yacc.c:1646  */
    {
    simbolo = UsoLocal((yyvsp[-2].atributos).lexema);
    if(simbolo == NULL) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Funcion no declarada (%s).\n", linea, (yyvsp[-2].atributos).lexema);
      return -1;
    }
    if(simbolo->categoria != FUNCION){
      fprintf(ERR_OUT, "****Error semantico en lin %ld: El identificador no es una funcion (%s).\n", linea, (yyvsp[-2].atributos).lexema);
      return -1;
    }
    if(simbolo->valor1 != parametros) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Numero incorrecto de parametros en llamada a funcion.\n", linea);
      return -1;
    }
    es_llamada = 0;
    (yyval.atributos).tipo = simbolo->tipo;
    llamarFuncion(yyout, (yyvsp[-2].atributos).lexema, simbolo->valor1);

    fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 782 "alfa.y" /* yacc.c:1646  */
    {
  if(es_llamada == 1) {
    fprintf(ERR_OUT, "****Error semantico en lin %ld: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
    return -1;
  }
  es_llamada = 1;
  parametros = 0;
  strcpy((yyval.atributos).lexema, (yyvsp[-1].atributos).lexema);
}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 794 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
				}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 797 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");
		es_llamada = 0;
		}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 810 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
					parametros++;
					}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 814 "alfa.y" /* yacc.c:1646  */
    {
						fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n");
						}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 821 "alfa.y" /* yacc.c:1646  */
    {
	  if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
	    fprintf(ERR_OUT, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", linea);
	    return -1;
	  }
          contador_cmp++;
	  igual(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1, contador_cmp++);
	  /*$$.tipo = BOOLEANO;
	  $$.es_direccion = 0;*/
	  fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
	}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 832 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
              fprintf(ERR_OUT, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
	    contador_cmp++;
            distinto(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
            }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 841 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
              fprintf(ERR_OUT, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            contador_cmp++;
            menor_igual(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 849 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
              fprintf(ERR_OUT, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
	    contador_cmp++;
            mayor_igual(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 857 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
              fprintf(ERR_OUT, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            contador_cmp++;
            menor(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 865 "alfa.y" /* yacc.c:1646  */
    {
            if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO) {
              fprintf(ERR_OUT, "****Error semantico en lin %ld: Comparacion con operandos boolean.\n", linea);
              return -1;
            }
            contador_cmp++;
            mayor(yyout, (yyvsp[-2].atributos).es_direccion?0:1, (yyvsp[0].atributos).es_direccion?0:1, contador_cmp++);
            fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 888 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");
		(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    		(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
		strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
		}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 894 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
		(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    		(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
		strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
		}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 903 "alfa.y" /* yacc.c:1646  */
    {
		fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");
		(yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
		strcpy((yyval.atributos).lexema,"1");

		fprintf(yyout, ";escribir_operando\n");
                escribir_operando( yyout, "1" , 0 );
		}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 913 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");
			(yyval.atributos).tipo = BOOLEANO;
                   	(yyval.atributos).es_direccion = 0;
			strcpy((yyval.atributos).lexema,"0");
			fprintf(yyout, ";escribir_operando\n");
                    	escribir_operando(yyout, "0" , 0 );
			}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 924 "alfa.y" /* yacc.c:1646  */
    {

	fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");

	(yyval.atributos).tipo = INT;
	(yyval.atributos).es_direccion = 0;
	(yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;

		/* escribe código con tu librería para meter en la pila la constante
			  push dword $1.valor_entero
		  */

			sprintf(cte_entera, "%d", (yyval.atributos).valor_entero );
					fprintf(yyout, ";escribir_operando\n");
                    escribir_operando(yyout, cte_entera , 0 );


	}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 945 "alfa.y" /* yacc.c:1646  */
    {
    simbolo = UsoLocal((yyvsp[0].atributos).lexema);
    if((simbolo != NULL && !es_funcion) || (simbolo != NULL && EsLocal((yyvsp[0].atributos).lexema)) ) {
      fprintf(ERR_OUT, "****Error semantico en lin %ld: Declaracion duplicada.\n", linea);
      return -1;
    }

    insertar.lexema = (yyvsp[0].atributos).lexema;
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
        fprintf(ERR_OUT, "****Error semantico en lin %ld: Variable local de tipo no escalar.\n", linea);
        return -1;
      }
      insertar.valor1 = num_variables_locales_actual;
      num_variables_locales_actual++;
      pos_variable_local_actual++;
    } else {
      declarar_variable(yyout, (yyvsp[0].atributos).lexema, tipo_actual,  insertar.valor1);

    }
    Declarar((yyvsp[0].atributos).lexema, &insertar);


    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2428 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 985 "alfa.y" /* yacc.c:1906  */


void yyerror (char *s){
	if(error == 0){
		fprintf(stderr,"**** Error sintáctico en [linea %d, columna %d]\n", linea, columna-yyleng);
	}

	error = 0;
}
