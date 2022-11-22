#include "Confederaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int harcodearConfederacion(eConfederacion vec[], int tam)
{
    int retorno = 0;
    if(vec != NULL && tam > 0)
    {
        eConfederacion harcodeo[]=
        {
            {100,"CONMEBOL","Sudamerica",1916},
            {101,"UEFA", "Europa",1954},
            {102,"AFC","Asia",1954},
            {103,"CAF","Africa",1957},
            {104,"CONCACAF","Norte y Centro America",1961},
            {105,"OFC","Oceania",1966},
        };

        for(int i=0; i < tam; i++)
        {
            vec[i] = harcodeo[i];
        }

        retorno = 1;
    }
    return retorno;
}

int mostrarConfederacion(eConfederacion confederaciones[],int tam)
{
    int retorno = 0;
    if(confederaciones != NULL && tam > 0)
    {
        printf("\n _______________________________________________________\n"
               "|%-5s|%-15s|%-25s|%-7s|\n"
               "|=====|===============|=========================|=======|\n","ID","Nombre","Region","Fecha");
        for(int x=0; x<tam; x++)
        {
            printf("|%-5d|%-15s|%-25s|%-5d\t|\n",confederaciones[x].id,confederaciones[x].nombre,confederaciones[x].region,confederaciones[x].anioCreacion);
        }
        printf("|_____|_______________|_________________________|_______|\n");
        retorno = 1;
    }
    return retorno;
}

int buscarConfederacionId(eConfederacion vec[], int tam, int id, int* pIndice)
{
    int retorno = 0;
    if(vec != NULL && tam > 0 && pIndice != NULL && id > 0)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}

int cargarDescripcionConfederacion(eConfederacion vec[], int tam, int id, char descripcion[])
{
    int retorno = 0;
    int indiceConfederacion;

    buscarConfederacionId(vec,tam,id,&indiceConfederacion);

    if(descripcion != NULL && indiceConfederacion != -1 )
    {
        strcpy(descripcion, vec[indiceConfederacion].nombre);
        retorno = 1;
    }
    return retorno;
}

int cargarDescripcionRegion(eConfederacion vec[], int tam, int id, char descripcion[])
{
    int retorno = 0;
    int indiceConfederacion;

    buscarConfederacionId(vec,tam,id,&indiceConfederacion);

    if(descripcion != NULL && indiceConfederacion != -1 )
    {
        strcpy(descripcion, vec[indiceConfederacion].region);
        retorno = 1;
    }
    return retorno;
}

int copiarPosicion(char descripcion[],int idPosicion)
{
    int retorno=0;
    switch(idPosicion)
    {
    case 1:
        strcpy(descripcion,"Arquero");
        break;
    case 2:
        strcpy(descripcion,"Defensor");
        break;
    case 3:
        strcpy(descripcion,"Mediocampista");
        break;
    case 4:
        strcpy(descripcion,"Delantero");
        break;
    }
    retorno =1;
    return retorno;
}


