
#include "Cola.hpp"
#include <string>
using namespace std;

Cola::Cola()
{
    primero= NULL;
    ultimo= NULL;
}
Cola::~Cola()
{

}
void Cola::insertarReserva(Reserva reserva)
{
    pnodo nuevo;
    nuevo= new Nodo(reserva);
    if(ultimo)
        ultimo-> siguiente= nuevo;

    ultimo= nuevo;
    if(!primero)
        primero=nuevo;
}
void Cola::insertarPedido(Pedido pedido)
{
    pnodo nuevo;
    nuevo= new Nodo(pedido);
    if(ultimo)
        ultimo-> siguiente= nuevo;

    ultimo= nuevo;
    if(!primero)
        primero=nuevo;
}
Reserva Cola::eliminarReserva()
{
    pnodo nodo;
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
Pedido Cola::eliminarPedido()
{
    pnodo nodo;
    Pedido pedido;
    nodo= primero;
    if(!nodo)
        return pedido;

    primero= nodo-> siguiente;
    pedido= nodo->valorPedido;
    delete nodo;
    if(!primero)
        ultimo= NULL;

    return pedido;
}

void Cola::mostrarReservas()
{
    pnodo aux= primero;
    cout<<"cola: ";
    while(aux)
    {
        Reserva reserva= aux->valorReserva;
        cout << "->"<< reserva.toString();
        aux= aux->siguiente;
    }
    cout<< endl;
}
void Cola::mostrarPedidos()
{
    pnodo aux= primero;
    cout<<"cola: ";
    while(aux)
    {
        Pedido pedido=aux->valorPedido;
        cout << "->" << pedido.toString();

        aux= aux->siguiente;
    }
    cout<< endl;
}

bool Cola::estaVacia(){
    if (!primero){
        return true;
    } else {
        return false;
    }

}
/*
Cola::~ColaReserva() {
    while (primero) {
        eliminarReserva();
    }
}
*/
/*
Cola::~ColaPedido() {
    while (primero) {
        eliminarPedido();
    }
}*/


