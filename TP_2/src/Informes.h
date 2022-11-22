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
/// \fn int ordenarJugadorAsc(eJugador[], int, eConfederacion[], int)
/// \brief ordena a los jugadores por nombre de confederacion en condicion ascendente
///
/// \param vec
/// \param tam
/// \param confederaciones
/// \param cantConfederacion
/// \return retorna a los jugadores ya ordenados
int ordenarJugadorAsc(eJugador vec[], int tam, eConfederacion confederaciones[], int cantConfederacion);

/// \fn int informarJugadorConfederacion(eJugador[], int, eConfederacion[], int)
/// \brief informa a que confederacion pertenecen los jugadores
///
/// \param vec
/// \param tam
/// \param confederaciones
/// \param tamConfederacion
/// \return
int informarJugadorConfederacion(eJugador vec[], int tam,eConfederacion confederaciones[], int tamConfederacion);

/// \fn int informarTotalPromedio(eJugador[], int)
/// \brief informa el salario y el promedio total de todos los jugadores
///
/// \param vec
/// \param tam
/// \return
int informarTotalPromedio(eJugador vec[], int tam);

/// \fn int informarRegionMasJugadores(eJugador[], int, int*)
/// \brief  informa el nombre de la confederacion que tiene mas contratos y la region que tiene mas jugadores
///
/// \param vec
/// \param cantJugador
/// \param pRegion
/// \return
int calcularConfederacionRegion(eJugador vec[], int tam, int* pConfederacion, int* pRegion);

/// \fn int listarPorRegion(eJugador[], eConfederacion[], int, int, int)
/// \brief
///
/// \param jugadores
/// \param confederaciones
/// \param tam
/// \param cantConfederacion
/// \param idRegion
/// \return
int listarPorRegion(eJugador jugadores[], eConfederacion confederaciones[], int tam, int cantConfederacion, int idRegion);

/// \fn int informarOpciones(eJugador[], int, eConfederacion[], int)
/// \brief  almacena a todas las funciones de informes en una sola
///
/// \param vec
/// \param cantJugador
/// \param confederaciones
/// \param cantConfederacion
/// \return
int informarOpciones(eJugador vec[], int cantJugador, eConfederacion confederaciones[], int cantConfederacion);
int informarPorcentaje(float PorcentajeCAF, float PorcentajeAFC, float PorcentajeUEFA, float PorcentajeCONMEBOL, float PorcentajeCONCACAF, float PorcentajeOFC);
int calcularConfederacionRegion(eJugador vec[], int tam, int* pConfederacion, int* pRegion);
#endif // INFORMES_H_INCLUDED
