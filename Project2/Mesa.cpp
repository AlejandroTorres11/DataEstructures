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

        return "Numero de mesa: " + to_string(numeroMesa) +
                ", Capacidad: " + to_string(capacidad) +
                   ", Situacion: " + situacion + ", Numero de pedidos: "+ std::to_string(pedidos.contarElementos());
                   //DA ERROR AL TRATAR DE IMPRIMIR EL NUMERO DE ELEMENTO DE EL QUE NO SEA RAIZ
    }



