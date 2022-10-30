#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED
#include "Jugadores.h"
#include "Confederaciones.h"
#include "Menus.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1

int confirmarProcedimiento(char *pMensaje);
int salirMenu(char* confirmaSalida);
int myGets(char* cadena, int longitud);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int tomarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int ingresarOpcion(int* pResultado, char* mensaje);
int tomarCadena(char cadena[],int longitud,char mensaje[], char mensajeError[], int reintentos);
int esNumericaFloat(char* cadena);
int getFloat(float* pResultado);
int tomarFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
#endif // INPUTS_H_INCLUDED
