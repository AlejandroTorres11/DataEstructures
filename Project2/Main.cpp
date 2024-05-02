#include <iostream>
#include <string>
#include "Restaurante.hpp"
#include "ListasDobles.hpp"
#include "Mesa.hpp"
#include "ABB.h"
using namespace std;

void Mostrar (Mesa &m){
    cout << m.toString() << "\n";
}

void MostrarTerrazas (Mesa &m){
    if ("Terraza" == m.situacion){
        cout << m.toString() << "\n";
    }
}

void MostrarInteriores (Mesa &m){
    if ("Interior" == m.situacion){
        cout << m.toString() << "\n";
    }
}
int main() {

    Reserva reserva;
    ListasDobles lReservas;
    Lista lPedidos;
    ABB AbbMesas;
    AbbMesas.generarMesasAleatorias();


    int eleccion = -1; // Inicializa eleccion con un valor distinto de 0

    while (eleccion != 0) {
        cout << "\nElige un numero:\n";
/*done*/cout << "1 - Mostrar ABB de mesas (inorden) \n";
/*done*/cout << "2 - Borrar una mesa concreta que indique el usuario.\n";
/*done*/cout << "3 - Crear una nueva mesa, solicitando los datos al usuario, e insertarla en el ABB de mesa.\n";
/*done*/cout << "4 - Generar aleatoriamente un numero de reservas y añadirlos a la lista doble de reservas.\n";
/*done*/cout << "5 - Mostrar en pantalla los datos de la lista de reservas" << ". Actualmente: ["<<lReservas.i<<"] reservas.\n";
/*done*/cout << "6 - Vaciar la lista de reservas.\n";
/*done*/cout << "7 - Solicitar por teclado un tipo de menu y eliminar de la lista doble todas las reservas de ese menu.\n";
/*done*/cout << "8 - Solicitar por teclado un turno y atender todas las reservas de ese turno.\n";
/*done*/cout << "9 - Solicitar por teclado una mesa y mostrar en pantalla sus datos y la lista de pedidos atendidos.\n";
/*done*/cout << "10 - Solicitar por teclado una situacion y mostrar en pantalla los datos de las mesas.\n";
/*done*/cout << "11 - Salir.\n";
        cin >> eleccion;

        if (eleccion == 1) {

        cout << "\nAltura de arbol: " << AbbMesas.AlturaArbol();
        cout << "\nNumero de nodos: " << AbbMesas.NumeroNodos() << "\n";
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
            lReservas.eliminarReservasMenu();
        } else if (eleccion == 8) {
            lReservas.atenderTurno(AbbMesas);
        } else if (eleccion == 9) {
            AbbMesas.ensenarMesa();
        } else if (eleccion == 10) {
            AbbMesas.ensenarMesasPorSituacion();
        }else if (eleccion == 11) {
            return 0;
        } else {
            cout << "Inserte un numero valido (0-9): ";
        }
    }

    return 0;
}
