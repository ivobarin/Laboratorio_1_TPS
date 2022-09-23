/*
 * Operaciones.h
 *
 *  Created on: 23 sept 2022
 *      Author: IvoBarin
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "conio.h"

/// \fn int cargaDatosMantenimiento(int*, char*, char*, int, int)
/// \brief operación que carga el gasto del mantenimiento ingresado
///
/// \param pGastoIngresado puntero que acumula el gasto ingresado en una variable
/// \param mensaje toma una cadena de caracteres por valor, para motrarlo por un printf
/// \param errorMensaje toma una cadena de caracteres por valor, para motrarlo por un printf
/// \param maximo es el numero maximo que acepta la funcion para validarlo
/// \param minimo es el numero minimo que acepta la funcion para validarlo
/// \return
int cargaDatosMantenimiento(int* pGastoIngresado, char* mensaje, char *errorMensaje, int maximo, int minimo);

/// \fn int cargaCamisetas(int*, char*, char*)
/// \brief valida que un numero este entre el 0 y el 99, sino le pide que lo vuelva a ingresar
///
/// \param numeroCamisetas puntero que acumula el numero de camisetas ingresado en una variable: (se que deberia ser un numero indivual para cada camiseta, pero no me gaste en cambiarlo porque no se muestra por pantalla)
/// \param pMensaje toma una cadena de caracteres por valor, para motrarlo por un printf
/// \param pErrorMensaje toma una cadena de caracteres por valor, para motrarlo por un printf
/// \return retorna 0 si no hay ninguna variable con una direccion de memoria en el puntero, o si es igual a NULL. Sino, retorna 1
int cargaCamisetas(int* numeroCamisetas,char* pMensaje,char* pErrorMensaje);

/// \fn int contadorConfederacion(int*, int*, int*, int*, int*, int*)
/// \brief switch que usa punteros como acumuladores para no tener otro switch adentro del main (perdon la redundancia)
///
/// \param pContadorAFC puntero que cuenta cuantas veces se ingreso la confederacion AFC
/// \param pContadorCAF puntero que cuenta cuantas veces se ingreso la confederacion CAF
/// \param pContadorCONCACAF puntero que cuenta cuantas veces se ingreso la confederacion CONCACAF
/// \param pContadorCONMEBOL puntero que cuenta cuantas veces se ingreso la confederacion CONMEBOL
/// \param pContadorUEFA puntero que cuenta cuantas veces se ingreso la confederacion UEFA
/// \param pContadorOFC puntero que cuenta cuantas veces se ingreso la confederacion OFC
/// \return Retorna 1 si la validaciones fueron correctas y se ingreso a alguna confederacion. Retorna 0 si las validaciones fallaron
int contadorConfederacion(int* pContadorAFC, int* pContadorCAF, int* pContadorCONCACAF, int* pContadorCONMEBOL, int* pContadorUEFA, int* pContadorOFC);

/// \fn int promedioJugadores(int, int, int, int, int, int, int, float*, float*, float*, float*, float*, float*)
/// \brief atrapa todos los contadores de cada confederacion, y el total de jugadores para calcular el promedio de jugadores por confederacion
///
/// \param totalJugadores es la variable que almacena la suma de todos los contadores de jugadores
/// \param contadorAFC es el contador de la confederacion AFC
/// \param contadorCAF es el contador de la confederacion CAF
/// \param contadorCONCACAF es el contador de la confederacion CONCACAF
/// \param contadorCONMEBOL es el contador de la confederacion CONMEBOL
/// \param contadorUEFA es el contador de la confederacion UEFA
/// \param contadorOFC es el contador de la confederacion OFC
/// \param pPromedioAFC es el puntero que guarda el promedio de la confederacion AFC en una variable
/// \param pPromedioCAF es el puntero que guarda el promedio de la confederacion CAF en una variable
/// \param pPromedioCONCACAF es el puntero que guarda el promedio de la confederacion CONCACAF en una variable
/// \param pPromedioCONMEBOL es el puntero que guarda el promedio de la confederacion CONMEBOL en una variable
/// \param pPromedioUEFA es el puntero que guarda el promedio de la confederacion UEFA en una variable
/// \param pPromedioOFC es el puntero que guarda el promedio de la confederacion OFC en una variable
/// \return Retorna 0 si la validacion de cada puntero fue incorrecta. Retorna 1 si la validacion de cada puntero fue correcta
int promedioJugadores(int totalJugadores,int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC, float* pPromedioAFC, float* pPromedioCAF, float* pPromedioCONCACAF, float* pPromedioCONMEBOL, float* pPromedioUEFA, float* pPromedioOFC);

/// \fn int calcularMantenimientoAumento(int, int, int, int, int, int, int, int*)
/// \brief obtiene el total gastado del mantenimiento y le aplica un porcentaje de aumento del 35% si la mayoria de los jugadores pertenecen a la confederacion UEFA
///
/// \param totalMantenimiento es la variable que almacena la suma de todos los acumuladores de gastos mantenimiento
/// \param contadorUEFA es el contador de la confederacion UEFA
/// \param contadorCAF es el contador de la confederacion CAF
/// \param contadorCONCAF es el contador de la confederacion CONCACAF
/// \param contadorAFC es el contador de la confederacion AFC
/// \param contadorCONMEBOL es el contador de la confederacion CONMEBOL
/// \param contadorOFC es el contador de la confederacion OFC
/// \param aumentoMantenimiento puntero que recibe el aumento del mantenimiento total, y lo guarda en la direccion de memoria de una variable
/// \return retorna -1 y el puntero es igual a NULL. Retorna 0 si la condicción es falsa, o 1 si la condicción es verdadera
int calcularMantenimientoAumento(int totalMantenimiento, int contadorUEFA, int contadorCAF, int contadorCONCAF, int contadorAFC, int contadorCONMEBOL, int contadorOFC ,int* aumentoMantenimiento);

#endif /* OPERACIONES_H_ */
