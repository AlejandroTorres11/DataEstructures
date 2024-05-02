#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include <iostream>
#include "Pedido.hpp"

class NodoLista {
    private:
        Pedido valor;
        NodoLista *siguiente;
        friend class Lista;
        friend class Pedido;
        friend class Mesa;

    public:
         NodoLista(Pedido v, NodoLista *sig);
        ~NodoLista();

};


#endif // NODOLISTA_HPP
