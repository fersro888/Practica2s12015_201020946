#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Tipodato;
typedef struct nodo{
    Tipodato dato;
    int fe;
    struct nodo *izq, *der;

}Nodo;
Nodo* crearNodo(Tipodato clave);
void insertarNodo(Nodo** cabeza, Tipodato d, int* altura);
void rotacionII(Nodo **n, Nodo *n1);
void rotacionID(Nodo **n, Nodo *n1);
void rotacionDD(Nodo **n, Nodo *n1);
void rotacionDI(Nodo **n, Nodo *n1);
void archivoDOT(Nodo *raiz);
FILE *f;


#endif // ARBOLAVL_H_INCLUDED
