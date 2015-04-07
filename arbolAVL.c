#include "arbolAVL.h"

void insertarNodo(Nodo** cabeza,Tipodato d, int* altura)
{
    Nodo* aux1;

    if( !(*cabeza))
    {
        *cabeza = crearNodo(d);
        *altura = 1;
       /* printf ("Estoy creando el primer nodo %i \n", (*cabeza)->dato );*/

    }else
    {

    if(d < (*cabeza) -> dato){
       /* printf("Estoy en el nodo izquierdo %i \n",(*cabeza)->dato);*/
        insertarNodo( &((*cabeza) -> izq), d, altura);
            if(*altura)
            {
                switch((*cabeza) -> fe)
                {
                case 1:
                    (*cabeza) -> fe = 0;
                    (*altura) = 0;
                    break;
                case 0:
                    (*cabeza) -> fe = -1;
                    break;
                case -1:
                    aux1= (*cabeza) -> izq;
                    if(aux1 -> fe <=0){
                     //   printf("Rotacion en II\n");
                        rotacionII(cabeza,aux1);
                    }else{
                      //  printf("Rotacion en ID \n");
                        rotacionID(cabeza,aux1);
                        }
                    (*altura)=0;
                    break;
                }

            }
        }else if(d > (*cabeza) -> dato)
        {
           /* printf("Estoy en el nodo derecho %i \n",(*cabeza)->dato);*/
            insertarNodo(&((*cabeza) -> der),d, altura);

            if((*altura)==1)
            {

                switch((*cabeza) -> fe)
            {
            case 1:
                aux1=(*cabeza) -> der;
                if(aux1 -> fe >= 0){
                  //  printf("Rotacion en DD \n");
                    rotacionDD( cabeza , aux1);
                }else{
                  //  printf("Rotacion en DI \n");
                    rotacionDI( cabeza ,aux1);
                    }
                (*altura)=0;
                break;
            case 0:
                (*cabeza) -> fe= +1;
                break;
            case -1:
                (*cabeza) -> fe = 0;
                (*altura)=0;
                break;

            }
        }
    }else{

        (*altura)=0;
        }
    }
}

Nodo* crearNodo(Tipodato clave)
{
    Nodo* nuevo;
    nuevo= (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato=clave;
    nuevo -> izq= nuevo -> der= NULL;
    nuevo -> fe=0;
    return nuevo;
}

Nodo* crearNodoLista(Tipodato clave)
{
    Nodo* nuevo;
    nuevo= (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato= clave;
    nuevo->der=NULL;
    return nuevo;
}

void insertarCrearNodoLista(Nodo** cabeza, Tipodato clave)
{
    if(!(*cabeza))
    {
    *cabeza=crearNodoLista(clave);
    }
    else
    {
    Nodo* nuevo;
    nuevo= (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato=clave;
    nuevo->der= (*cabeza);
    *cabeza= nuevo;
    }
}


//ROTACIONES

void rotacionDD(Nodo **n, Nodo *n1)
{
    (*n)->der= n1->izq;
    n1->izq=(*n);

   /* if(n1->fe==+1)
    {
        (*n)->fe=0;
        n1->fe=0;
    }else{
        (*n)->fe=+1;
        n1->fe=-1;
    }*/
    (*n)->fe=0;
    (*n)=n1;
}

void rotacionII(Nodo **n, Nodo *n1)
{
    (*n)->izq= n1->der;
    n1->der=(*n);
    (*n)->fe=0;
       /* if(n1->fe==-1)
        {
            (*n)->fe=0;
            n1->fe=0;
        }else{
            (*n)->fe=-1;
            n1->fe=1;
        }*/
        (*n)=n1;
}


void rotacionID(Nodo **n, Nodo *n1)
{
    Nodo* n2;
    n2=n1->der;
    (*n)->izq= n2->der;
    n2->der=(*n);
    n1->der= n2->izq;
    n2->izq=n1;

        if(n2->fe==-1)
            (*n)->fe=+1;
        else
            (*n)->fe=0;

        if(n2->fe==1)
           n1->fe=-1;
        else
            n1->fe=0;

    (*n)=n2;
    (*n)->fe=0;
}

void rotacionDI(Nodo **n, Nodo *n1)
{
    Nodo* n2;

    n2=n1->izq;
    (*n)->der=n2->izq;
    n2->izq=(*n);
    n1->izq=n2->der;
    n2->der=n1;

        if(n2->fe==+1)
            (*n)->fe=-1;
        else
            (*n)->fe=0;

        if(n2->fe==-1)
            n1->fe=1;
        else
            n1->fe=0;

        (*n)=n2;
        (*n)->fe=0;
}

void recorrerEnOrden(Nodo *raiz)
{
    if(raiz)
    {
        recorrerEnOrden(raiz -> izq);
        printf("%d  ", raiz -> dato);
        archivoDOT(raiz);
        recorrerEnOrden(raiz -> der);
    }
}

void archivoDOT(Nodo *raiz)
{
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"\"%s %d\" %s %d %s \n","node",raiz->dato,"[label=\"<f0> | <f1>",raiz->dato," | <f2>\"];");
    fclose(f);
    if(raiz -> izq){
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"\"%s %d\" %s %d %s \n","node",raiz->izq->dato,"[label=\"<f0> | <f1>",raiz->izq->dato," | <f2>\"];");
    fclose(f);
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f,"\"%s %d\" %s %d %s \n","node",raiz->dato,"[label=\"<f0> | <f1>",raiz->dato," | <f2>\"];");
    fclose(f);
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f, "\"%s %d\" %s %d\" %s \n","node",raiz->dato,":f0 -> \"node",raiz->izq->dato,":f1;");
    fclose(f);
    }
    if(raiz -> der){
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f, "\"%s %d\" %s %d %s \n","node",raiz->der->dato,"[label=\"<f0> | <f1>",raiz->der->dato," | <f2>\"];");
    fclose(f);
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f, "\"%s %d\" %s %d %s \n","node",raiz->dato,"[label=\"<f0> | <f1>",raiz->dato," | <f2>\"];");
    fclose(f);
    f= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/graficaAVL.dot","a+");
    fprintf(f, "\"%s %d\" %s %d\" %s \n","node",raiz->dato,":f2 -> \"node",raiz->der->dato,":f1;");
    fclose(f);
    }

}

void graficoTiempoInsercion(double valorX, double valorY) /*valor en x es Tiempo, valor en y es Numero de Nodo*/
{
    int i;
    int NUM_GRAPH=2;

    char *comandoGnuPlot[]={"set title \"Insercion del Arbol\"", "plot 'Insercion.temp' with linespoints ls 1 \n"};
    double xVal[]={valorX};
    double yVal[]={valorY};


    FILE * temp = fopen("Insercion.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#009E60' lt 1 lw 2 pt 7 ps 1.5 # --- green");

    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i]);
    }

   /*    for(i=0;i< valorX ; i++ )
    {
        for(j=1; j<valorY; j++)
        {
             fprintf(temp, "%lf %lf \n", i, j);
        }
    }*/


     for (i=0; i < NUM_COMMANDSI; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }




}

void graficoTiempoRecorrido(double valorX, double valorY)
{
    int i;
    int NUM_GRAPH=2;

    char *comandoGnuPlot[]={"set title \"Insercion del Arbol\"", "plot 'recorrido.temp' with linespoints ls 1 \n"};
    double xVal[]={valorX};
    double yVal[]={valorY};


    FILE * temp = fopen("recorrido.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#1A3349' lt 1 lw 2 pt 7 ps 1.5 # --- green");

    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i]);
    }

     for (i=0; i < NUM_COMMANDSR; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }


}
void graficoTiempoBurbuja(double valorX, double valorY)
{
    BB= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/burbuja.txt","a+");
    fprintf(BB,"set xlabel 'Tiempo (s)'\nset ylabel 'No. Nodos'\nset xrange[-%lf:%lf]\nset yrange[-%lf:%lf]\n plot x**2-2*x+1 title 'O(n^2) Ordenamiento Burbuja'", valorX,valorX, valorY,valorY);
    fclose(BB);

}
void graficoTiempoQuicksort(double valorX, double valorY)
{
    BB= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/quicksort.txt","a+");
    fprintf(BB,"set xlabel 'Tiempo (s)'\nset ylabel 'No. Nodos'\nset xrange[-%lf:%lf]\nset yrange[-%lf:%lf]\n plot log10(x) /log10(2) title 'Ordenaci�n Quicksort O(nlog2n)'", valorX,valorX, valorY,valorY, valorY);
    fclose(BB);
}

void graficoMinimoComparaciones(double noNodos)
{
    int i;
    int NUM_GRAPH=2;
    int total;

    total=noNodos-1;

    char *comandoGnuPlot[]={"set title \"Comparacion Minima\"", "plot 'Cmin.temp' with linespoints ls 1 \n"};
    double yVal[]={noNodos};
    double xVal[]={total};

    FILE * temp = fopen("Cmin.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#483D8B' lt 1 lw 2 pt 7 ps 1.5 # --- DarkSlateBlue");

    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i] );
    }

     for (i=0; i < NUM_COMMANDSR; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }

}

void graficoMovimientosMinimos(double noNodos)
{
    int i;
    int NUM_GRAPH=2;
    int total;

    total=(2*(noNodos-1));

    char *comandoGnuPlot[]={"set title \"Comparacion Minima\"", "plot 'movMin.temp' with linespoints ls 1 \n"};
    double yVal[]={noNodos};
    double xVal[]={total};

    FILE * temp = fopen("movMin.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#DB7093' lt 1 lw 2 pt 7 ps 1.5 # --- PaleVioletRed");


    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i] );
    }

     for (i=0; i < NUM_COMMANDSR; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }

}

void graficoTiempoVRSBurbuja()//double tiempo, double noNodos) //tiempo es en x y noNodos en y
{
  FILE *gp;
  gp = popen(GNUPLOT_PATH, "w");
     if(gp == NULL){
       fprintf(stderr, "Oops, I can't find %s.", GNUPLOT_PATH);
       exit(EXIT_FAILURE);
       }
  fprintf(gp, "set term aqua title \"Function A\" \n");
  fprintf(gp, "set samples 2048 \n");
  fprintf(gp, "plot [-512:512] -abs(x*sin(sqrt(abs(x))))+400");
  fflush(gp); /* Don't forget to flush the buffer.
     getchar();*/
  pclose(gp);
  return(EXIT_SUCCESS);
}



void quickSort(int lista[], int n)
{
    qs(lista,0,n-1);
}
void qs(int lista[], int izq, int der)
{
    int i=0, j=0;
    int x=0, aux=0;
    i=izq;
    j=der;
    x= lista[(izq+der)/2];

        do{
            while(lista[i] < x && j<=der) {i++;}
            while(x<lista[j] && j>izq) {j--;}
            if(i <=j)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
                i++;
                j--;
            }
        }while(i<=j);
        if(izq < j)
        {qs(lista, izq, j);}
        if(i < der)
        {qs(lista, i, der);}

}

void ordenamientoQuicksort(int numeroNodos)
{
FILE *archivo;
 char lectura[100];
 int arreglo[numeroNodos];
 int i,j,k;
 k=0;
 int temp=0;

     archivo= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/Datos.txt","r"); //Archivo para leer

    if(archivo == NULL)
        exit(1);


    while(feof(archivo)==0) //Leer el archivo .txt
    {
        fgets(lectura, 100, archivo);
        int numero=atoi(lectura);
        arreglo[k]=numero; //Guardar los elementos en un arreglo, dependiendo del numero de nodos que entren al arbol
        k++;
    }
    fclose(archivo);

    int tamano=sizeof(arreglo)/sizeof(int);
    quickSort(arreglo,tamano);

    printf("Los valores ORDENADOS POR QUICKSORT: \n");
    for( i=0; i< tamano; i++)
    {
        printf("%d", arreglo[i]);
            if(i< tamano-1)
                printf(",");
    }

}

void ordenamientoBurbuja(int numeroNodos) //Numero de nodos que ingresaron al arbol
{
 FILE *archivo;
 char lectura[100];
 int arreglo[numeroNodos];
 int i,j,k;
 k=0;
 int temp=0;

     archivo= fopen("C:/Users/Destroy the time/Desktop/C/practica2_EDDAVL/Datos.txt","r"); //Archivo para leer

    if(archivo == NULL)
        exit(1);


    while(feof(archivo)==0) //Leer el archivo .txt
    {
        fgets(lectura, 100, archivo);
        int numero=atoi(lectura);
        arreglo[k]=numero; //Guardar los elementos en un arreglo, dependiendo del numero de nodos que entren al arbol
        k++;
    }
    fclose(archivo);

        for(i=1; i<numeroNodos;i++)
        {
            for(j=0;j<=numeroNodos-1;j++)
            {
                if(arreglo[j]>arreglo[j+1])
                {
                    temp=arreglo[j];
                   //printf("numero: %d", temp);
                    arreglo[j]=arreglo[j+1];
                    arreglo[j+1]=temp;
                }
            }
        }

    printf("Los valores ORDENADOS CON BURBUJA\n");
    for(i=0; i<numeroNodos; i++)
    {
        printf("%3d", arreglo[i]);
    }
}

