#include "NodoArbol.hpp"

NodoArbol::NodoArbol(const Mesa &m, NodoArbol *izq, NodoArbol *der) : mesa(m), izquierdo(izq), derecho(der) {}

NodoArbol::~NodoArbol()
{

}



