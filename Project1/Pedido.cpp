#include "Pedido.hpp"
#include <iostream>
#include <string>
using namespace std;


bool Pedido::esIgual(const Pedido &otroPedido) const {
    return reserva.numReserva == otroPedido.reserva.numReserva;
}

string Pedido::toString()
{
    return "Numero de mesa: " + std::to_string(numeroMesa) +
            ", numPedido: " + std::to_string(reserva.numReserva) +
            ", Cliente: " + reserva.cliente +
               ", Número de personas: " + std::to_string(reserva.numPersonas) +
               ", Preferencia de menu: " + reserva.preferenciaMenu +
               ", Situacion de mesa: " + reserva.situacionMesa +
               ", Finalizado: " + (finalizado ? "Si" : "No") + "\n";
}
