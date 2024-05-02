#ifndef PILA_HPP
#define PILA_HPP

#include "NodoMesas.hpp"
#include "Mesa.hpp"


class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Mesa mesa);
    void volcarPila(Pila &p);
    Mesa extraer();
    void borrarPila();
    void mostrar();
    bool estaVacia();
    //Pila invertirPila();
    void generarMesasAleatorias();
private:
    pnodoMesa ultimo;
};



#endif // PILA_HPP
