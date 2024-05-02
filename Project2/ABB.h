#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include "NodoArbol.hpp"
#include "Reserva.hpp"
#include <iostream>
#include <string>
using namespace std;


class ABB {
    private:

   NodoArbol *raiz;
   NodoArbol *actual;
   int contador;
   int altura;
   void Podar(NodoArbol* &);
   void auxContador(NodoArbol*);
   void auxAltura(NodoArbol*, int);
   void buscarMesaAdecuadaRecursiva(NodoArbol* nodo, Reserva &reserva, bool& mesaBool);

    public:
   ABB() : raiz(NULL), actual(NULL) {}
   ~ABB() { Podar(raiz); }
   void ensenarMesa();
   void Insertar(const Mesa dat);
   void Borrar(const Mesa dat);
   bool Buscar(const Mesa dat);
   bool Vacio(NodoArbol *r) { return r==NULL; }
   bool EsHoja(NodoArbol *r) { return !r->derecho && !r->izquierdo; }
   const int NumeroNodos();
   const int AlturaArbol();
   int Altura(const Mesa dat);
   Mesa &ValorActual() { return actual->mesa; }
   void Raiz() { actual = raiz; }
   string sumarUnaHora(const string& hora);
   void InOrden(void (*func)(Mesa&) , NodoArbol *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(Mesa&) , NodoArbol *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(Mesa&) , NodoArbol *nodo=NULL, bool r=true);
   void ensenarMesasPorSituacion();
   void ensenarMesasPorSituacionAux(NodoArbol* nodo,  string sitMesa);
   void pedirMesaInsertar();
   void pedirMesaBorrar();
   void generarMesasAleatorias();
   void resetearMesas(NodoArbol* nodo);
   void resetearMesas();
   bool buscarMesaAdecuada(Reserva &reserva);

};

#endif // ABB_H_INCLUDED
