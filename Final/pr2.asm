;escribir_subseccion_data
segment .data
	msg_error_division db "División por cero",0
	msg_error_indice_vector db "Error en el indice del vector", 0
;escribir_cabecera_bss
segment .bss
	__esp resd 1
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
_x 	resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	y
_y 	resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	z
_z 	resd 1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>
;escribir_segmento_codigo
segment .text
	global main
	extern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string
;R21:	<funciones> ::=
;escribir_inicio_main
main:
	mov dword [__esp], esp
;D:	x
	push dword _x
	call scan_boolean
	add dword esp, 4
;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	y
	push dword _y
	call scan_boolean
	add dword esp, 4
;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	z
	push dword _z
	call scan_boolean
	add dword esp, 4
;R54:	<lectura> ::= scanf <identificador>
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	x
;D:	+
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	y
;D:	*
	push dword _y
;R80:	<exp> ::= <identificador>
;D:	z
;D:	;
	push dword _z
;R80:	<exp> ::= <identificador>
	pop dword ecx
	pop dword eax
	imul ecx
	cdq
	push dword eax
;R75:	<exp> ::= <exp> * <exp>
	pop dword edx
	pop dword eax
	mov dword edx, [edx]
	add eax, edx
	push dword eax
;R72:	<exp> ::= <exp> + <exp>
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_boolean
	call print_endofline
	add dword esp, 4
;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	(
;D:	x
;D:	+
	push dword _x
;R80:	<exp> ::= <identificador>
;D:	y
;D:	)
	push dword _y
;R80:	<exp> ::= <identificador>
	pop dword edx
	pop dword eax
	add eax, edx
	push dword eax
;R72:	<exp> ::= <exp> + <exp>
;R82:	<exp> ::= ( <exp> )
;D:	*
;D:	z
;D:	;
	push dword _z
;R80:	<exp> ::= <identificador>
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	imul ecx
	cdq
	push dword eax
;R75:	<exp> ::= <exp> * <exp>
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_boolean
	call print_endofline
	add dword esp, 4
;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	-
;D:	x
;D:	*
	push dword _x
;R80:	<exp> ::= <identificador>
	pop dword eax
	neg eax
	push dword eax
;R76:	<exp> ::= - <exp>
;D:	y
;D:	*
	push dword _y
;R80:	<exp> ::= <identificador>
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	imul ecx
	cdq
	push dword eax
;R75:	<exp> ::= <exp> * <exp>
;D:	-
;D:	z
;D:	;
	push dword _z
;R80:	<exp> ::= <identificador>
	pop dword eax
	neg eax
	push dword eax
;R76:	<exp> ::= - <exp>
	pop dword ecx
	pop dword eax
	mov dword eax, [eax]
	mov dword ecx, [ecx]
	imul ecx
	cdq
	push dword eax
;R75:	<exp> ::= <exp> * <exp>
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_boolean
	call print_endofline
	add dword esp, 4
;R56:	<escritura> ::= printf <exp>
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
;escribir_fin
	jmp near fin
fin_error_division:
	push dword msg_error_division
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin_indice_fuera_rango:
	push dword msg_error_indice_vector
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin:
	mov esp, [__esp]
	ret
