#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "Jugadores.h"
#include "Confederaciones.h"
#include "Menus.h"
#include "Inputs.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1

int ordenarJugadorAsc(eJugador vec[], int tam, eConfederacion confederaciones[], int cantConfederacion);
int informarJugadorConfederacion(eJugador vec[], int tam,eConfederacion confederaciones[], int tamConfederacion);
int informarTotalPromedio(eJugador vec[], int tam);
int confederacionMasContratos(eJugador vec[], int tam, int* pConfederacion);
int informarRegionMasJugadores(eJugador vec[], int cantJugador, int* pRegion);
int informarOpciones(eJugador vec[], int cantJugador, eConfederacion confederaciones[], int cantConfederacion);
#endif // INFORMES_H_INCLUDED
