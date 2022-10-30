#include "Menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void menuPrincipal()
{
    printf(" _________________________________________________\n");
    printf("|            >>>Menu Principal<<<                 |\n");
    printf("|-------------------------------------------------|\n");
    printf("| 1. Alta de Jugador                              |\n");
    printf("| 2. Baja de Jugador                              |\n");
    printf("| 3. Modificar Jugador                            |\n");
    printf("| 4. Informes                                     |\n");
    printf("| 5. Salir del Programa                           |\n");
    printf("|_________________________________________________|\n\n");
}

void menuPosicion()
{
    printf("\n");
    printf(" _____________________\n");
    printf("|ID | POSICIONES      |\n");
    printf("|===|=================|\n");
    printf("| 1 | Arquero         |\n");
    printf("| 2 | Defensor        |\n");
    printf("| 3 | Mediocampista   |\n");
    printf("| 4 | Delantero       |\n");
    printf("|___|_________________|\n\n");
}

void menuModificacion()
{
    printf("\n");
    printf(" _______________________________\n");
    printf("|ID | Menu Modificacion         |\n");
    printf("|===|===========================|\n");
    printf("| 1 | Modificar Nombre          |\n");
    printf("| 2 | Modificar Posicion        |\n");
    printf("| 3 | Modificar Numero Camiseta |\n");
    printf("| 4 | Modificar Confederacion   |\n");
    printf("| 5 | Modificar Salario         |\n");
    printf("| 6 | Modificar A%cos Contrato   |\n",164);
    printf("| 7 | Salir del Menu            |\n");
    printf("|___|___________________________|\n\n");
}

void menuInformes()
{
    printf("\n");
    printf(" ___________________________________________________________________\n");
    printf("|ID | Menu de Informes                                              |\n");
    printf("|===|===============================================================|\n");
    printf("| 1 | Ordenamiento por nombre de confederaci%cn o nombre de jugador. |\n",162);
    printf("| 2 | Listado de confederaciones con sus jugadores.                 |\n");
    printf("| 3 | Total y promedio de salarios y cu%cntos jugadores.             |\n",160);
    printf("| 4 | Informar confederaci%cn con mayor cantidad de a%cos de contrato.|\n",162,164);
    printf("| 5 | Informar porcentaje de jugadores por cada confederaci%cn.      |\n",162);
    printf("| 6 | Informar la regi%cn con m%cs jugadores y el listado.            |\n",162,160);
    printf("|___|_______________________________________________________________|\n\n");
}
