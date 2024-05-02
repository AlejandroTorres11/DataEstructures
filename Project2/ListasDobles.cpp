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
void ListasDobles::borrarNodo(Reserva reserva, char c) {
    char tipoBorrado;
    tipoBorrado = c;

    if (tipoBorrado == 'f') { // Eliminación por el final
        NodoLDobles *aux = NULL;
        if (cabeza == fin) { // Sólo hay un elemento
            aux = fin;
            cabeza = fin = NULL;
            delete aux;
        } else {
            aux = fin;
            fin = fin->anterior;
            aux->anterior = NULL;  // Añado según transparencias
            fin->siguiente = NULL;
            delete aux;
        }
    } else if (tipoBorrado == 'p') { // Eliminación por el Principio
        NodoLDobles *aux = NULL;
        if (cabeza == fin) { // Sólo hay un elemento
            aux = cabeza;
            cabeza = fin = NULL;
            delete aux;
        } else {
            aux = cabeza;
            cabeza = cabeza->siguiente;
            aux->siguiente = NULL;  // Añado según transparencias
            cabeza->anterior = NULL;
            delete aux;
        }
    } else { // Borrado por valor
        NodoLDobles *aux = cabeza;
        NodoLDobles *siguiente;

        while (aux) {
            siguiente = aux->siguiente;

            if (aux->valor.esIgual(reserva)) {
                if (aux->anterior) {
                    aux->anterior->siguiente = aux->siguiente;
                } else {
                    cabeza = aux->siguiente;
                }

                if (aux->siguiente) {
                    aux->siguiente->anterior = aux->anterior;
                } else {
                    fin = aux->anterior;
                }

                delete aux;
            }

            aux = siguiente;
        }
    }
}


    // Función para insertar un nodo en la lista ordenada
void ListasDobles::insertarNodoOrdenado(const Reserva& nuevaReserva) {
        NodoLDobles* nuevoNodo = new NodoLDobles(nuevaReserva);

        // Caso 1: Lista vacía
        if (!cabeza) {
            cabeza = nuevoNodo;
            fin = nuevoNodo;
            return;
        }

        // Comparar por hora, situación y número de comensales
        NodoLDobles* actual = cabeza;
        while (actual) {
            // Comparar hora
            if (nuevaReserva.hora < actual->valor.hora) {
                // Insertar antes del actual
                nuevoNodo->siguiente = actual;
                nuevoNodo->anterior = actual->anterior;

                if (actual->anterior) {
                    actual->anterior->siguiente = nuevoNodo;
                } else {
                    cabeza = nuevoNodo;
                }

                actual->anterior = nuevoNodo;
                return;
            } else if (nuevaReserva.hora == actual->valor.hora) {
                // Si la hora es la misma, comparar por situación
                if (nuevaReserva.situacionMesa < actual->valor.situacionMesa) {
                    // Insertar antes del actual
                    nuevoNodo->siguiente = actual;
                    nuevoNodo->anterior = actual->anterior;

                    if (actual->anterior) {
                        actual->anterior->siguiente = nuevoNodo;
                    } else {
                        cabeza = nuevoNodo;
                    }

                    actual->anterior = nuevoNodo;
                    return;
                } else if (nuevaReserva.situacionMesa == actual->valor.situacionMesa) {
                    // Si la situación es la misma, comparar por número de comensales
                    if (nuevaReserva.numPersonas < actual->valor.numPersonas) {
                        // Insertar antes del actual
                        nuevoNodo->siguiente = actual;
                        nuevoNodo->anterior = actual->anterior;

                        if (actual->anterior) {
                            actual->anterior->siguiente = nuevoNodo;
                        } else {
                            cabeza = nuevoNodo;
                        }

                        actual->anterior = nuevoNodo;
                        return;
                    }
                }
            }

            // Mover al siguiente nodo
            actual = actual->siguiente;
        }

        // Si llegamos aquí, la nueva reserva es la más grande, la agregamos al final
        fin->siguiente = nuevoNodo;
        nuevoNodo->anterior = fin;
        fin = nuevoNodo;

    }
void ListasDobles::mostrarLista (int orden)
{
    if (!listaVacia()){
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
    } else {

        cout << "\nLa lista doble de reservas esta vacia.\n";
    }
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
    int x = i+n;

    srand(static_cast<unsigned>(time(0)));
    string listaNombres[] = {"David", "Alejandro", "Juan", "Pedro", "Sandra", "Maria", "Alejandra", "Silvia", "Jose", "Vanesa", "Ana", "Patricia", "Fernando", "Manuel", "Luis", "Elena", "Carlos", "Carmen", "Lorena", "Roberto", "Rosa", "Laura", "Javier", "Isabel", "Antonio", "Eduardo", "Marta", "Raul", "Lucia", "Diego", "Veronica", "Sergio", "Monica", "Andres", "Beatriz", "Miguel", "Maria Jose", "Pablo", "Victoria", "Ricardo", "Natalia", "Hector", "Valentina", "Gonzalo", "Camila", "Rene", "Paola", "Hugo", "Diana"};
    for ( i ; i < x; ++i) {
        Reserva reserva;
        reserva.numReserva = i+1    ;
        reserva.numPersonas = rand() % 8 + 1;
        reserva.cliente = listaNombres[(rand() % 45)];
        reserva.hora = (rand() % 3 == 0) ? "13:00" : ((rand() % 2 == 0) ? "14:00" : "15:00");
        reserva.situacionMesa = (rand() % 2 == 0) ? "Terraza" : "Interior";
        reserva.preferenciaMenu = (rand() % 3 == 0) ? "vegano" : ((rand() % 2 == 0) ? "sin Gluten" : "completo");
        cout << reserva.toString();

        insertarNodoOrdenado(reserva);
    }
    cout << "Reservas creadas existosamente.\n";
    i = x;
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
    cout << "Listas dobles vaciadas correctamente.\n";
}
void ListasDobles::eliminarReservasMenu() {
    string preferenciaMenuAEliminar;
    cout << "Ingrese el tipo de menu a eliminar: ";
    cin >> preferenciaMenuAEliminar;

    NodoLDobles *aux = cabeza;
    NodoLDobles *siguiente;

    while (aux) {
        siguiente = aux->siguiente;

        if (aux->valor.preferenciaMenu == preferenciaMenuAEliminar) {
            // Si la reserva tiene la preferencia de menú que se quiere eliminar, la eliminamos
            if (aux->anterior) {
                aux->anterior->siguiente = aux->siguiente;
            } else {
                cabeza = aux->siguiente;
            }

            if (aux->siguiente) {
                aux->siguiente->anterior = aux->anterior;
            } else {
                fin = aux->anterior;
            }

            delete aux;
        }

        aux = siguiente;
    }

    cout << "Reservas eliminadas exitosamente.\n";
}



void ListasDobles::atenderTurno(ABB &mesas) {

    int turno;
    cout << "Ingrese el número del turno (1 - X): ";
    cin >> turno;

    // Iterar sobre las reservas
    NodoLDobles* actual = cabeza;
    while (actual) {
        // Comprobar si la reserva tiene el mismo turno
        if (actual->valor.esIgualEnTurno(turno)) {

            // BUSCAMOS UNA MESA VACÍA
            bool encontrado = mesas.buscarMesaAdecuada(actual->valor);

            // Mover a la siguiente reserva
            NodoLDobles* siguiente = actual->siguiente;
            if (encontrado){
                borrarNodo(actual->valor,'v');
            }
            actual = siguiente;
        } else {
            // Pasar a la siguiente reserva
            actual = actual->siguiente;
        }
    }
    mesas.resetearMesas();
}


