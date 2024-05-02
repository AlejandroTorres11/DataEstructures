
#include "ColaPedidos.hpp"
#include <string>
using namespace std;

ColaPedidos::ColaPedidos()
{
    primero= NULL;
    ultimo= NULL;
}
ColaPedidos::~ColaPedidos()
{

}

void ColaPedidos::insertarPedido(Pedido pedido)
{
    pnodoPedido nuevo;
    nuevo= new NodoPedidos(pedido);
    if(ultimo)
        ultimo-> siguiente= nuevo;

    ultimo= nuevo;
    if(!primero)
        primero=nuevo;
}

Pedido ColaPedidos::eliminarPedido()
{
    pnodoPedido nodo;
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

void ColaPedidos::mostrarPedidos()
{
    pnodoPedido aux= primero;
    cout<<"Cola: ";
    while(aux)
    {
        Pedido pedido=aux->valorPedido;
        cout << "->" << pedido.toString();

        aux= aux->siguiente;
    }
    cout<< endl;
    cout <<"\n";

}

bool ColaPedidos::estaVacia(){
    if (!primero){
        return true;
    } else {
        return false;
    }
}
int ColaPedidos::contarElementos(){
        int contador = 0;
        NodoPedidos* temp = primero;

        while (temp) {
            contador++;
            temp = temp->siguiente;
        }

        return contador;
    }

