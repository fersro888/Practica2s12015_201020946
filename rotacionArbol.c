void rotacionDD(Nodo **n, Nodo *n1)
{
    (*n)->der= n1->izq;
     n1->izq=(*n);
    (*n)->fe=0;
    (*n)=n1;
}

void rotacionII(Nodo **n, Nodo *n1)
{
    (*n)->izq= n1->der;
    n1->der=(*n);
    (*n)->fe=0;
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
