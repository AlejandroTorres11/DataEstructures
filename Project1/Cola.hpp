#ifndef COLA_HPP
#define COLA_HPP
#include "Nodo.hpp"
#include "Reserva.hpp"
#include "Pedido.hpp"

class Cola
{
public:
    Cola();
    ~Cola();

    void insertarReserva(Reserva reserva);
    void insertarPedido(Pedido pedido);
    Reserva eliminarReserva();
    Pedido eliminarPedido();
    void mostrarReservas();
    void mostrarPedidos();
    bool estaVacia(); // Para reservas
private:
    pnodo primero, ultimo;

};



#endif // COLA_HPP
