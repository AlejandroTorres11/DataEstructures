

#include "Nodo.hpp"


Nodo::Nodo(Reserva r, Nodo* sig)
{
    Reserva reserva= r;
    Nodo* siguiente= sig;
}
Nodo::Nodo(Pedido p, Nodo* sig)
{
    Pedido pedido= p;
    Nodo* siguiente= sig;
}
Nodo::Nodo(Mesa m, Nodo* sig)
{
    Mesa mesa=m;
    Nodo* siguiente= sig;
}
Nodo::~Nodo()
{
}

