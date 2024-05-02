#ifndef NODOLDOBLES_HPP
#define NODOLDOBLES_HPP

#include <iostream>
#include "Reserva.hpp"

class NodoLDobles
{
    private:
        Reserva valor;
        NodoLDobles *siguiente;
        NodoLDobles *anterior;
        friend class ListasDobles;
        friend class Reserva;

    public:
        NodoLDobles(Reserva v, NodoLDobles *sig = NULL, NodoLDobles *ant = NULL);
        ~NodoLDobles();

};
#endif // NODOLDOBLES_HPP
