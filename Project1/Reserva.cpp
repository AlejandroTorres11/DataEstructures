#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Reserva.hpp"
#include "ColaReservas.hpp"
#include "Mesa.hpp"
#include "Pila.hpp"

using namespace std;


//falta poner la mesa asignada en la generación de reservas

    Reserva::Reserva()
    {
    }


    // Método para mostrar en pantalla los datos de la cola cReservas


bool Reserva::esIgual(const Reserva &otraReserva) const {
    return numReserva == otraReserva.numReserva;
}

string Reserva::toString()
    {

return  "\nDatos de la reserva:\n numReserva: " + std::to_string(numReserva)
            + ", Cliente: " + cliente
            + " ,Preferencia situacion: " + situacionMesa
            + " ,Numero de personas: " + to_string(numPersonas)
            +",situacion de la mesa: " +situacionMesa
            + ",Hora: " + hora
            + " ,Preferencia de menu: " + preferenciaMenu + "\n";

    }


