/*
 * Operaciones.c
 *
 *  Created on: 23 sept 2022
 *      Author: IvoBarin
 */

#include "Operaciones.h"

int cargaDatosMantenimiento(int* pGastoIngresado, char* mensaje, char *errorMensaje, int maximo, int minimo)
{
    float valorCosto;
    int retorno=0;
    if(pGastoIngresado != NULL && mensaje != NULL && errorMensaje != NULL)
    {
        printf(mensaje);
        scanf("%f", &valorCosto);

        while(valorCosto > maximo || valorCosto < minimo)
        {
            printf(errorMensaje);
            scanf("%f", &valorCosto);
        }
        retorno = 1;
        *pGastoIngresado = valorCosto;

    }
    return retorno;
}

int cargaCamisetas(int* numeroCamisetas,char* pMensaje,char* pErrorMensaje)
{
    int retorno = 0;
    int camiseta;
    if(numeroCamisetas != NULL)
    {
        printf(pMensaje);
        scanf("%d", &camiseta);
        while(camiseta < 1 || camiseta > 99)
        {
            printf(pErrorMensaje);
            scanf("%d", &camiseta);
        }
        *numeroCamisetas = camiseta;
        retorno = 1;

    }
    return retorno;
}

int contadorConfederacion(int* pContadorAFC, int* pContadorCAF, int* pContadorCONCACAF, int* pContadorCONMEBOL, int* pContadorUEFA, int* pContadorOFC)
{
    int retorno = 0;
    int opcion;
    if(pContadorAFC != NULL && pContadorCAF != NULL && pContadorCONCACAF != NULL && pContadorCONMEBOL != NULL && pContadorOFC != NULL && pContadorUEFA != NULL)
    {
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            (*pContadorAFC)++;
            retorno = 1;
            break;
        case 2:
            (*pContadorCAF)++;
            retorno = 1;
            break;
        case 3:
            (*pContadorCONCACAF)++;
            retorno = 1;
            break;
        case 4:
            (*pContadorCONMEBOL)++;
            retorno = 1;
            break;
        case 5:
            (*pContadorUEFA)++;
            retorno = 1;
            break;
        case 6:
            (*pContadorOFC)++;
            retorno = 1;
            break;
        default:
            printf("\nError, porfavor vuelva a ingresar una confederacion valida!\n");
            break;
        }
    }
    return retorno;
}

int promedioJugadores(int totalJugadores,int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC, float* pPromedioAFC, float* pPromedioCAF, float* pPromedioCONCACAF, float* pPromedioCONMEBOL, float* pPromedioUEFA, float* pPromedioOFC)
{
    int retorno = 0;
    if(pPromedioAFC != NULL && pPromedioCAF != NULL && pPromedioCONCACAF != NULL && pPromedioCONMEBOL != NULL && pPromedioUEFA != NULL && pPromedioOFC != NULL)
    {
        *pPromedioAFC = (float) contadorAFC / totalJugadores;
        *pPromedioCAF = (float) contadorCAF / totalJugadores;
        *pPromedioCONCACAF = (float) contadorCONCACAF / totalJugadores;
        *pPromedioCONMEBOL = (float) contadorCONMEBOL / totalJugadores;
        *pPromedioUEFA = (float) contadorUEFA / totalJugadores;
        *pPromedioOFC = (float) contadorUEFA / totalJugadores;
        retorno = 1;
    }
    return retorno;
}

int calcularMantenimientoAumento(int totalMantenimiento, int contadorUEFA, int contadorCAF, int contadorCONCAF, int contadorAFC, int contadorCONMEBOL, int contadorOFC ,int* aumentoMantenimiento)
{
    int retorno = -1;
    int aumento=0;
    if(aumentoMantenimiento != NULL)
    {
    	retorno = 0;
        if((contadorUEFA > contadorCAF) && (contadorUEFA > contadorAFC) && (contadorUEFA > contadorCONCAF) && (contadorUEFA > contadorCONMEBOL) && (contadorUEFA > contadorOFC))
        {
            aumento = ((35 * totalMantenimiento) / 100);
            *(aumentoMantenimiento) = aumento;
            retorno = 1;
        }
    }
    return retorno;
}




