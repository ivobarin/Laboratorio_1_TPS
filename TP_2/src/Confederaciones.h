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


/// \fn int harcodearConfederacion(eConfederacion[], int)
/// \brief harcodea los campos de la estructura con datos validos
///
/// \param vec el vector eConfederacion que va a ser harcodeado
/// \param tam el tamaño del vector
/// \return retorna 1 si todo salio bien
int harcodearConfederacion(eConfederacion vec[], int tam);

/// \fn int mostrarConfederacion(eConfederacion[], int)
/// \brief muestra los datos de todos los campos de la estructura eConfederacion
///
/// \param confederaciones, array de la struct
/// \param tam, cantidad de elementos del array
/// \return retorna 1 despues de mostrar los elementos
int mostrarConfederacion(eConfederacion confederaciones[],int tam);

/// \fn int buscarConfederacionId(eConfederacion[], int, int, int*)
/// \brief busca el id que se le pasa por param y retorna el indice
///
/// \param vec el array con las confederaciones
/// \param tam la cantidad de elementos del array
/// \param id es el ID de que se desea encontrar
/// \param pIndice puntero que guarda el indice que tiene el ID
/// \return retorna -1 si no es encuentra el ID, sino retorna el elemento que lo tenga
int buscarConfederacionId(eConfederacion vec[], int tam, int id, int* pIndice);

/// \fn int cargarDescripcionConfederacion(eConfederacion[], int, int, char[])
/// \brief guarda el nombre del la confederacion en un string para mostrarlo por pantalla
///
/// \param vec array eConfederacion
/// \param tam cantidad de elementos del array
/// \param id el id del elemento que se desea guardar el nombre
/// \param descripcion el puntero char que guarda el nombre de la confederacion
/// \return retorna 1 si se guardo el nombre, sino 0
int cargarDescripcionConfederacion(eConfederacion vec[], int tam, int id, char descripcion[]);

/// \fn int cargarDescripcionRegion(eConfederacion[], int, int, char[])
/// \brief guarda la descripcion de la region de la confederacion en un string para mostrarlo por pantalla
///
/// \param vec array eConfederacion
/// \param tam cantidad de elementos del array
/// \param id el id del elemento que se desea guardar
/// \param descripcion el puntero char que guarda la region de la confederacion
/// \return retorna 1 si se guardo la region, sino 0
int cargarDescripcionRegion(eConfederacion vec[], int tam, int id, char descripcion[]);

/// \fn int copiarPosicion(char[], int)
/// \brief guarda la la descripcion de la posicion del elemento
///
/// \param descripcion string
/// \param idPosicion el id que se desea guardar
/// \return retorna 1 cuando finaliza la funcion
int copiarPosicion(char descripcion[],int idPosicion);
#endif // CONFEDERACIONES_H_INCLUDED
