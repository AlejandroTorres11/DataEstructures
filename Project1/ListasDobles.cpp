#include "ListasDobles.hpp"

using namespace std;

ListasDobles::~ListasDobles()
{
    NodoLDobles *aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
        fin=NULL;
}

void ListasDobles::insertarNodo(Reserva v, char c)
{
    NodoLDobles *aux;
    char tipoInsercion;
    tipoInsercion=c;

    if(listaVacia()) { // Si la lista está vacía
        aux = new NodoLDobles(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else if (tipoInsercion=='f') {//Inserción por el final
        aux= new NodoLDobles(v,NULL,NULL);
        aux->anterior=fin;
        fin->siguiente=aux;
        fin=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new NodoLDobles(v,NULL,NULL);
        aux->siguiente=cabeza;
        cabeza->anterior=aux;
        cabeza=aux;
    }
}
/*
void ListasDobles::insertarNodoIntAntes(Reserva v, int posicion)
{
    NodoLDobles *aux;

    if(listaVacia()) { // Si la lista está vacía
        aux = new NodoLDobles(v,NULL,NULL);
        fin=cabeza=aux;
    }
    else   //Inserción antes del nodo
    {   actual=cabeza;
        while(actual)
        {
            if (actual->valor != posicion) actual = actual->siguiente; // Crear funcion esIgual con Reservas
            else
            {
                aux= new NodoLDobles(v,NULL,NULL);
                aux->siguiente=actual;
                aux->anterior=actual->anterior;
                actual->anterior->siguiente=aux;
                actual->anterior=aux;
                actual = actual->siguiente; //mueve actual para que salga del while.
           }
        }
    }

}
*/
void ListasDobles::borrarNodo(Reserva v,char c)
{
    char tipoBorrado;
    tipoBorrado=c;

    if(tipoBorrado=='f') {//Eliminación por el final
        NodoLDobles *aux=NULL;
        if((cabeza==fin)) { //Sólo hay elemento
            aux=fin;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=fin;
            fin=fin->anterior;
            aux->anterior=NULL;  //añado yo según transparencias
            fin->siguiente=NULL;
            delete aux;
        }
    }
    else if(tipoBorrado=='p') {//Eliminación por el Principio
        NodoLDobles *aux=NULL;
        if((cabeza==fin)) {//Sólo hay elemento
            aux=cabeza;
            cabeza = fin = NULL;
            aux=NULL;
            delete aux;
        }
        else {
            aux=cabeza;
            cabeza=cabeza->siguiente;
            aux->siguiente=NULL;  //añado yo según transparencias
            cabeza->anterior=NULL;
            delete aux;
        }
    }
}

void ListasDobles::mostrarLista (int orden)
{
    NodoLDobles *aux;

    if (orden == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        while(aux) {
            cout << aux->valor.toString() << "-> "; aux = aux->siguiente;
        }
    }
    else {
        esUltimo();
        aux = fin;
        while(aux) {
            cout << aux->valor.toString() << "-> "; aux = aux->anterior;
        }
    }
    cout << endl;
}

bool ListasDobles::listaVacia()
{
    return cabeza == NULL;
}

void ListasDobles::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

void ListasDobles::esAnterior()
{
    if(actual) actual = actual->anterior;
}

void ListasDobles::esPrimero()
{
    actual=cabeza;
}

void ListasDobles::esUltimo()
{
    actual=fin;
}

bool ListasDobles::esActual()
{
    return actual != NULL;
}

Reserva ListasDobles::valorActual()
{
    if (!listaVacia()) return actual->valor;
     else return Reserva();
}


void ListasDobles::generarReservas() {
    int n;
    cout << "¿Cuantas reservas quieres hacer?: ";
    cin >> n;
    srand(static_cast<unsigned>(time(0)));
    string listaNombres[] = {"David", "Alejandro", "Juan", "Pedro", "Sandra", "Maria", "Alejandra", "Silvia", "Jose", "Vanesa", "Ana", "Patricia", "Fernando", "Manuel", "Luis", "Elena", "Carlos", "Carmen", "Lorena", "Roberto", "Rosa", "Laura", "Javier", "Isabel", "Antonio", "Eduardo", "Marta", "Raul", "Lucia", "Diego", "Veronica", "Sergio", "Monica", "Andres", "Beatriz", "Miguel", "Maria Jose", "Pablo", "Victoria", "Ricardo", "Natalia", "Hector", "Valentina", "Gonzalo", "Camila", "Rene", "Paola", "Hugo", "Diana"};
    for (int i = 0; i < n; ++i) {
        Reserva reserva;
        reserva.numReserva = i+1    ;
        reserva.numPersonas = rand() % 8 + 1;
        reserva.cliente = listaNombres[(rand() % 45)];
        reserva.hora = (i < 4) ? "13:00" : ((i < 8) ? "14:00" : "15:00");
        reserva.situacionMesa = (rand() % 2 == 0) ? "Terraza" : "Interior";
        reserva.preferenciaMenu = (rand() % 3 == 0) ? "vegano" : ((rand() % 2 == 0) ? "sin Gluten" : "completo");
        cout << reserva.toString();

        insertarNodo(reserva,'p');
    }
    cout << "Reservas creadas existosamente.\n";
}


void ListasDobles::vaciarLista(){
    NodoLDobles *aux;
    esPrimero();
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
        cabeza=NULL;
        actual=NULL;
        fin=NULL;
}
