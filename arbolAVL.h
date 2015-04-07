#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM_COMMANDSI 2
#define NUM_COMMANDSR 2
#define NUM_COMMANDSB 2
#define NUM_COMMANDSQ 2
#define GNUPLOT_PATH "/Program Files (x86)/gnuplot/bin"

typedef int Tipodato;
typedef struct nodo{
    Tipodato dato;
    int fe;
    struct nodo *izq, *der;

}Nodo;


Nodo* crearNodo(Tipodato clave);
Nodo* crearNodoLista(Tipodato clave);
void insertarCrearNodoLista(Nodo** cabeza, Tipodato clave);
void insertarNodo(Nodo** cabeza, Tipodato d, int* altura);
void recorrerEnOrden(Nodo *raiz);
void ordenamientoBurbuja(int numeroNodos);
void ordenamientoQuicksort(int numeroNodos);
void rotacionII(Nodo **n, Nodo *n1);
void rotacionID(Nodo **n, Nodo *n1);
void rotacionDD(Nodo **n, Nodo *n1);
void rotacionDI(Nodo **n, Nodo *n1);
void archivoDOT(Nodo *raiz);
void graficoTiempoInsercion(double valorX, double valorY);
void graphInsercion(double valorX, double valorY);
void graphBurbuja(double valorX, double valorY);
void graphQuicksort(double valorX, double valorY);
void graficoTiempoRecorrido(double valorX, double valorY);
void graficoTiempoBurbuja(double valorX, double valorY);
void graficoTiempoQuicksort(double valorX, double valorY);
void graficoMinimoComparaciones(double noNodos);
void graficoMovimientosMinimos(double noNodos);
void graficoTiempoVRSBurbuja();
FILE *f;
FILE *BB;
FILE *QQ;
FILE *II;
FILE *GB;
FILE *GQ;

#endif // ARBOLAVL_H_INCLUDED
