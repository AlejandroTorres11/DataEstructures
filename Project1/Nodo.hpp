#ifndef NODO_HPP
#define NODO_HPP
#include <iostream>

#include "Reserva.hpp"
#include "Pedido.hpp"
#include "Mesa.hpp"

using namespace std;

class Mesa;
class Nodo
{
public:
    //Nodo(int v, Nodo* sig= NULL);
    Nodo(Reserva, Nodo* sig= NULL);
    Nodo(Pedido, Nodo* sig=NULL);
    Nodo(Mesa, Nodo* sig=NULL);
    ~Nodo();
private:
    Reserva valorReserva;
    Pedido valorPedido;
    Mesa valorMesa;
    Nodo* siguiente;

    friend class Pila;
    friend class Cola;
    friend class Reserva;
    friend class Pedido;
    friend class Mesa;
};
typedef Nodo* pnodo;//ahora podemos crear clases nodo con punteros de tipo pnodo.
#endif // NODO_HPP
