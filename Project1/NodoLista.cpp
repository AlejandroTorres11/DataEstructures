#include "NodoLista.hpp"
NodoLista::NodoLista(Pedido v, NodoLista *sig )
    {
       valor = v;
       siguiente = sig;
    }

NodoLista::~NodoLista()
{

}
