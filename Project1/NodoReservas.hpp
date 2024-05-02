
#ifndef NODORESERVAS_HPP
#define NODORESERVAS_HPP
#include <iostream>

#include "Reserva.hpp"

using namespace std;

class NodoReservas
{
public:
    NodoReservas();
    NodoReservas(Reserva , NodoReservas* sig= NULL);
    ~NodoReservas();
private:
    Reserva valorReserva;
    NodoReservas* siguiente;

    friend class ColaReservas;
    friend class Reserva;

};
typedef NodoReservas* pnodoReserva;//ahora podemos crear clases nodo con punteros de tipo pnodo.
#endif // NODORESERVAS_HPP
