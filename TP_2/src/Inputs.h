#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED
#include "Jugadores.h"
#include "Confederaciones.h"
#include "Menus.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1


/// \fn int confirmarProcedimiento(char*)
/// \brief funcion con el objetivo de confirmar si el usuario desea continuar con el programa
/// \param pMensaje, cadena de caracteres
/// \return retorna 1 si el usuario ingresa 'S' o 0 si recibe cualquier otro caracter
int confirmarProcedimiento(char *pMensaje);


/// \fn int salirMenu(char*)
/// \brief funcion que retorna un puntero que actua como bandera para la finalizacion del programa
///
/// \param confirmaSalida: puntero char que contiene la direccion de memoria de un caracter 's' o 'n'
/// \return retorna 0 si el programa falló o 1 si todo salio bien
int salirMenu(char* confirmaSalida);


/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud);

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
int esNumerica(char* cadena);

/**
* \brief Verifica si la cadena ingresada es no tiene un 'SPACE' en el primer elemento
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena no tiene 'SPACE' y 0 (falso) si lo tiene
*/
int esEspacio(char* cadena);

/**
* \brief Verifica si la cadena ingresada es no tiene algun simbolo
* \param *cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena no tiene simbolos y 0 (falso) si los tiene
*/
int esSimbolo(char* cadena);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
int getInt(int* pResultado);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int tomarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Solicita un string al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int tomarCadena(char cadena[],int longitud,char mensaje[], char mensajeError[], int reintentos);

/**
* \brief Verifica si la cadena ingresada es numerica y si tiene un punto '.'
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y tiene un punto 0 (falso) si no lo es
*/
int esNumericaFloat(char* cadena);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
int getFloat(float* pResultado);

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int tomarFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
#endif // INPUTS_H_INCLUDED
