/*
 * Menus.c
 *
 *  Created on: 23 sept 2022
 *      Author: IvoBarin
 */

#include "Menus.h"

char menuPrincipal(int hospedaje, int comida, int transporte, int arqueros, int defensores, int mediocampistas, int delanteros)// le pasamos por param los acumuladores para que se incremente el menu
{
    char opcion;
    printf(" _________________________________________________\n");
    printf("|           >>> Menu Principal<<<                 |\n");
    printf("|_________________________________________________|\n\n");
    printf(" 1. Ingreso de los costos de Mantenimiento:\n");
    printf("  Costo de Hospedaje -> $%d\n", hospedaje);
    printf("  Costo de Comida -> $%d\n", comida);
    printf("  Costo de Transporte -> $%d\n", transporte);
    printf(" 2.Carga de Jugadores:\n");
    printf("  Arqueros -> %d\n",arqueros);
    printf("  Defensores -> %d\n",defensores);
    printf("  Mediocampistas -> %d\n",mediocampistas);
    printf("  Delanteros-> %d\n",delanteros);
    printf(" 3.Realizar todos los calculos\n");
    printf(" 4.Informar todos los resultados\n");
    printf(" 5.Salir\n");
    printf("\n");
    printf ("Ingrese una opcion: ");
    fflush(stdin);
    // lo agarra como tipo de dato caracter(Cadena sin tamaño), y no como tipo de dato entero, para que no se rompa el programa si el usuario le ingresa una letra como opcion
    scanf("%s", &opcion);
    return opcion;
}

char menuMantenimiento()
{
    char opcion;
    printf(" _________________________________________________\n");
    printf("|           >>> Costo de Mantenimiento<<<         |\n");
    printf("|_________________________________________________|\n");
    printf("| 1. Costo de Hospedaje                           |\n");
    printf("| 2. Costo de Comida                              |\n");
    printf("| 3. Costo de Transporte                          |\n");
    printf("|_________________________________________________|\n\n");
    printf ("Ingrese una opcion: ");
    fflush(stdin);
// lo agarra como tipo de dato caracter(Cadena sin tamaño), y no como tipo de dato entero, para que no se rompa el programa si el usuario le ingresa una letra como opcion
    scanf("%s", &opcion);
    printf("\n");
    return opcion;
}

void pausarPantalla()// funcion que reemplaza al system("pause"), usa la funcion getch de la bibloteca ctype.h
{
    printf("\nPresione una tecla para continuar...");
    fflush(stdin);
    getch();
    printf("\n");
}

char menuJugadores()
{
    char opcion;
    printf(" _________________________________________________\n");
    printf("|           >>> Carga de Jugadores<<<             |\n");
    printf("|_________________________________________________|\n");
    printf("| 1. Carga de Arqueros                            |\n");
    printf("| 2. Carga de Defensores                          |\n");
    printf("| 3. Carga de Mediocampistas                      |\n");
    printf("| 4. Carga de Delanteros                          |\n");
    printf("|_________________________________________________|\n\n");
    printf ("Ingrese una opcion: ");
    fflush(stdin);
// lo agarra como tipo de dato caracter(Cadena sin tamaño), y no como tipo de dato entero, para que no se rompa el programa si el usuario le ingresa una letra como opcion
    scanf("%s", &opcion);
    printf("\n");
    return opcion;
}

void mostrarResultados(float pPromedioUEFA,float pPromedioCONMEBOL, float pPromedioCONCACAF, float pPromedioAFC, float pPromedioOFC, float pPromedioCAF)
{
    printf(" _________________________________________________\n");
    printf("|      >>> Informar todos los Resultados<<<       |\n");
    printf("|_________________________________________________|\n\n");
    printf(" Promedio Uefa: %.2f\n", pPromedioUEFA);
    printf(" Promedio Conmebol: %.2f\n",pPromedioCONMEBOL);
    printf(" Promedio Concacaf: %.2f\n", pPromedioCONCACAF);
    printf(" Promedio Afc: %.2f\n",pPromedioAFC);
    printf(" Promedio Ofc: %.2f\n",pPromedioOFC);
    printf(" Promedio Caf: %.2f\n", pPromedioCAF);
    printf("\n");
}

void menuConfederacion()
{
    printf(" _________________________________________________\n");
    printf("|         >>> Carga de Confederaci%cn<<<          |\n",162);
    printf("|_________________________________________________|\n");
    printf("| 1. Carga de AFC                                 |\n");
    printf("| 2. Carga de CAF                                 |\n");
    printf("| 3. Carga de CONCACAF                            |\n");
    printf("| 4. Carga de CONMEBOL                            |\n");
    printf("| 5. Carga de UEFA                                |\n");
    printf("| 6. Carga de OFC                                 |\n");
    printf("|_________________________________________________|\n\n");
    printf ("Ingrese una opcion: ");
}


