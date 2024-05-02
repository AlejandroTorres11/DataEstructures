#include "Reserva.hpp"
#include "ColaReservas.hpp"
#include <string>
using namespace std;

ColaReservas::ColaReservas()
{
    primero= NULL;
    ultimo= NULL;
}
ColaReservas::~ColaReservas()
{

}
void ColaReservas::generarReservasAleatorias(ColaReservas &cPendientes) {
    srand(static_cast<unsigned>(time(0)));

string listaNombres[] = {"David", "Alejandro", "Juan", "Pedro", "Sandra", "Maria", "Alejandra", "Silvia", "Jose", "Vanesa", "Ana", "Patricia", "Fernando", "Manuel", "Luis", "Elena", "Carlos", "Carmen", "Lorena", "Roberto", "Rosa", "Laura", "Javier", "Isabel", "Antonio", "Eduardo", "Marta", "Raul", "Lucia", "Diego", "Veronica", "Sergio", "Monica", "Andres", "Beatriz", "Miguel", "Maria Jose", "Pablo", "Victoria", "Ricardo", "Natalia", "Hector", "Valentina", "Gonzalo", "Camila", "Rene", "Paola", "Hugo", "Diana"};
    for (int i = 0; i < 12; ++i) {
        Reserva reserva;
        reserva.numReserva = i+1    ;
        reserva.numPersonas = rand() % 8 + 1;
        reserva.cliente = listaNombres[(rand() % 45)];
        reserva.hora = (i < 4) ? "13:00" : ((i < 8) ? "14:00" : "15:00");
        reserva.situacionMesa = (rand() % 2 == 0) ? "Terraza" : "Interior";
        reserva.preferenciaMenu = (rand() % 3 == 0) ? "vegano" : ((rand() % 2 == 0) ? "sin Gluten" : "completo");
        //cout << reserva.toString();

        insertarReserva(reserva);
        cPendientes.insertarReserva(reserva);
    }
    cout << "Reservas creadas existosamente.\n";
}

Mesa ColaReservas::buscadorMesa(Pila &p, Reserva reserva, ColaReservas &cPendientes, ColaPedidos &cPedidos) {
    Pila temp;
    bool encontrado = false;
    while (!encontrado && !p.estaVacia()) {
        Mesa mesaCandidato = p.extraer();
        int numBusqueda = (reserva.numPersonas > 4) ? 8 : 4;
        if ((mesaCandidato.capacidad == numBusqueda)&&(mesaCandidato.situacion==reserva.situacionMesa)) { //Encuentra la mesa
            encontrado = true;
            temp.volcarPila(p);
            //p.mostrar();
            //cout << "^\n";
            //cout << "|\n";
            //cout << "|\n";

            return mesaCandidato;
        } else {
            temp.insertar(mesaCandidato);

        }
    }
    // No se encontró una mesa adecuada, crea una reserva temporal y almacénala en cPendientes
    Reserva reservaNoEncontrada = reserva;
    cPendientes.insertarReserva(reservaNoEncontrada);
    return Mesa();
}


void ColaReservas::insertarReserva(Reserva reserva)
{
    pnodoReserva nuevo;
    nuevo= new NodoReservas(reserva);
    if(ultimo)
        ultimo-> siguiente= nuevo;

    ultimo= nuevo;
    if(!primero)
        primero=nuevo;
}
void ColaReservas::unirColas(ColaReservas &cola)//INSERTA LA COLA DE LA IZQUIERDA(OBJETO) A LA DE LA DERECHA(ARGUMENTO)
{
    Reserva reserva;
    while(!estaVacia())
    {
        reserva=eliminarReserva();
        cola.insertarReserva(reserva);
    }
}
Reserva ColaReservas::eliminarReserva()
{
    pnodoReserva nodo;
    Reserva reserva;
    nodo= primero;
    if(!nodo)
        return reserva;

    primero= nodo-> siguiente;
    reserva = nodo->valorReserva;
    delete nodo;
    if(!primero)
        ultimo= NULL;

    return reserva;
}
void ColaReservas::borrarReservas()
{
    while (!estaVacia()) {
        eliminarReserva();
    }
    cout<<"Cola de reservas borrada\n";
}
void ColaReservas::mostrarReservas()
{
    pnodoReserva aux= primero;
    cout<<"Cola: ";
    while(aux)
    {
        Reserva reserva= aux->valorReserva;
        cout << "->"<< reserva.toString();
        aux= aux->siguiente;
    }
        cout <<"\n";

}
//otra versión sin punteros
    /*
void ColaReservas::mostrarReservas() {
    while (!estaVacia()) {
        Reserva reserva = eliminarReserva();
        cout<< reserva.toString();
    }
}*/
bool ColaReservas::estaVacia(){
    if (!primero){
        return true;
    } else {
        return false;
    }

}



