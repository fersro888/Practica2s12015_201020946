#include <stdio.h>
#include <stdlib.h>
#include "arbolAVL.h"




int main()
{
    Nodo *raiz;
    raiz = NULL;
    int altura;
    FILE *archivo;
    char lectura[100];

    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"%s\n","digraph g{ \nnode [shape=record, height=.1];");
    fclose(f);
    /*Aqui leer archivos.txt y enviarlos a la funcion insertarNodo, pruebas*/
    /*insertarNodo(&raiz,6,&altura);
    insertarNodo(&raiz,5,&altura);
    insertarNodo(&raiz,7,&altura);
    insertarNodo(&raiz,4,&altura);
    insertarNodo(&raiz,8,&altura);
    */
    archivo= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/Datos.txt","r");

    if(archivo == NULL)
        exit(1);
    while (feof(archivo) == 0) /*hasta que sea fin de linea*/
    {
        fgets(lectura, 100, archivo);
        printf("Entrando %s", lectura);
        int numero=atoi(lectura); /*casteo con atoi el string que viene a int*/
        insertarNodo(&raiz, numero, &altura);
    }
    fclose(archivo);

    recorrerEnOrden(raiz);

    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"%s\n","}");
    fclose(f);

    free(raiz);
}

