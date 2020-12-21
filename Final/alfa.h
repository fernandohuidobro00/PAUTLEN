#ifndef ALFA_H
#define ALFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaHash.h"
#include "tablaSimbolos.h"
#include "generacion.h"
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64
#define ERR_OUT stdout

typedef enum {
  FALSE = 0,
  TRUE = 1
} BOOL;

typedef struct {
  char lexema[MAX_LONG_ID+1];
  int tipo;
  int valor_entero;
  BOOL valor_boolean;
  int es_direccion;
  int etiqueta;
} tipo_atributos;

/*
typedef struct {
  char lexema[MAX_LONG_ID+1];
  int tipo;
  int valor_entero;
  BOOL valor_boolean;
  int es_direccion;
  int etiqueta;
} tipo_atributos;
*/


/* CLASES */
#define ESCALAR 1
#define PARAMETRO 2
#define VECTOR 3

/* TIPOS */
#define INT 1
#define BOOLEAN 2




#endif
