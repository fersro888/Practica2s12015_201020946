#include "ListaSimple.h"

void insertarLS(NODOLISTA **cabeza, NODOLISTA **cola, int clave, int posicion)
{
    NODOLISTA *nuevo =(NODOLISTA*)malloc(sizeof(NODOLISTA));
    nuevo->clave=clave;
    nuevo->posicionOQ=posicion; //servira para el ordenamiento Quicksort
    nuevo->pararOB=0; //servira para el ordenamiento Burbuja
    nuevo->siguiente=NULL;
    nuevo->anterior=NULL;
   // printf("Estoy creando nodo de la lista, %d \n", nuevo->clave);
        if((*cabeza)) //si no esta vacia
        {
            nuevo->anterior=(*cola);  //nuevo nodo apunta a cola(ultimo)
            (*cola)->siguiente=nuevo; //cola(ultimo) siguiente apunta al nuevo
            (*cola)=nuevo; //cola(ultimo) se apuntan asi mismo y por ultimo son iguales
          //  printf("Estoy en el primer if, %d\n", nuevo->clave);
        }
        else
        { //si esta vacia solo se igualan al nuevo nodo
            (*cabeza)=nuevo;
            (*cola)=nuevo;
           // printf("Estoy en el else %d\n", nuevo->clave);
        }

}

void ordenamientoBurbujaLS(NODOLISTA **cabeza)
{
    if((*cabeza)->pararOB == 0 && (*cabeza)) //si la lista no esta vacia y pararOB sea 0
    {
        NODOLISTA *auxiliar=(*cabeza); //este auxiliar tomo toda la cabeza
            while(auxiliar !=NULL)
            {
                if(auxiliar->pararOB !=1)
                {
                    if(auxiliar->siguiente !=NULL)
                    {
                        if((auxiliar->clave)> (auxiliar->siguiente->clave)) //si es mayor se hace el intercambio de claves
                        {
                            int aux1= auxiliar->clave;
                            int aux2= auxiliar->siguiente->clave;
                            auxiliar->clave=aux2;
                            auxiliar->siguiente->clave=aux1;
                           // printf("clave cambiada %d %d \n", auxiliar->clave, auxiliar->siguiente->clave);
                        }
                    }
                    if(auxiliar->siguiente == NULL && auxiliar->pararOB ==0)
                    {
                        auxiliar->pararOB =1; //cambiamos a uno la primer clave
                    }
                    else if(auxiliar->siguiente->pararOB ==1)
                    {
                        auxiliar->pararOB=1; //si no si se cambia la siguiente clave
                    }
                        auxiliar=auxiliar->siguiente; //recorremos al siguiente nodo de nuestra lista
                }
                else //si auxiliar->pararOB ya es igual a 1
                {

                    break; //nos salimos del while
                }
            }
            ordenamientoBurbujaLS(&(*cabeza)); //recorremos nuestra lista, hasta que sea null ó todos tengan un valor 1
    }
}

void ordenamientoQuicksortLS(NODOLISTA **cabeza, NODOLISTA **cola, int primero, int ultimo)
{
    int auxPrimer, auxUltimo, auxMedio;
    int auxCentro;

    auxMedio = (primero+ultimo)/2;
    auxCentro = listaIzquierda(&(*cabeza), auxMedio)->clave;
    auxPrimer = primero;
    auxUltimo = ultimo;

        do
        {
            while(listaIzquierda(&(*cabeza),auxPrimer) -> clave < auxCentro && auxPrimer < ultimo) auxPrimer++; //este while recorre de izquierda a derecha
            while(listaDerecha(&(*cola), auxUltimo) -> clave > auxCentro && auxUltimo > primero) auxUltimo--; //este while recorre de derecha a izquierda
                if(auxPrimer <= auxUltimo)
                {
                    int temporal;
                    temporal= listaIzquierda(&(*cabeza), auxPrimer)->clave;
                    listaIzquierda(&(*cabeza), auxPrimer)->clave=listaDerecha(&(*cola), auxUltimo)->clave;
                    listaDerecha(&(*cola), auxUltimo)->clave=temporal;
                    auxPrimer++;
                    auxUltimo--;
                }
        }while(auxPrimer <= auxUltimo);
         if(primero <auxUltimo)
         {
             ordenamientoQuicksortLS(&(*cabeza), &(*cola), primero,auxUltimo);
         }
         if(auxPrimer < ultimo)
         {
             ordenamientoQuicksortLS(&(*cabeza), &(*cola), auxPrimer, ultimo);
         }
}

NODOLISTA *listaIzquierda(NODOLISTA **cabeza,int posicion)
{
    NODOLISTA *aux1=NULL;
   // printf("debería de ser 0, %d", aux1);
        if((*cabeza))
        {
            NODOLISTA *aux2 =(*cabeza);
            while(aux2!=NULL) //Recorrer
            {
                if(aux2->posicionOQ !=posicion)
                {
                   // printf("valores que vienen aqui %d\n", aux2->clave);
                    aux2=aux2->siguiente; //recorrer el siguiente nodo
                }
                else
                {
                    aux1=aux2;
                    break;
                }
            }
        }
    return aux1;
}

NODOLISTA *listaDerecha(NODOLISTA **cola,int posicion)
{
    NODOLISTA *aux1=NULL;
    if((*cola))
    {
        NODOLISTA *aux2=(*cola);
        while(aux2 != NULL) //recorriendo lista
        {
            if(aux2->posicionOQ != posicion)
            {
                aux2= aux2->anterior;
            }
            else
            {
                aux1= aux2;
                break;
            }
        }
    }
    return aux1;
}

void imprimirLista(NODOLISTA **cabeza)
{
    if((*cabeza)) //si la lista no esta vacia
    {
        NODOLISTA *aux= (*cabeza);
        printf("VALORES:\n");
        while(aux != NULL)
        {
            printf("%i ",aux->clave);
            aux=aux->siguiente;

        }
    }
}
