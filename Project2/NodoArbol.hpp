
#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include <iostream>
#include "Mesa.hpp"

class NodoArbol {
public:
    NodoArbol(const Mesa &m, NodoArbol *izq = nullptr, NodoArbol *der = nullptr);
    ~NodoArbol();
private:
    Mesa mesa;
    NodoArbol *izquierdo;
    NodoArbol *derecho;
    friend class ABB;
    friend class Mesa;
};


#endif // NODOARBOL_HPP
