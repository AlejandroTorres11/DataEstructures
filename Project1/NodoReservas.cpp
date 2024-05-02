
#include "NodoReservas.hpp"

NodoReservas::NodoReservas(Reserva r, NodoReservas* sig)
{
    valorReserva = r;
    siguiente = sig;
}

NodoReservas::~NodoReservas()
{
}

