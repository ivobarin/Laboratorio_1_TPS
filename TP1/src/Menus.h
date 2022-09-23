/*
 * Menus.h
 *
 *  Created on: 23 sept 2022
 *      Author: IvoBarin
 */

#ifndef MENUS_H_
#define MENUS_H_

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "conio.h"
/// \fn char menuPrincipal(int, int, int, int, int, int, int)
/// \brief muestra el menu principal con los acumuladores y contadores por parametro y agarra un caracter para no romper el codigo
///
/// \param hospedaje es acumulador del gasto en hospedajes
/// \param comida es el acumulador del gasto en comida
/// \param transporte es el acumulador del gasto en transporte
/// \param arqueros es el contador de la cantidad de arqueros ingresados
/// \param defensores es el contador de la cantidad de defensores ingresados
/// \param mediocampistas es el contador de la cantidad de mediocampistas ingresados
/// \param delanteros es el contador de la cantidad de delanteros ingresados
/// \return retorna la opcion en tipo de dato char para que la tome el switch del main
char menuPrincipal(int hospedaje, int comida, int transporte, int arqueros, int defensores, int mediocampistas, int delanteros);

/// \fn char menuMantenimiento()
/// \brief muestra el menu de opciones cuando se ingrasa el case 1 en el main
///
/// \return retorna la opcion en tipo de dato char para que la tome el switch del main
char menuMantenimiento();

/// \fn void pausarPantalla()
/// \brief pausar pantalla fue una función creada con el propósito de reemplazar system("pause") en el la
///	consola integrada de eclipse, sin embargo, parece que consola integrada de eclipse tampoco toma las funciones
/// de la bibloteca "conio.h". Por lo cual, decidí comentarla a lo largo del codigo
///
void pausarPantalla();

/// \fn char menuJugadores()
/// \brief muestra el menu de opciones cuando se ingrasa el case 2 en el main
///
/// \return retorna la opcion en tipo de dato char para que la tome el switch del main
char menuJugadores();

/// \fn void mostrarResultados(float, float, float, float, float, float)
/// \brief muestra el resultado de los promedios de cada confederación
///
/// \param pPromedioUEFA es el promedio de la confederación UEFA
/// \param pPromedioCONMEBOL es el promedio de la confederación CONMEBOL
/// \param pPromedioCONCACAF es el promedio de la confederación CONCACAF
/// \param pPromedioAFC es el promedio de la confederación AFC
/// \param pPromedioOFC es el promedio de la confederación OFC
/// \param pPromedioCAF es el promedio de la confederación UEFA
void mostrarResultados(float pPromedioUEFA,float pPromedioCONMEBOL, float pPromedioCONCACAF, float pPromedioAFC, float pPromedioOFC, float pPromedioCAF);

/// \fn void menuConfederacion()
/// \brief muestra el menu de opciones de todas las confederaciones
///
void menuConfederacion();

#endif /* MENUS_H_ */
