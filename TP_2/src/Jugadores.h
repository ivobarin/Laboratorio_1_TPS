#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include "Confederaciones.h"
#include "Menus.h"
#include "Inputs.h"
#define CANT_CONFEDERACION 6
#define CANT_JUGADOR 3000
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[50];
    char posicion[50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
} eJugador;

int altaJugadores(eJugador jugadores[], int cantJugador, int* pId);
eJugador cargaDatosJugador();
int inicializarJugadores(eJugador vec[], int tam);
int eJugadorBuscarEspacioLibre(eJugador vec[], int tam);
short buscarJugadorLibre(eJugador jugadores[], int cantJugador);
int listarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion);
int buscarJugadorOcupado(eJugador vec[], int tam, int id, int* pIndice);
int mostrarUnJugador(eJugador jugador, eConfederacion confederaciones[],int cantConfederacion);
int bajaJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion);
int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int cantConfederacion);
#endif // JUGADORES_H_INCLUDED
