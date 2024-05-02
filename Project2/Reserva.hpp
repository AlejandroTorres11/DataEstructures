#ifndef RESERVA_HPP
#define RESERVA_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


class Reserva {
public:
    Reserva();
    int numReserva;
    string cliente;
    string situacionMesa; // Terraza o Interior
    int numPersonas;
    string hora; // "13:00", "14:00", "15:00"
    string preferenciaMenu; // "vegano", "sin Gluten", "completo"
    bool esIgual(const Reserva otraReserva);
    bool esIgualEnTurno(int turno);  // Constructor por defecto
    string toString();
};

#endif // RESERVA_HPP
