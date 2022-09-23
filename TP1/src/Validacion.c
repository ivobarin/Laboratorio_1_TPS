/*
 * Validacion.c
 *
 *  Created on: 23 sept 2022
 *      Author: IvoBarin
 */

#include "Validacion.h"

int salirMenu(char* confirmaSalida)
{
    int retorno = 0;
    char salir;
    if(confirmaSalida != NULL)//validamos el puntero
    {
        do
        {
            printf("Desea Finalizar el Programa?[s/n]: ");
            fflush(stdin);
            scanf("%c", &salir);
            salir = tolower(salir); // lo transforma en minuscula para que finalize la estructura repetitiva while
        }
        while((salir != 's') && (salir != 'n'));
        *confirmaSalida = salir;
    }
    retorno = 1;
    return retorno;
}

int confirmarProcedimiento(char *pMensaje)
{
    int retorno = -1;
    char confirmar;
    do
    {
        printf(pMensaje);
        fflush(stdin);
        scanf("%c", &confirmar);
        confirmar = tolower(confirmar);
    }
    while((confirmar != 's') && (confirmar != 'n'));
    retorno = 0;

    if(confirmar == 's')
    {
        retorno = 1;
    }
    return retorno;
}

