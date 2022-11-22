#include "Informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ordenarJugadorAsc(eJugador vec[], int tam, eConfederacion confederaciones[], int cantConfederacion)
{
    int retorno=0;
    eJugador auxiliar;
    int indiceX;
    int indiceI;
    if(vec != NULL && tam > 0 && confederaciones != NULL && cantConfederacion > 0)
    {
        for(int x=0; x<tam-1; x++)
        {
            for(int i=x+1; i<tam; i++)
            {
                buscarConfederacionId(confederaciones,cantConfederacion,vec[x].idConfederacion,&indiceX);
                buscarConfederacionId(confederaciones,cantConfederacion,vec[i].idConfederacion,&indiceI);

                if(strcmp(confederaciones[indiceX].nombre, confederaciones[indiceI].nombre) > 0)
                {
                    auxiliar = vec[x];
                    vec[x] = vec[i];
                    vec[i] = auxiliar;
                }
                else if(confederaciones[x].nombre == confederaciones[i].nombre)
                {
                    if(strcmp(vec[x].nombre, vec[i].nombre) > 0)
                    {
                        auxiliar = vec[x];
                        vec[x] = vec[i];
                        vec[i] = auxiliar;
                    }
                }
            }
        }
    }
    return retorno = 1;
}

int informarJugadorConfederacion(eJugador vec[], int tam,eConfederacion confederaciones[], int tamConfederacion)
{
    int todoOk = 0;
    int idConfederacion;
    int flag = 1;
    char descripcion[50];


    if(vec != NULL && confederaciones != NULL && tam > 0 && tamConfederacion > 0)
    {
        printf(" __________________________________________________\n");
        printf("|  *** Listado de Jugadores por Confederacion***   |\n");
        printf("|==================================================|\n");
        printf("|INGRESE EL ID DE UNA CONFEDERACION PARA INFORMAR  |\n");
        printf("|__________________________________________________|\n");

        mostrarConfederacion(confederaciones, tamConfederacion);

        tomarEntero(&idConfederacion, "ingrese el id de una confederacion: ", "\nVUELVA A INGRESAR UN ID!\n",100,105,1000);
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == OCUPADO && vec[i].idConfederacion == idConfederacion)
            {
                printf("\n ___________________________________________________________________________________________________________________________________\n"
                       "|%-5s|%-20s|%-20s|%-20s|%-20s|%-20s|A%cos de Contrato    |\n"
                       "|=====|====================|====================|====================|====================|====================|====================|\n","ID","Nombre","Posicion","Nro Camiseta","Sueldo","Confederacion",164);
                mostrarUnJugador(vec[i], confederaciones, tamConfederacion);
                printf("|_____|____________________|____________________|____________________|____________________|____________________|____________________|\n");
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionConfederacion(confederaciones,tamConfederacion, idConfederacion, descripcion);
            printf("\nNo hay Jugadores registrados en la confederacion: %s\n", descripcion);
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int informarTotalPromedio(eJugador vec[], int tam)
{
    int retorno = 0;
    float acomulador = 0;
    int contador = 0;
    float promedio;
    int contadorPromedio = 0;
    if(vec != NULL)
    {
        for(int i= 0; i<tam; i++)
        {
            if(vec[i].isEmpty == OCUPADO)
            {
                acomulador += vec[i].salario;
                contador++;
            }
        }

        promedio = (float) acomulador / contador;

        for(int i= 0; i<tam; i++)
        {
            if(vec[i].isEmpty == OCUPADO)
            {
                if(vec[i].salario > promedio)
                {
                    contadorPromedio ++;
                }
            }
        }
        retorno = 1;
        printf("\nSalario total de Jugadores: %.2f\nPromedio del salario: %.2f\nContador de jugadores que superan el promedio: %d\n",acomulador,promedio,contadorPromedio);
    }
    return retorno;
}

int calcularConfederacionRegion(eJugador vec[], int tam, int* pConfederacion, int* pRegion)
{
    int retorno = 0;
    int acumuladores[6];
    int contadores[6];
    int confederacionMasContratos=0;
    int regionMasJugadores = 0;

    if(vec != NULL && tam > 0 && pConfederacion != NULL && pRegion != NULL)
    {
        for(int x = 0; x<6; x++)
        {
            acumuladores[x] = 0;
            contadores[x] = 0;
        }

        for(int x = 0; x<tam; x++)
        {
            if(vec[x].isEmpty == OCUPADO)
            {
                switch(vec[x].idConfederacion)
                {
                case 100:
                    acumuladores[0] += vec[x].aniosContrato;
                    contadores[0]++;
                    break;
                case 101:
                    acumuladores[1] += vec[x].aniosContrato;
                    contadores[1]++;
                    break;
                case 102:
                    acumuladores[2] += vec[x].aniosContrato;
                    contadores[2]++;
                    break;
                case 103:
                    acumuladores[3] += vec[x].aniosContrato;
                    contadores[3]++;
                    break;
                case 104:
                    acumuladores[4] += vec[x].aniosContrato;
                    contadores[4]++;
                    break;
                case 105:
                    acumuladores[5] += vec[x].aniosContrato;
                    contadores[5]++;
                    break;
                }
            }
        }
        for(int i=0; i<6; i++)
        {
            if(acumuladores[i] > confederacionMasContratos)
            {
                confederacionMasContratos = acumuladores[i];
                *pConfederacion = i;
            }

            if(contadores[i] > regionMasJugadores)
            {
                regionMasJugadores = contadores[i];
                *pRegion = i;
            }
        }
        switch(*pConfederacion)
        {
        case 0:
            *pConfederacion = 100;
            break;
        case 1:
            *pConfederacion = 101;
            break;
        case 2:
            *pConfederacion = 102;
            break;
        case 3:
            *pConfederacion = 103;
            break;
        case 4:
            *pConfederacion = 104;
            break;
        case 5:
            *pConfederacion = 105;
            break;
        }

        switch(*pRegion)
        {
        case 0:
            *pRegion = 100;
            break;
        case 1:
            *pRegion = 101;
            break;
        case 2:
            *pRegion = 102;
            break;
        case 3:
            *pRegion = 103;
            break;
        case 4:
            *pRegion = 104;
            break;
        case 5:
            *pRegion = 105;
            break;
        }
        retorno = 1;
    }
    return retorno;
}

int calcularPorcentaje(eJugador vec[], int tam, float* pPorcentajeCAF, float* pPorcentajeAFC, float* pPorcentajeUEFA, float* pPorcentajeCONMEBOL, float* pPorcentajeCONCACAF, float* pPorcentajeOFC)
{
    int retorno = 0;
    int contadores[6];
    int contadorJugadores = 0;
    if(vec != NULL && tam > 0 && pPorcentajeCAF != NULL && pPorcentajeAFC != NULL && pPorcentajeUEFA && pPorcentajeCONMEBOL != NULL && pPorcentajeCONCACAF != NULL && pPorcentajeOFC != NULL)
    {
        for(int x=0; x<6; x++)
        {
            contadores[x] = 0;
        }

        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty == OCUPADO)
            {
                contadorJugadores++;

                switch(vec[i].idConfederacion)
                {
                case 100:
                    contadores[0]++;
                    break;
                case 101:
                    contadores[1]++;
                    break;
                case 102:
                    contadores[2]++;
                    break;
                case 103:
                    contadores[3]++;
                    break;
                case 104:
                    contadores[4]++;
                    break;
                case 105:
                    contadores[5]++;
                    break;
                }
            }
        }

        *(pPorcentajeCONMEBOL) = (float)((contadores[0] * 100) / contadorJugadores);
        *(pPorcentajeUEFA) = (float) ((contadores[1] * 100) / contadorJugadores);
        *(pPorcentajeAFC) = (float) ((contadores[2] * 100) / contadorJugadores);
        *(pPorcentajeCAF) = (float) ((contadores[3] * 100) / contadorJugadores);
        *(pPorcentajeCONCACAF) = (float) ((contadores[4] * 100) / contadorJugadores);
        *(pPorcentajeOFC) = (float) ((contadores[5] * 100) / contadorJugadores);

        retorno = 1;
    }
    return retorno;

}

int informarPorcentaje(float PorcentajeCAF, float PorcentajeAFC, float PorcentajeUEFA, float PorcentajeCONMEBOL, float PorcentajeCONCACAF, float PorcentajeOFC)
{
    int retorno = 0;
    printf("\n ================================================\n");
    printf("| Porcentaje de Jugadores por cada Confederacion |\n");
    printf("+================================================+\n");
    printf(" Porcentaje CONMEBOL: %.2f\n", PorcentajeCONMEBOL);
    printf(" Porcentaje AFC: %.2f\n", PorcentajeAFC);
    printf(" Porcentaje UEFA: %.2f\n", PorcentajeUEFA);
    printf(" Porcentaje CAF: %.2f\n", PorcentajeCAF);
    printf(" Porcentaje CONCACAF: %.2f\n", PorcentajeCONCACAF);
    printf(" Porcentaje OFC: %.2f\n\n", PorcentajeOFC);

    retorno = 1;
    return retorno;
}

int listarPorRegion(eJugador jugadores[], eConfederacion confederaciones[], int tam, int cantConfederacion, int idRegion)
{
    int retorno = 0;
    if(jugadores != NULL)
    {
        for(int x = 0; x<tam; x++)
        {
            if(jugadores[x].isEmpty == OCUPADO && jugadores[x].idConfederacion == idRegion)
            {
                printf("\n ___________________________________________________________________________________________________________________________________\n"
                       "|%-5s|%-20s|%-20s|%-20s|%-20s|%-20s|A%cos de Contrato    |\n"
                       "|=====|====================|====================|====================|====================|====================|====================|\n","ID","Nombre","Posicion","Nro Camiseta","Sueldo","Confederacion",164);
                mostrarUnJugador(jugadores[x],confederaciones,cantConfederacion);
                printf("|_____|____________________|____________________|____________________|____________________|____________________|____________________|\n");
                retorno = 1;
            }
        }
    }
    return retorno;
}

int informarOpciones(eJugador vec[], int cantJugador, eConfederacion confederaciones[], int cantConfederacion)
{
    int retorno = 0;
    int opcion;
    int confederacionMayorContratos;
    int regionMasJugadores;
    float pCONMEBOL;
    float pAFC;
    float pCAF;
    float pUEFA;
    float pCONCACAF;
    float pOFC;
    char descripcionConfederacion[50];
    char descripcionRegion[50];
    if(vec != NULL && cantJugador > 0 && confederaciones != NULL && cantConfederacion > 0)
    {
        menuInformes();
        tomarEntero(&opcion,"ingrese una opcion: ","\nPorfavor, ingrese una opcion valida!\n\n",1,6,100000);

        switch(opcion)
        {
        case 1:
            ordenarJugadorAsc(vec, cantJugador, confederaciones, cantConfederacion);
            listarJugadores(vec, cantJugador, confederaciones, cantConfederacion);
            break;
        case 2:
            informarJugadorConfederacion(vec,cantJugador,confederaciones,cantConfederacion);
            break;
        case 3:
            informarTotalPromedio(vec,cantJugador);
            break;
        case 4:
            calcularConfederacionRegion(vec,cantJugador,&confederacionMayorContratos, &regionMasJugadores);
            cargarDescripcionConfederacion(confederaciones,cantConfederacion,confederacionMayorContratos,descripcionConfederacion);
            printf("\nLa confederaci%cn con mayor cantidad de a%cos de contratos total es: %s \n",162, 164, descripcionConfederacion);
            break;
        case 5:
            calcularPorcentaje(vec, cantJugador, &pCAF, &pAFC, &pUEFA, &pCONMEBOL, &pCONCACAF, &pOFC);
            informarPorcentaje(pCAF,pAFC,pUEFA,pCONMEBOL,pCONCACAF,pOFC);
            break;
        case 6:
            calcularConfederacionRegion(vec,cantJugador,&confederacionMayorContratos,&regionMasJugadores);
            cargarDescripcionRegion(confederaciones,cantConfederacion,regionMasJugadores,descripcionRegion);
            printf("\nLa regi%cn con m%cs jugadores es: %s\n\n",162, 160, descripcionRegion);
            listarPorRegion(vec,confederaciones,cantJugador,cantConfederacion,regionMasJugadores);
            break;
        }
        retorno = 1;
    }
    return retorno;
}
