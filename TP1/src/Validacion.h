/*
 * Validacion.h
 *
 *  Created on: 23 sept 2022
 *      Author: IvoBarin
 */

#ifndef VALIDACION_H_
#define VALIDACION_H_

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "conio.h"

/// \fn int salirMenu(char*)
/// \brief pide que se ingrese un SÍ o NO en forma de caracter 's' o 'n' y luego lo pasa a minuscula para validarlo
///
/// \param confirmaSalida es un puntero que toma la respuesta del usuario ('s' | 'n'), y la guarda en una variable
/// \return retorna -1 si la funcion se rompio y no salio del bucle, 0 si la respuesta es 'n', y 1 si la respuesta es 's'
int salirMenu(char* confirmaSalida);
int confirmarProcedimiento(char *pMensaje);

#endif /* VALIDACION_H_ */
