#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Jugadores.h"
#include "Confederaciones.h"
#include "Menus.h"
#include "Inputs.h"
#include "Informes.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
    eConfederacion confederaciones[CANT_CONFEDERACION];
    eJugador jugadores[CANT_JUGADOR];
    int pOpcion;
    char pSalir;
    int idJugadores=1000;
    int contadorJugadores=0;
    int validacionBaja;

    inicializarJugadores(jugadores,CANT_JUGADOR);
    harcodearConfederacion(confederaciones, CANT_CONFEDERACION);

    /**< -----------------------------------------------menu de opciones---------------------------------------------------------------------------------------------------------- */
    do
    {
        menuPrincipal();
        tomarEntero(&pOpcion,"ingrese una opcion: ","\nPorfavor, ingrese una opcion valida!\n\n",1,5,100000);
        switch(pOpcion)
        {
        case 1:
            if(altaJugadores(jugadores,CANT_JUGADOR,&idJugadores))
            {
                printf("\nJugador agregado con exito!\n");
                contadorJugadores++;
            }
            else
            {
                printf("\nError, hubo problemas al momento de hacer el alta de Jugadores!\nVolver a intentar!\n");
            }
            break;
        case 2:
            if(contadorJugadores > 0)
            {
                validacionBaja = bajaJugador(jugadores,CANT_JUGADOR,confederaciones,CANT_CONFEDERACION);
                if(validacionBaja == -1)
                {
                    printf("\nHubo un Error al hacer la Baja de Jugadores!\nVolver a intentar!\n");
                }
                else if(!validacionBaja)
                {
                    printf("\nBaja cancelada por el usuario!\n");
                }
                else
                {
                    contadorJugadores--;
                }
            }
            else
            {
                printf("\nIngrese un jugador para poder eliminarlo!\n");
            }
            break;
        case 3:
            if(contadorJugadores > 0)
            {
                modificarJugador(jugadores,CANT_JUGADOR,confederaciones,CANT_CONFEDERACION);
                printf("\nModificacion realizada con exito!\n");
            }
            else
            {
                printf("\nPorfavor, ingrese un Jugador antes de hacer la modificaci%cn!\n",162);
            }
            break;
        case 4:
            if(contadorJugadores > 0)
            {
                informarOpciones(jugadores, CANT_JUGADOR, confederaciones, CANT_CONFEDERACION);
            }
            else
            {
                printf("\nIngrese un jugador para poder informar los datos!\n");
            }
            break;
        case 5:
            salirMenu(&pSalir);
            break;
        default:
            printf("\nPorfavor, ingrese una opcion valida!\n\n");
            break;
        }
    }
    while(pSalir != 's');
    return 0;
}
