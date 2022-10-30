#include "Inputs.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int confirmarProcedimiento(char *pMensaje)
{
    int retorno = 0;
    char confirmar;
    do
    {
        printf(pMensaje);
        fflush(stdin);
        scanf("%s", &confirmar);
        confirmar = tolower(confirmar);
    }
    while((confirmar != 's') && (confirmar != 'n'));

    if(confirmar == 's')
    {
        retorno = 1;
    }
    return retorno;
}


int salirMenu(char* confirmaSalida)
{
    int retorno = 0;
    char salir;
    if(confirmaSalida != NULL)//validamos en puntero
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

int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int tomarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int ingresarOpcion(int* pResultado, char* mensaje)
{
    int bufferInt;
    int retorno = 0;

    printf("%s",mensaje);
    if(getInt(&bufferInt) == 0)
    {
        *pResultado = bufferInt;
        retorno = 1;
    }
    return retorno;
}

int tomarCadena(char cadena[],int longitud,char mensaje[], char mensajeError[], int reintentos)
{
    int retorno=-1;
    char buffer[4090];
    int largoBuffer;

    do
    {
        reintentos--;
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%[^\n]",buffer);
        if(!(esNumerica(buffer)) && (int)strlen(buffer) > 0)
        {
            largoBuffer = (int)strlen(buffer);//casteamos el strlen para que tome la cantidad del largo del buffer.

            if(longitud > largoBuffer)
            {
                strcpy(cadena,buffer);
                retorno = 1;
                break;
            }
        }
        printf("%s", mensajeError);
    }
    while(reintentos > 0);

    return retorno;
}

int esNumericaFloat(char* cadena)
{
    int retorno;
    int contadorPunto = 0;
    int i=0;

    if (cadena != NULL && strlen (cadena) > 0)
    {
        retorno = 1;
        while(cadena[i] != '\0')
        {

            if (cadena[i] == '/' || cadena[i] < '.' || cadena[i] > '9' || contadorPunto > 1)
            {
                retorno = -1;
                break ;
            }
            if(cadena[i] == '.')
            {
                contadorPunto++;
            }
            i++;
        }
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumericaFloat(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;
}

int tomarFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    float bufferFloat;
    int retorno = -1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
