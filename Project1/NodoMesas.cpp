
#include "NodoMesas.hpp"

NodoMesas::NodoMesas(Mesa m, NodoMesas* sig)
{
    valorMesa = m;
    siguiente = sig;
}

NodoMesas::~NodoMesas()
{
}


