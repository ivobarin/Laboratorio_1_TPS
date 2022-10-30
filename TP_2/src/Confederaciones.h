#include "Jugadores.h"
#include "Menus.h"
#include "Inputs.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1

#ifndef CONFEDERACIONES_H_INCLUDED
#define CONFEDERACIONES_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
} eConfederacion;

int harcodearConfederacion(eConfederacion vec[], int tam);
int mostrarConfederacion(eConfederacion confederaciones[],int tam);
int buscarConfederacionId(eConfederacion vec[], int tam, int id, int* pIndice);
int cargarDescripcionConfederacion(eConfederacion vec[], int tam, int id, char descripcion[]);
int cargarDescripcionRegion(eConfederacion vec[], int tam, int id, char descripcion[]);
int copiarPosicion(char descripcion[],int idPosicion);
#endif // CONFEDERACIONES_H_INCLUDED
