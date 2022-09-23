/*
 ============================================================================
 Name        : TP1.c
 Author      : Ivo Barinstein
 Version     : 1.0
 Copyright   : Trabajo Práctico numero 1 de Ivo Barinstein (2do Cuatrimestre)
 Description : Creado el 15/09/22 (originalmente en CodeBlocks) y ultima modificación el 23/09/22 (eclipse)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "conio.h"
#include "Menus.h"
#include "Validacion.h"
#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	 //variables para gasto del hospedaje
	 int pHospedaje;
	 int acumuladorHospedaje=0;
	 //variables para gasto de la comida
	 int pComida;
	 int acumuladorComida=0;
	 //variables para el gasto del transporte
	 int pTransporte;
	 int acumuladorTransporte=0;
	 //variables para la carga de Jugadores(contadores)
	 int contadorArqueros=0;
	 int contadorDefensores=0;
	 int contadorMediocampistas=0;
	 int contadorDelanteros=0;
	 //variables para la carga de Jugadores(punteros)
	 int pCamisetas;
	  int pContadorAFC=0;
	    int pContadorCAF=0;
	    int pContadorCONCACAF=0;
	    int pContadorCONMEBOL=0;
	    int pContadorUEFA=0;
	    int pContadorOFC=0;
	    int confederacion=0;
	    //Varibles y punteros para realizar todas las operaciones
	    float pPromedioAFC=0;
	    float pPromedioCAF=0;
	    float pPromedioCONCACAF=0;
	    float pPromedioCONMEBOL=0;
	    float pPromedioUEFA=0;
	    float pPromedioOFC=0;
	    int totalJugadores;
	    int mantenimientoTotal=0;
	    int aumento=0;
	    int mantenimientoAumentado=0;
	    //validacion para informar resultados
	    int banderaMantenimiento=0;
	    int banderaCargaJugadores=0;
	    int banderaResultados=0;
	    //variables para los menus
	    int confirmacion;
	    char salir;

	do
	    {
	           switch(menuPrincipal(acumuladorHospedaje, acumuladorComida, acumuladorTransporte, contadorArqueros, contadorDefensores,contadorMediocampistas, contadorDelanteros))
	           {
	           case '1'://OPCIÓN 1: INGRESO DE COSTOS DE MANTENIMIENTO
	               //pausarPantalla();
	               banderaMantenimiento = 1;
	               switch(menuMantenimiento())
	               {
	               case '1'://OPCIONES DEL MENU MANTENIMIENTO
	                   if(acumuladorHospedaje == 0)
	                   {
	                       cargaDatosMantenimiento(&pHospedaje, "Porfavor, ingrese el costo del hospedaje: ","\nPorfavor, vuelva a ingresar un costo de hospedaje valido:", 100000, 0);
	                       acumuladorHospedaje += pHospedaje;
	                   }
	                   else
	                   {
	                       confirmacion = confirmarProcedimiento("Esta seguro que quiere incrementar el costo del hospedaje [s|n]: ");
	                       if(confirmacion)
	                       {
	                           cargaDatosMantenimiento(&pHospedaje, "Porfavor, ingrese el costo del hospedaje: ","\nPorfavor, vuelva a ingresar un costo de hospedaje valido:", 100000, 0);
	                           acumuladorHospedaje+=pHospedaje;
	                       }
	                   }
	                   break;
	               case '2':
	                   if(acumuladorComida == 0)
	                   {
	                       cargaDatosMantenimiento(&pComida, "Porfavor, ingrese el costo de la comida: ","\nPorfavor, vuelva a ingresar un costo de comida valido:", 100000, 0);
	                       acumuladorComida += pComida;
	                   }
	                   else
	                   {
	                       confirmacion = confirmarProcedimiento("Esta seguro que quiere incrementar el costo de la comida [s|n]: ");
	                       if(confirmacion)
	                       {
	                           cargaDatosMantenimiento(&pComida, "Porfavor, ingrese el costo de la comida: ","\nPorfavor, vuelva a ingresar un costo de comida valido:", 100000, 0);
	                           acumuladorComida += pComida;
	                       }
	                   }
	                   break;
	               case '3':
	                   if(acumuladorTransporte == 0)
	                   {
	                       cargaDatosMantenimiento(&pTransporte, "Porfavor, ingrese el costo del transporte: ","\nPorfavor, vuelva a ingresar el costo del transporte valido:", 100000, 0);
	                       acumuladorTransporte += pTransporte;
	                   }
	                   else
	                   {
	                       confirmacion = confirmarProcedimiento("Esta seguro que quiere incrementar el costo del Transporte [s|n]: ");
	                       if(confirmacion)
	                       {
	                           cargaDatosMantenimiento(&pTransporte, "Porfavor, ingrese el costo del transporte: ","\nPorfavor, vuelva a ingresar el costo del transporte valido:", 100000, 0);
	                           acumuladorTransporte += pTransporte;
	                       }
	                   }
	                   break;
	               }
	               break;
	           case '2'://OPCIÓN 2: CARGA DE JUGADORES
	              // pausarPantalla();
	               banderaCargaJugadores = 1;
	               switch(menuJugadores())
	               {
	               case '1'://OPCIONES DEL MENU DE JUGADORES
	                   if(contadorArqueros < 2)
	                   {
	                       contadorArqueros++;
	                       cargaCamisetas(&pCamisetas,"Porfavor, ingrese el numero de la camiseta de su arquero: ", "\n\nError, vuelva a ingresar el numero de camiseta del Arquero: ");
	                       menuConfederacion();
	                       confederacion = contadorConfederacion(&pContadorAFC,&pContadorCAF,&pContadorCONCACAF,&pContadorCONMEBOL,&pContadorUEFA,&pContadorOFC);
	                       if(confederacion == 0){
	                    	   contadorArqueros--;
	                       }
	                   }
	                   else
	                   {
	                       printf("No puede ingresar m%cs de 2 arqueros, cantidad maxima alcanzada!\n", 160);
	                   }
	                   break;
	               case '2':
	                   if(contadorDefensores < 8)
	                   {
	                       contadorDefensores++;
	                       cargaCamisetas(&pCamisetas,"Porfavor, ingrese el numero de la camiseta de su defensor: ", "\n\nError, vuelva a ingresar el numero de camiseta del Defensor: ");
	                       menuConfederacion();
	                       confederacion = contadorConfederacion(&pContadorAFC,&pContadorCAF,&pContadorCONCACAF,&pContadorCONMEBOL,&pContadorUEFA,&pContadorOFC);
	                       if(confederacion == 0){
	                    	   contadorDefensores--;
	                       	 }
	                   }
	                   else
	                   {
	                       printf("No puede ingresar m%cs de 8 defensores, cantidad maxima alcanzada!\n", 160);
	                   }
	                   break;
	               case '3':
	                   if(contadorMediocampistas < 8)
	                   {
	                       contadorMediocampistas++;
	                       cargaCamisetas(&pCamisetas,"Porfavor, ingrese el numero de la camiseta de su mediocampista: ", "\n\nError, vuelva a ingresar el numero de camiseta del Mediocampista: ");
	                       menuConfederacion();
	                       confederacion = contadorConfederacion(&pContadorAFC,&pContadorCAF,&pContadorCONCACAF,&pContadorCONMEBOL,&pContadorUEFA,&pContadorOFC);
	                       if(confederacion == 0){
	                    	   contadorMediocampistas--;
	                      }
	                   }
	                   else
	                   {
	                       printf("No puede ingresar m%cs de 8 mediocampistas, cantidad maxima alcanzada!\n", 160);
	                   }
	                   break;
	               case '4':
	                   if(contadorDelanteros < 4)
	                   {
	                       contadorDelanteros++;
	                       cargaCamisetas(&pCamisetas,"Porfavor, ingrese el numero de la camiseta de su delantero: ", "\n\nError, vuelva a ingresar el numero de camiseta del Delantero: ");
	                       menuConfederacion();
	                       confederacion = contadorConfederacion(&pContadorAFC,&pContadorCAF,&pContadorCONCACAF,&pContadorCONMEBOL,&pContadorUEFA,&pContadorOFC);
	                       if(confederacion == 0){
	                    	   contadorDelanteros--;
	                       }
	                   }
	                   else
	                   {
	                       printf("No puede ingresar m%cs de 4 delanteros, cantidad maxima alcanzada!\n", 160);
	                   }
	                   break;
	               }
	               break;
	           case '3'://OPCIÓN 3: REALIZAR TODOS LOS CÁLCULOS
	               //pausarPantalla();
	               if(banderaMantenimiento == 0 || banderaCargaJugadores == 0)
	               {
	                   printf("\nPor favor, ingrese el costo de los mantenimientos, y la carga de datos de los jugadores, para poder continuar!\n");
	               }
	               else
	               {
	                   confirmacion = confirmarProcedimiento("\nEsta seguro que desea calcular el promedio de jugadores y el costo del mantenimiento[s|n]: ");
	                   if(confirmacion)
	                   {
	                       banderaResultados = 1;
	                       mantenimientoTotal = (acumuladorComida + acumuladorHospedaje + acumuladorTransporte);
	                       totalJugadores = (contadorArqueros + contadorDefensores + contadorDelanteros + contadorMediocampistas);
	                       promedioJugadores(totalJugadores,pContadorAFC,pContadorCAF,pContadorCONCACAF,pContadorCONMEBOL,pContadorUEFA,pContadorOFC,&pPromedioAFC,&pPromedioCAF,&pPromedioCONCACAF,&pPromedioCONMEBOL,&pPromedioUEFA,&pPromedioOFC);
	                       calcularMantenimientoAumento(mantenimientoTotal, pContadorUEFA, pContadorCAF, pContadorCONCACAF, pContadorAFC, pContadorCONMEBOL, pContadorOFC, &aumento);
	                       mantenimientoAumentado = mantenimientoTotal + aumento;
	                       printf("\nCarga de calculos realizada con exito!\n");
	                   }
	               }
	               break;
	           case '4'://OPCIÓN 4: INFORMAR TODOS LOS RESULTADOS
	               //pausarPantalla();
	               if(banderaResultados)
	               {
	                   mostrarResultados(pPromedioUEFA,pPromedioCONMEBOL,pPromedioCONCACAF,pPromedioAFC,pPromedioOFC,pPromedioCAF);
	                   if(aumento > 0)
	                   {
	                       printf("El costo del mantenimiento era de %d y recibio un aumento de $%d, su nuevo valor es de: $%d\n", mantenimientoTotal, aumento, mantenimientoAumentado);
	                   }
	                   else
	                   {
	                       printf("El costo total del mantenimiento es de $%d", mantenimientoTotal);
	                   }
	               }
	               else
	               {
	                   printf("\nPor favor, realice los calculos para poder continuar!\n");
	               }
	               break;
	           case '5'://OPCIÓN 5: SALIR
	               salirMenu(&salir);
	               break;
	           default:
	               printf("\nPorfavor, vuelva a ingresar una opcion valida!\n");
	               break;
	           }
	           //pausarPantalla();
	       }
	       while(salir != 's');

	return EXIT_SUCCESS;
}
