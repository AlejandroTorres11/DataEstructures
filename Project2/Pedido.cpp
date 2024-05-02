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
            ".\n\t- Numero de pedido: " + std::to_string(reserva.numReserva) +
            ".\n\t- Cliente: " + reserva.cliente +
               ".\n\t- Número de personas: " + std::to_string(reserva.numPersonas) +
               ".\n\t- Preferencia de menu: " + reserva.preferenciaMenu +
               ".\n\t- Situacion de mesa: " + reserva.situacionMesa + "\n";

}
