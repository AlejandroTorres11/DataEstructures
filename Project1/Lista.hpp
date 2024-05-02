#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include "NodoLista.hpp"
#include <iostream>
#include "Pedido.hpp"
class Lista {
private:
    NodoLista *cabeza, *fin;
    NodoLista *actual;

public:
    Lista() : cabeza(nullptr), fin(nullptr), actual(nullptr) {}
    ~Lista();
    int contarElementos();
    void insertarNodo(Pedido);
    void insertarNodoIntermedio(Pedido, int);
    void borrarNodo(Pedido);
    bool listaVacia();
    void mostrarLista();
    void esSiguiente();
    void esFinal();
    void esPrimero();
    void esUltimo();
    bool esActual();

    Pedido valorActual();
};

#endif // LISTA_HPP_INCLUDED

