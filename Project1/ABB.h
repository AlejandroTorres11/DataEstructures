#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include "NodoArbol.hpp"
#include <iostream>
#include <string>
using namespace std;


class ABB {
    private:
   // Punteros de la lista, para cabeza y nodo actual:
   NodoArbol *raiz;
   NodoArbol *actual;
   int contador;
   int altura;

    public:
   // Constructor y destructor básicos:
   ABB() : raiz(NULL), actual(NULL) {}
   ~ABB() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const Mesa dat);
   // Borrar un elemento del árbol:
   void Borrar(const Mesa dat);
   // Función de búsqueda:
   bool Buscar(const Mesa dat);
   // Comprobar si el árbol está vacío:
   bool Vacio(NodoArbol *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(NodoArbol *r) { return !r->derecho && !r->izquierdo; }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un int:
   int Altura(const Mesa dat);
   // Devolver referencia al int del nodo actual:
   Mesa &ValorActual() { return actual->mesa; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(Mesa&) , NodoArbol *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(Mesa&) , NodoArbol *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(Mesa&) , NodoArbol *nodo=NULL, bool r=true);

   void pedirMesaInsertar();
   void pedirMesaBorrar();
   void generarMesasAleatorias();
  private:
   // Funciones auxiliares
   void Podar(NodoArbol* &);
   void auxContador(NodoArbol*);
   void auxAltura(NodoArbol*, int);
};

#endif // ABB_H_INCLUDED
