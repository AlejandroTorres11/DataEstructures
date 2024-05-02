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


bool Reserva::esIgual(const Reserva otraReserva) {
    return numReserva == otraReserva.numReserva;
}
bool Reserva::esIgualEnTurno(int turno) {
    return (hora == std::to_string(turno + 12) + ":00");
}



string Reserva::toString()
    {

return  "\n-- Datos de la reserva:\n numReserva: " + std::to_string(numReserva)
            + "\n\t- Cliente: " + cliente
            + "\n\t- Preferencia situacion: " + situacionMesa
            + "\n\t- Numero de personas: " + to_string(numPersonas)
            + "\n\t- Situacion de la mesa: " +situacionMesa
            + "\n\t- Hora: " + hora
            + "\n\t- Preferencia de menu: " + preferenciaMenu + "\n";

    }


