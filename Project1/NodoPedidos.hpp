
#ifndef NODOPEDIDOS_HPP
#define NODOPEDIDOS_HPP
#include <iostream>

#include "Pedido.hpp"

using namespace std;

class NodoPedidos
{
public:
    NodoPedidos();
    NodoPedidos(Pedido , NodoPedidos* sig= NULL);
    ~NodoPedidos();
private:
    Pedido valorPedido;
    NodoPedidos* siguiente;

    friend class ColaPedidos;
    friend class Pedido;

};
typedef NodoPedidos* pnodoPedido;//ahora podemos crear clases nodo con punteros de tipo pnodo.
#endif // NODOPEDIDOS_HPP

