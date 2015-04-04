#include <stdio.h>
#include <stdlib.h>
#include "arbolAVL.h"
#include "ListaSimple.h"
#include <time.h>


int main()
{
    Nodo *raiz;
    NODOLISTA *listaInicial, *listaInicialOQ;
    NODOLISTA *listaFinal, *listaFinalOQ;
    raiz = NULL;
    listaInicial= NULL;
    listaFinal= NULL;
    listaInicialOQ=NULL;
    listaFinalOQ=NULL;
    int altura;
    double numeroNodos=0;
    int contadorLista=0;
    FILE *archivo;
    char lectura[100];

    //INSERCION DEL ARBOL
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"%s\n","digraph g{ \nnode [shape=record, height=.1];");
    fclose(f);

    archivo= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/Datos.txt","r"); /*Archivo para leer*/

    if(archivo == NULL)
        exit(1);
    clock_t inicioInsercionI, inicioInsercionF ;
    inicioInsercionI=clock(); /*Tiempo de inicio de insercion del arbol*/
    while (feof(archivo) == 0) /*hasta que sea fin de linea*/
    {

        fgets(lectura, 100, archivo);
       /* printf("Entrando %s", lectura);*/
        int numero=atoi(lectura); /*casteo con atoi el string que viene a int*/
        insertarNodo(&raiz, numero, &altura);  /*Creando arbol AVL*/
        insertarLS(&listaInicial, &listaFinal, numero,contadorLista); //crear una lista para ordenamiento Burbuja
        insertarLS(&listaInicialOQ, &listaFinalOQ, numero,contadorLista); //Crear una lista para ordenamiento Quicksort
        numeroNodos++;
        contadorLista++;
    }
    inicioInsercionF=clock();
    printf("\nInsercion del arbol:  %f segundos \n", (double)(inicioInsercionF)/CLOCKS_PER_SEC); /*Tiempo final de insercion*/
    graficoTiempoInsercion(((double)(inicioInsercionF)/CLOCKS_PER_SEC), numeroNodos);
    fclose(archivo);
    //--------------------------
    //RECORRIDO ARBOL
    printf("\nRECORRIDO INORDEN: \n");
    clock_t inicioRecorridoI,inicioRecorridoF ;
    inicioRecorridoI= clock(); /*Tiempo de inicio para recorrer el arbol enOrden*/
    recorrerEnOrden(raiz); /*Recorrer el arbol y generar el .DOT*/
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"%s\n","}");
    inicioRecorridoF= clock();
    printf("\nRecorrido del arbol: %f segundos \n", (double)(inicioRecorridoF)/CLOCKS_PER_SEC); /*Tiempo final de recorrido*/
    graficoTiempoRecorrido(((double)(inicioRecorridoF)/CLOCKS_PER_SEC), numeroNodos);
    fclose(f);
    //---------------------------
    //IMPRIMIR LISTA
    printf("\nLISTA DESORDENADA:\n");
    imprimirLista(&listaInicial);
    //---------------------------
    //ORDENAMIENTO BURBUJA
    clock_t inicioOrdenamientoBurbujaI,inicioOrdenamientoBurbujaF;
    inicioOrdenamientoBurbujaI= clock(); /*Tiempo de inicio para el ordenamiento en burbuja*/
    ordenamientoBurbujaLS(&listaInicial); /*Ordenamiento de burbuja*/
    printf("\nORDENAMIENTO BURBUJA:\n");
    imprimirLista(&listaInicial);
    inicioOrdenamientoBurbujaF= clock();
    printf("\nOrdenamiento Burbuja: %f segundos \n", (double)(inicioOrdenamientoBurbujaF)/CLOCKS_PER_SEC); /*Tiempo final de recorrido*/
    graficoTiempoBurbuja(((double)(inicioOrdenamientoBurbujaF)/CLOCKS_PER_SEC), numeroNodos);
    //---------------------------
    //ORDENAMIENTO QUICKSORT
    clock_t inicioOrdenamientoQuickSortI,inicioOrdenamientoQuickSortF;
    inicioOrdenamientoQuickSortI= clock();
    ordenamientoQuicksortLS(&listaInicialOQ, &listaFinalOQ, (listaInicialOQ)->posicionOQ, (listaFinalOQ)->posicionOQ); /*Ordenamiento Quicksort*/
    printf("\nORDENAMIENTO QUICKSORT:\n");
    imprimirLista(&listaInicialOQ);
    inicioOrdenamientoQuickSortF= clock();
    printf("\nOrdenamiento Quicksort: %f segundos \n", (double)(inicioOrdenamientoQuickSortF)/CLOCKS_PER_SEC);
    graficoTiempoQuicksort(((double)(inicioOrdenamientoQuickSortF)/CLOCKS_PER_SEC), numeroNodos);
    //---------------------------

    free(raiz);
    free(listaInicial);
    free(listaFinal);
    free(listaInicialOQ);
    free(listaFinalOQ);

}

