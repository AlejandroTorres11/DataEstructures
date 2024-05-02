#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Reserva.hpp"
using namespace std;


class Pedido {
public:
    Reserva reserva;
    int numeroMesa;
    //Mesa mesaAsignada;
    bool finalizado;
    string toString();
    bool esIgual(const Pedido &otroPedido) const;

};

#endif // PEDIDO_HPP
