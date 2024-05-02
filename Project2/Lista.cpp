#include "Lista.hpp"

using namespace std;

Lista::~Lista()
{
    NodoLista* aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

void Lista::insertarNodo(Pedido &v) {
    NodoLista* aux;

    if (listaVacia())
    {
        cabeza = new NodoLista(v, NULL);
        fin=cabeza;
    }
    else
    {
        aux= new NodoLista(v,NULL);
        fin->siguiente=aux;
        fin=aux;
    }
}

void Lista::insertarNodoIntermedio(Pedido v, int posicion) {
    NodoLista* aux;

    aux= new NodoLista(v,NULL);

    if (listaVacia())
    {
        cabeza = new NodoLista(v, NULL);
        fin=cabeza;
    }
    else
    {   actual=cabeza;
        while(actual)
        {
            if (actual->valor.reserva.numReserva != posicion) actual = actual->siguiente; // HAY QUE REVISAR COMO SE HACE LA ORDENACION AQUI
            else
            {
                aux->siguiente=actual->siguiente;
                actual->siguiente=aux;

                actual = actual->siguiente; //mueve actual para que salga del while.
            }
        }
    }
}

void Lista::borrarNodo(Pedido v) {
    NodoLista* anterior;

    actual = cabeza;

    while ((!actual->valor.esIgual(v)) && (actual->siguiente!=NULL)) // !actual->valor.esIgual(v)
    {
        anterior=actual;
        actual=actual->siguiente;
    }

    if (actual==cabeza) // Primer elemento
        cabeza = actual->siguiente;
    else
    {
        anterior->siguiente = actual->siguiente;
        if (actual==fin) // HAY QUE CREAR UNA FUNCION DE COMPARACION DE NODOSLISTA
        {
            fin=anterior;
        }
    }
    actual->siguiente=NULL;
    delete actual;
}

bool Lista::listaVacia(){
    return cabeza == NULL;
}

void Lista::mostrarLista()
{
    //Nodo *aux;
    NodoLista* aux;
    aux = cabeza;

    while(aux)
    {
        cout << "\n-> ";
        cout << aux->valor.toString();
        aux = aux->siguiente;
    }
    cout << endl;
}

void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void Lista::esPrimero()
{
    actual = cabeza;
}


void Lista::esFinal()
{
    esPrimero();
    if(!listaVacia())
    while(actual->siguiente)
    esSiguiente();
}

bool Lista::esActual()
{
    return actual != NULL;
}

Pedido Lista::valorActual()
{
    return actual->valor;
}

int Lista::contarElementos() {
    NodoLista* aux = cabeza;
    int resultado = 0;

    // Verificar si la lista está vacía
    if (listaVacia()) {
        return resultado;
    }

    // Contar elementos mientras haya nodos
    while (aux) {
        resultado++;
        if (aux->siguiente) {
            aux = aux->siguiente;
        } else {
            break;  // Salir del bucle si no hay un siguiente nodo
        }
    }

    return resultado;
}


