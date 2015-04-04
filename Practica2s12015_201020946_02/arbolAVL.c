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
                    if(aux1 -> fe == -1){
                       // printf("Rotacion en II\n");
                        rotacionII(cabeza,aux1);
                    }else{
                       // printf("Rotacion en ID \n");
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

            if(*altura)
            {

                switch((*cabeza) -> fe)
            {
            case 1:
                aux1=(*cabeza) -> der;
                if(aux1 -> fe == +1){
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

    if(n1->fe==+1)
    {
        (*n)->fe=0;
        n1->fe=0;
    }else{
        (*n)->fe=+1;
        n1->fe=-1;
    }
    (*n)=n1;
}

void rotacionII(Nodo **n, Nodo *n1)
{
    (*n)->izq= n1->der;
    n1->der=(*n);
        if(n1->fe==-1)
        {
            (*n)->fe=0;
            n1->fe=0;
        }else{
            (*n)->fe=-1;
            n1->fe=1;
        }
        (*n)=n1;
}


void rotacionID(Nodo **n, Nodo *n1)
{
    Nodo* n2;
    n2=n1->der;
    (*n)->izq= n2->der;
    n2->der=*n;
    n1->der= n2->izq;
    n2->izq=n1;

        if(n2->fe==+1)
            n1->fe=-1;
        else
            n1->fe=0;

    n2->fe=0;
    (*n)=n2;

}

void rotacionDI(Nodo **n, Nodo *n1)
{
    Nodo* n2;

    n2=n1->izq;
    (*n)->der=n2->izq;
    n2->izq=*n;
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

        n2->fe=0;
        (*n)=n2;
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
    int i;
    int NUM_GRAPH=2;

    char *comandoGnuPlot[]={"set title \"Insercion del Arbol\"", "plot 'ordenamientoBurbuja.temp' with linespoints ls 1 \n"};
    double xVal[]={valorX};
    double yVal[]={valorY};


    FILE * temp = fopen("ordenamientoBurbuja.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#989AA3' lt 1 lw 2 pt 7 ps 1.5 # --- green");

    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i]);
    }

     for (i=0; i < NUM_COMMANDSB; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }


}
void graficoTiempoQuicksort(double valorX, double valorY)
{
    int i;
    int NUM_GRAPH=2;

    char *comandoGnuPlot[]={"set title \"Insercion del Arbol\"", "plot 'OrdenamientoQuicksort.temp' with linespoints ls 1 \n"};
    double xVal[]={valorX};
    double yVal[]={valorY};


    FILE * temp = fopen("OrdenamientoQuicksort.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persist", "w");

    fprintf(gnuplotPipe, "set style line 1 lc rgb '#5A392E' lt 1 lw 2 pt 7 ps 1.5 # --- green");

    for (i=0; i < NUM_GRAPH; i++)
    {
    fprintf(temp, "%lf %lf \n", xVal[i], yVal[i]);
    }

     for (i=0; i < NUM_COMMANDSQ; i++)
     {
     fprintf(gnuplotPipe, "%s \n", comandoGnuPlot[i]); // Enviar los comandos para gnuplot uno a uno.
     }


}


