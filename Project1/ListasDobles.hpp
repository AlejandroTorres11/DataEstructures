
#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED

#include "NodoLDobles.hpp"
#include <iostream>

const int ASCENDENTE=0;
const int DESCENDENTE=1;



class ListasDobles
{
    private:
        NodoLDobles *cabeza, *fin, *actual;

    public:
        ListasDobles() {cabeza=actual=fin=NULL; }
        ~ListasDobles();
        void insertarNodo(Reserva v, char c);
        void generarReservas();

        //void insertarNodoIntAntes(Reserva v, int posicion);
        void borrarNodo(Reserva v,char c);
        bool listaVacia();
        void mostrarLista(int);
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        void vaciarLista();
        Reserva valorActual();

};

#endif // LISTAS_DOBLES_H_INCLUDED
