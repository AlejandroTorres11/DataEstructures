#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Mesa.hpp"

using namespace std;

    Mesa::Mesa()
    {
    }
    // Operador de comparación personalizado
    bool Mesa::esIgual(const Mesa& otraMesa) const {
        return (numeroMesa == otraMesa.numeroMesa);
    }
        // Operador de comparación personalizado (>)
    bool Mesa::operator>(const Mesa& otraMesa) const {
        return numeroMesa > otraMesa.numeroMesa;
    }
    // Operador de comparación personalizado (<)
    bool Mesa::operator<(const Mesa& otraMesa) const {
        return numeroMesa < otraMesa.numeroMesa;
    }

   string Mesa::toString()
    {
        return "Número de mesa: " + to_string(numeroMesa) +
                ", Capacidad: " + to_string(capacidad) +
                   ", Situación: " + situacion + ", numero de pedidos: "+ std::to_string(pedidos.contarElementos()) + "\n";
    }

