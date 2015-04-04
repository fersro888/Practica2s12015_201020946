#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int clave;
    int posicionOQ; /*Servira para el ordenamiento Quicksort*/
    int pararOB;    /*Servira para el ordenamiento Burbuja*/
    struct lista *siguiente;
    struct lista *anterior; /*Apuntadores de la lista*/

}NODOLISTA;

void insertarLS(NODOLISTA **cabeza, NODOLISTA **cola, int clave, int posicion);
void imprimirLista(NODOLISTA **cabeza);
void ordenamientoBurbujaLS(NODOLISTA **cabeza);
void ordenamientoQuicksortLS(NODOLISTA **cabeza, NODOLISTA **cola, int primero, int ultimo);
NODOLISTA* listaIzquierda(NODOLISTA **cabeza,int posicion);
NODOLISTA* listaDerecha(NODOLISTA **cola,int posicion);
#endif // LISTASIMPLE_H_INCLUDED
