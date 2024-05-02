#include <iostream>
#include <string>
#include "Restaurante.hpp"
#include "ListasDobles.hpp"
#include "Mesa.hpp"
#include "ABB.h"
using namespace std;

void Mostrar (Mesa &m){
    cout << m.toString();
}
int main() {
    Restaurante restaurante;
    Reserva reserva;
    ListasDobles lReservas;
    ABB AbbMesas;
    AbbMesas.generarMesasAleatorias();

    bool empezado= false;
    int eleccion = -1; // Inicializa eleccion con un valor distinto de 0

    while (eleccion != 0) {
        cout << "\nElige un numero:\n";
/*INCOMPLETO------*/cout << "1 - Mostrar ABB de mesas (inorden) \n";
/*done*/cout << "2 - Borrar una mesa concreta que indique el usuario.\n";
/*done*/cout << "3 - Crear una nueva mesa, solicitando los datos al usuario, e insertarla en el ABB de mesa\n";
/*done*/cout << "4 - Generar aleatoriamente un número de reservas y añadirlos a la lista doble de reservas.\n";
/*done*/cout << "5 - Mostrar en pantalla los datos de la lista de reservas\n";
        cout << "6 - Vaciar la lista de reservas\n";
        cout << "7 - Solicitar por teclado un tipo de menú y eliminar de la lista doble todas las reservas de ese menú\n";
        cout << "8 - Solicitar por teclado un turno y atender todas las reservas de ese turno.\n";
        cout << "9 - Solicitar por teclado una mesa y mostrar en pantalla sus datos y la lista de pedidos atendidos.\n";
        cout << "10 - Solicitar por teclado una situación y mostrar en pantalla los datos de las mesas\n";
        cout << "11 - Salir\n";
        cin >> eleccion;

        if (eleccion == 1) {
            AbbMesas.InOrden(Mostrar);
        } else if (eleccion == 2) {
            AbbMesas.pedirMesaBorrar();
        } else if (eleccion == 3) {
            AbbMesas.pedirMesaInsertar();

        } else if (eleccion == 4) {
            lReservas.generarReservas();
        } else if (eleccion == 5) {
            lReservas.mostrarLista(0);
        } else if (eleccion == 6) {
            lReservas.vaciarLista();
        } else if (eleccion == 7) {

        } else if (eleccion == 8) {

        } else if (eleccion == 9) {


        } else if (eleccion == 10) {

        }else if (eleccion == 11) {
            return 0;
        } else {
            cout << "Inserte un numero valido (0-9): ";
        }
    }

    return 0;
}
