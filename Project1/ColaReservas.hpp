#ifndef COLARESERVAS_HPP
#define COLARESERVAS_HPP
#include "NodoReservas.hpp"
#include "Reserva.hpp"
#include "ColaPedidos.hpp"


class ColaReservas
{
public:
    ColaReservas();
    ~ColaReservas();

    void insertarReserva(Reserva reserva);
    void unirColas(ColaReservas &cola);
    Reserva eliminarReserva();
    void mostrarReservas();
    void borrarReservas();
    void generarReservasAleatorias(ColaReservas &cPendientes);
    bool estaVacia(); // Para reservas

private:
    pnodoReserva primero, ultimo;

};


#endif // COLARESERVAS_HPP
