#include "Jugadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int altaJugadores(eJugador jugadores[], int cantJugador, int* pId)
{
    eJugador nuevoJugador;
    int retorno = -1;
    short indice;
    if(jugadores != NULL && cantJugador > 0)
    {
        indice = buscarJugadorLibre(jugadores,cantJugador);

        if(indice != -1)
        {
            nuevoJugador = cargaDatosJugador();
            nuevoJugador.isEmpty = OCUPADO;
            nuevoJugador.id = *pId;
            (*pId)++;
            jugadores[indice] = nuevoJugador;
            retorno = 1;
        }
        else
        {
            printf("\nNo hay lugar en el sistema!\n");
            retorno = 0;
        }
    }
    return retorno;
}

eJugador cargaDatosJugador()
{
    eJugador auxiliar;
    eConfederacion confederaciones[6];
    int idPosicion;
    char descripcionPosicion[50];
    int numeroCamiseta;
    int contrato;

    //CARGA DE NOMBRE
    tomarCadena(auxiliar.nombre,50,"\nPorfavor, ingrese el nombre del Jugador: ","\nError, ingrese al menos una letra y ningun numero!\n",1000);
    fflush(stdin);//vaciamos la entrada standard
    //CARGA DE CONFEDERACION
    menuPosicion();
    tomarEntero(&idPosicion,"\nIngrese el ID de una posicion: ","\nError, vuelva a ingresar el ID de una posicion!\n",1,4,1000);
    copiarPosicion(descripcionPosicion,idPosicion);
    strcpy(auxiliar.posicion, descripcionPosicion);
    //CARGA DE NUMERO CAMISETA
    tomarEntero(&numeroCamiseta,"\nIngrese un numero en la camiseta: ","\nError, vuelva a ingresar el numero de la camiseta!\n",1,99,1000);
    auxiliar.numeroCamiseta = (short)numeroCamiseta;
    //CARGA DE CONFEDERACION
    harcodearConfederacion(confederaciones,6);
    mostrarConfederacion(confederaciones,6);
    tomarEntero(&auxiliar.idConfederacion,"\nIngrese el ID de una confederacion: ","\nError, vuelva a ingresar el ID de una posicion!\n",100,105,1000);
    //CARGA DE SALARIO
    tomarFlotante(&auxiliar.salario, "\nIngrese un monto del salario: ","\nError, vuelva a ingresar el monto del salario!\n",1,100000000,1000);
    //CARGA DE LOS AÑOS DEL CONTRATO
    tomarEntero(&contrato,"\nIngrese la cantidad de tiempo por contrato [1 a 10]: ","\nError, vuelva a ingresar la cantidad de tiempo por contrato!\n",1,10,1000);
    auxiliar.aniosContrato = (short)contrato;
    return auxiliar;
}

int inicializarJugadores(eJugador vec[], int tam)
{
    short* pVector;
    int retorno = 0;
    if(vec != 0 && tam > 0)
    {
        pVector = &vec->isEmpty;//marcamos que el puntero es igual a la direccion de memoria del campo del vector
        for(int x=0; x<tam; x++)
        {
            *(pVector + x-1) = VACIO;//notacion de aritmetica de puntero, (x-1) para que entre al indice 0;
        }
        retorno = 1;
    }
    return retorno;
}

int eJugadorBuscarEspacioLibre(eJugador vec[], int tam)
{
    int retorno = -1;
    if(vec != NULL && tam > 0)
    {
        for(int x=0; x<tam; x++)
        {
            if(!vec[x].isEmpty)
            {
                retorno = x;
                break;
            }
        }
    }
    return retorno;
}

short buscarJugadorLibre(eJugador jugadores[], int cantJugador)
{
    int retorno = -1;

    for(int x=0; x<cantJugador; x++)
    {
        if(jugadores[x].isEmpty == VACIO)
        {
            retorno = x;
            break;
        }
    }

    return retorno;
}

int listarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion)
{
    int retorno = 0;
    int bandera = 0;
    char descripcion[50];

    if(jugadores != NULL && tam > 0 && confederaciones != NULL && cantConfederacion > 0)
    {
        printf("\n ___________________________________________________________________________________________________________________________________\n"
               "|%-5s|%-20s|%-20s|%-20s|%-20s|%-20s|A%cos de Contrato    |\n"
               "|=====|====================|====================|====================|====================|====================|====================|\n","ID","Nombre","Posicion","Nro Camiseta","Confederacion","Sueldo",164);
        for(int x=0; x<tam; x++)
        {
            if(jugadores[x].isEmpty == OCUPADO)
            {
                bandera=1;
                cargarDescripcionConfederacion(confederaciones,cantConfederacion,jugadores[x].idConfederacion,descripcion);
                printf("|%-5d|%-20s|%-20s|%-20hd|%-20s|%-20.2f|%-20hd|\n",jugadores[x].id,jugadores[x].nombre, jugadores[x].posicion, jugadores[x].numeroCamiseta, descripcion, jugadores[x].salario, jugadores[x].aniosContrato);
            }
        }
        printf("|_____|____________________|____________________|____________________|____________________|____________________|____________________|\n");

        if(bandera == 0)
        {
            printf("\nNo hay jugadores en el sistema!\n");
        }
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}

int buscarJugadorOcupado(eJugador vec[], int tam, int id, int* pIndice)
{
    int retorno = 0;
    if(vec != NULL && tam > 0 && pIndice != NULL && id > 0)
    {
        *pIndice = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty == OCUPADO && vec[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        retorno = 1;
    }
    return retorno;
}

int mostrarUnJugador(eJugador jugador, eConfederacion confederaciones[],int cantConfederacion)
{
    int retorno = 0;
    char descripcion[50];

    if(confederaciones != NULL && cantConfederacion > 0)
    {
        if(jugador.isEmpty == OCUPADO)
        {
            cargarDescripcionConfederacion(confederaciones,cantConfederacion,jugador.idConfederacion,descripcion);
            printf("\n ___________________________________________________________________________________________________________________________________\n"
                   "|%-5s|%-20s|%-20s|%-20s|%-20s|%-20s|A%cos de Contrato    |\n"
                   "|=====|====================|====================|====================|====================|====================|====================|\n","ID","Nombre","Posicion","Nro Camiseta","Sueldo","Confederacion",164);
            printf("|%-5d|%-20s|%-20s|%-20hd|%-20.2f|%-20s|%-20hd|\n",jugador.id,jugador.nombre, jugador.posicion, jugador.numeroCamiseta,jugador.salario, descripcion, jugador.aniosContrato);
            printf("|_____|____________________|____________________|____________________|____________________|____________________|____________________|\n\n");
            retorno = 1;
        }
    }
    return retorno;
}

int bajaJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion)
{
    int retorno = -1;
    int idIngresado;
    int indice;
    char confirmar;

    listarJugadores(jugadores,tam,confederaciones,cantConfederacion);
    tomarEntero(&idIngresado, "\nPorfavor ingrese un ID: ", "\nError, Ingrese un ID valido!\n",1000, 4000,10000);

    if(buscarJugadorOcupado(jugadores,tam,idIngresado,&indice))
    {
        if(indice == -1)
        {
            printf("\nNo hay un Jugador con la ID: %d\n", idIngresado);
        }
        else
        {
            mostrarUnJugador(jugadores[indice], confederaciones, cantConfederacion);
            confirmar = confirmarProcedimiento("\nConfirma la baja [s|n]: ");
            if(!confirmar)
            {
                retorno = 0;
            }
            else
            {
                jugadores[indice].isEmpty = VACIO;
                printf("\nBaja realizada con el exito!!!\n");
                retorno = 1;
            }
        }
    }
    else
    {
        printf("\n\nOcurrio un problema al buscar el Jugador!\n");
    }
    return retorno;
}

int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion)
{
    int retorno = 0;
    int idIngresado;
    int indice;
    int opcion;
    int idPosicion;
    int numeroCamiseta;
    int contrato;
    char descripcionPosicion[50];
    int validarModificacion;
    char salir = 'n';

    if(jugadores != NULL && tam > 0 && confederaciones != NULL && cantConfederacion > 0)
    {
        listarJugadores(jugadores,tam,confederaciones,cantConfederacion);
        tomarEntero(&idIngresado, "\nPorfavor ingrese un ID: ", "\nError, Ingrese un ID valido!\n",1000, 4000,10000);

        if(buscarJugadorOcupado(jugadores,tam,idIngresado,&indice))
        {
            if(indice == -1)
            {
                printf("\nNo hay un Jugador con la ID: %d\n", idIngresado);
            }
            else
            {
                mostrarUnJugador(jugadores[indice],confederaciones,cantConfederacion);
                validarModificacion = confirmarProcedimiento("\nConfirma la modificacion de este jugador?[s|n]: ");

                if(validarModificacion)
                {
                    do
                    {
                        menuModificacion();
                        ingresarOpcion(&opcion,"ingrese una ID valida: ");
                        switch(opcion)
                        {
                        case 1:
                            tomarCadena(jugadores[indice].nombre,50,"\nPorfavor, ingrese el nombre del Jugador: ","\nError, ingrese al menos una letra y ningun numero!\n",1000);
                            fflush(stdin);//vaciamos la entrada standard
                            break;
                        case 2:
                            menuPosicion();
                            tomarEntero(&idPosicion,"\nIngrese el ID de una posicion: ","\nError, vuelva a ingresar el ID de una posicion!\n",1,4,1000);
                            copiarPosicion(descripcionPosicion,idPosicion);
                            strcpy(jugadores[indice].posicion, descripcionPosicion);
                            break;
                        case 3:
                            tomarEntero(&numeroCamiseta,"\nIngrese un numero en la camiseta: ","\nError, vuelva a ingresar el numero de la camiseta!\n",1,99,1000);
                            jugadores[indice].numeroCamiseta = (short)numeroCamiseta;
                            break;
                        case 4:
                            mostrarConfederacion(confederaciones,6);
                            tomarEntero(&jugadores[indice].idConfederacion,"\nIngrese el ID de una confederacion: ","\nError, vuelva a ingresar el ID de una posicion!\n",100,105,1000);
                            break;
                        case 5:
                            tomarFlotante(&jugadores[indice].salario, "\nIngrese un monto del salario: ","\nError, vuelva a ingresar el monto del salario!\n",1,100000000,1000);
                            break;
                        case 6:
                            tomarEntero(&contrato,"\nIngrese la cantidad de tiempo por contrato [1 a 10]: ","\nError, vuelva a ingresar la cantidad de tiempo por contrato!\n",1,10,1000);
                            jugadores[indice].aniosContrato = (short)contrato;
                            break;
                        case 7:
                            salir = 's';
                            retorno = 1;
                            break;
                        default:
                            printf("\nError, ingrese una opcion valida!\n");
                            break;
                        }
                    }
                    while(salir != 's');
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }
    }
    return retorno;
}

