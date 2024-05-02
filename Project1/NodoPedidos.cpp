
#include "NodoPedidos.hpp"

NodoPedidos::NodoPedidos(Pedido p, NodoPedidos* sig)
{
    valorPedido = p;
    siguiente = sig;
}

NodoPedidos::~NodoPedidos()
{
}


