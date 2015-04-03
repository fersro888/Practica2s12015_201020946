#include <stdio.h>
#include <stdlib.h>
#include "arbolAVL.h"
#include <time.h>


int main()
{
    Nodo *raiz, *lista;
    raiz = NULL;
    lista= NULL;
    int altura;
    double numeroNodos=0;
    FILE *archivo;
    char lectura[100];


  /*  int NUM_GRAPH=5;

    char *comandoGnuPlot[]={"set title \"TITULO\"", "plot 'data.temp' with linespoints ls 1 \n"};
    double xVal[]={1.0,2.0,3.0,4.0,5.0};
    double yVal[]={1.0,3.0,2.0,4.0,5.0};


    FILE * temp = fopen("data.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#009E60' lt 1 lw 2 pt 7 ps 1.5 # --- green");
    int i;
    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i]);
    }

     for (i=0; i < NUM_COMMANDS; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }*/

    clock_t inicioInsercion=clock(); /*Tiempo de inicio de insercion del arbol*/
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"%s\n","digraph g{ \nnode [shape=record, height=.1];");
    fclose(f);

    archivo= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/Datos.txt","r"); /*Archivo para leer*/

    if(archivo == NULL)
        exit(1);


    while (feof(archivo) == 0) /*hasta que sea fin de linea*/
    {

        fgets(lectura, 100, archivo);
       /* printf("Entrando %s", lectura);*/
        int numero=atoi(lectura); /*casteo con atoi el string que viene a int*/
        insertarNodo(&raiz, numero, &altura);  /*Creando arbol AVL*/
        insertarCrearNodoLista(&lista,numero);
        numeroNodos++;
    }

    ordenamientoBurbujaDinamico(lista);

    printf("Insercion del arbol:  %f segundos \n", ((double)clock()- inicioInsercion)/CLOCKS_PER_SEC); /*Tiempo final de insercion*/
    graficoTiempoInsercion((((double)clock()- inicioInsercion)/CLOCKS_PER_SEC), numeroNodos);
    fclose(archivo);

    clock_t inicioRecorrido= clock(); /*Tiempo de inicio para recorrer el arbol enOrden*/
    recorrerEnOrden(raiz); /*Recorrer el arbol y generar el .DOT*/
    printf("Recorrido del arbol: %f segundos \n", ((double)clock()- inicioRecorrido)/CLOCKS_PER_SEC); /*Tiempo final de recorrido*/

    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"%s\n","}");
    graficoTiempoRecorrido((((double)clock()- inicioRecorrido)/CLOCKS_PER_SEC), numeroNodos);
    fclose(f);

    clock_t inicioOrdenamientoQuickSort= clock();
    ordenamientoQuicksort(numeroNodos); /*Ordenamiento Quicksort*/
    printf("\nOrdenamiento Quicksort: %f segundo \n", ((double)clock()- inicioOrdenamientoQuickSort)/CLOCKS_PER_SEC);
    graficoTiempoQuicksort((((double)clock()- inicioOrdenamientoQuickSort)/CLOCKS_PER_SEC), numeroNodos);

    clock_t inicioOrdenamientoBurbuja= clock(); /*Tiempo de inicio para el ordenamiento en burbuja*/
    ordenamientoBurbuja(numeroNodos); /*Ordenamiento de burbuja*/
   /* ordenamientoBurbujaDinamico(lista, numeroNodos);*/
    printf("\nOrdenamiento Burbuja: %f segundos \n", ((double)clock()- inicioOrdenamientoBurbuja)/CLOCKS_PER_SEC); /*Tiempo final de recorrido*/
    graficoTiempoBurbuja((((double)clock()- inicioOrdenamientoBurbuja)/CLOCKS_PER_SEC), numeroNodos);

    free(raiz);

}

