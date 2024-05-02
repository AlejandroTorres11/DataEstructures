
#ifndef NODOMESAS_HPP
#define NODOMESAS_HPP
#include <iostream>

#include "Mesa.hpp"

using namespace std;

class Mesa;
class NodoMesas
{
public:
    NodoMesas();
    NodoMesas(Mesa , NodoMesas* sig= NULL);
    ~NodoMesas();
private:
    Mesa valorMesa;
    NodoMesas* siguiente;

    friend class Pila;
    friend class Mesa;


};
typedef NodoMesas* pnodoMesa;//ahora podemos crear clases nodo con punteros de tipo pnodo.
#endif // NODOMESAS_HPP

