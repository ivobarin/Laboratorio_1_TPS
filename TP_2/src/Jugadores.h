#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include "Confederaciones.h"
#include "Menus.h"
#include "Inputs.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[50];
    char posicion[50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
} eJugador;


/** \brief deja ingresar los datos (validados) de un jugador,(a los campos de struct eJugador), al usuario
 *
 * \param  vec[], vector eJugador
 * \param tam, tamaño del de vector
 * \param *id, es un puntero a la id autoincremencial (para que no se reinice cuando finaliza la funcion)
 * \return retorna 1 si los datos son ingresados con exito, o 0 si no se encontro ningun espacio libre
 */
int altaJugadores(eJugador jugadores[], int cantJugador, int* pId);

/** \brief es una funcion auxiliar con todas las validaciones y el ingreso de datos para la alta de jugadores
 */
eJugador cargaDatosJugador();

/** \brief Funcion que recorre el array del campo estado y el asigna LIBRE (0)
*
* \param  vec[]: vector del tipo de dato eJugador
* \param int tam: Tamaño del vector
* \return retorna 1 cuando el estado del vector esta vacio, o 0 si los paramentros son = NULL
*/
int inicializarJugadores(eJugador vec[], int tam);

/// \fn short BuscarJugadorLibre(eJugador[], int)
/// \brief recorre el array si se fija si hay algun elemento vacio
///
/// \param vec array eJugador
/// \param tam cantidad de elementos
/// \return retorna el indice libre, sino -1
short buscarJugadorLibre(eJugador jugadores[], int cantJugador);

/// \fn int listarJugadores(eJugador[], int, eConfederacion[], int)
/// \brief lista los jugadores ingresados
///
/// \param jugadores
/// \param tam
/// \param confederaciones
/// \param cantConfederacion
/// \return retorna 1 cuando finaliza
int listarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion);

/// \fn int buscarJugadorOcupado(eJugador[], int, int, int*)
/// \brief devuelve el indice de un jugador ocupado en memoria
///
/// \param vec
/// \param tam
/// \param id
/// \param pIndice
/// \return retorna -1 si estan todos vacios, sino retorna el indice
int buscarJugadorOcupado(eJugador vec[], int tam, int id, int* pIndice);

/// \fn int mostrarUnJugador(eJugador, eConfederacion[], int)
/// \brief muestra los datos de un solo jugador
///
/// \param jugador
/// \param confederaciones
/// \param cantConfederacion
/// \return retorna 1 cuando finaliza
int mostrarUnJugador(eJugador jugador, eConfederacion confederaciones[],int cantConfederacion);

/** \brief realiza la baja de jugadores, ingresando el id del jugador que se quiera eliminar, y modificando su estado a LIBRE (0)
 *
 * \param jugadores[], vector
 * \param tam, tamaño del de vector
 * \param confederaciones[], (utiliza el campo descripcion)
 * \param cantConfederacion, tamaño del de vector
 * \return retorna el -1 si el indice de mostrar jugador no existe, 0 si se cancela la baja, 1 si la baja es realizada con exito
 */
int bajaJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion);
int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion);
#endif // JUGADORES_H_INCLUDED
