#ifndef RESERVA_HPP
#define RESERVA_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


class Reserva {
public:
    int numReserva;
    string cliente;
    string situacionMesa; // Terraza o Interior
    int numPersonas;
    string hora; // "13:00", "14:00", "15:00"
    string preferenciaMenu; // "vegano", "sin Gluten", "completo"
    bool esIgual(const Reserva &otraReserva) const;
    // Constructor por defecto
    Reserva();

    // Método para generar aleatoriamente la cola cReservas
    //void generarReservasAleatorias(Pila p);

    // Método para mostrar en pantalla los datos de la cola cReservas
    //void mostrarReservas();

    string toString();
};

#endif // RESERVA_HPP
