#include "NodoLDobles.hpp"

NodoLDobles::NodoLDobles(Reserva v, NodoLDobles *sig, NodoLDobles *ant)
    {
        valor = v;
        siguiente = sig;
        anterior = ant;
    }

NodoLDobles::~NodoLDobles()
{

}

