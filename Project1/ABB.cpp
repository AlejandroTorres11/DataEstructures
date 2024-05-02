#include "ABB.h"

// Poda: borrar todos los nodos a partir de uno, incluido
void ABB::Podar(NodoArbol* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void ABB::Insertar(const Mesa dat)
{
   NodoArbol *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) &&  !actual->mesa.esIgual(dat)) { // while(!Vacio(actual) &&  actual->mesa.esIgual(dat) {
      padre = actual;
      if(dat > actual->mesa) actual = actual->derecho;
      else if(dat < actual->mesa) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new NodoArbol(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->mesa) padre->izquierdo = new NodoArbol(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->mesa) padre->derecho = new NodoArbol(dat);
}

void ABB::Borrar(const Mesa dat)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   Mesa aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(actual->mesa.esIgual(dat)) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            cout << "\n\t\tBorrado un nodo hoja,";
            if(padre) {// Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            }
            else{
                cout << " que ademas era raiz.";
                raiz=NULL;
            }
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            if (actual->derecho==NULL){ //sólo tiene hijo izquierdo.
                cout << "\n\t\tBorrado un nodo lista izquierda,";
                if (padre){ //Si tiene padre, me lo salto
                        if(padre->izquierdo==actual)
                            padre->izquierdo=actual->izquierdo;
                        else
                            padre->derecho=actual->izquierdo;
                }
                else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz;
                    cout << " que ademas era raiz.";
                    raiz=actual->izquierdo;
                }
                delete actual;
                actual=NULL;
                return;
            }
            else  if (actual->izquierdo==NULL){ //sólo tiene hijo derecho.
                cout << "\n\t\tBorrado un nodo lista derecha,";
                if (padre){ //Si tiene padre, me lo salto
                        if(padre->izquierdo==actual)
                            padre->izquierdo=actual->derecho;
                        else
                            padre->derecho=actual->derecho;
                }
                else{ //Si no tiene padre, su hijo izquierdo es el nuevo raiz;
                    cout << " que ademas era raiz.";
                    raiz=actual->derecho;
                                    }
                delete actual;
                actual=NULL;
                return;
            }
            else{ // Tiene dos hijos. Busco sustituto. Nodo más a la derecha de la rama izquierda
               padre=actual;
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            // Intercambiar valores de nodo a borrar y nodo encontrado y continuar, cerrando el bucle. El nodo encontrado no tiene por qué ser un nodo hoja.
            // cerrando el bucle nos aseguramos de que sólo se eliminan nodos hoja.
                aux = actual->mesa;
                actual->mesa = nodo->mesa;
                nodo->mesa = aux;
                actual = nodo;
                cout << "\n\t\tHay intercambio.";
            }
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->mesa) actual = actual->derecho;
         else if(dat < actual->mesa) actual = actual->izquierdo;
      }
   }
}


// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABB::InOrden(void (*func)(Mesa&) , NodoArbol *nodo, bool r)
{
        if (Vacio(raiz)) return;
        if(r) {
            nodo = raiz;
        }
        if(nodo->izquierdo) {
            InOrden(func, nodo->izquierdo, false);
        }
        func(nodo->mesa);
        if(nodo->derecho){
            InOrden(func, nodo->derecho, false);
    }
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABB::PreOrden(void (*func)(Mesa&), NodoArbol *nodo, bool r)
{
   if (Vacio(raiz)) return;
   if(r) nodo = raiz;
   func(nodo->mesa);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void ABB::PostOrden(void (*func)(Mesa&), NodoArbol *nodo, bool r)
{
   if (Vacio(raiz)) return;
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->mesa);
}

// Buscar un valor en el árbol
bool ABB::Buscar(const Mesa dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(actual->mesa.esIgual(dat)) return true; // int encontrado
      else if(dat > actual->mesa) actual = actual->derecho; // Seguir
      else if(dat < actual->mesa) actual = actual->izquierdo;
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el int dat
int ABB::Altura(const Mesa dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(actual->mesa.esIgual(dat)) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->mesa) actual = actual->derecho;
         else if(dat < actual->mesa) actual = actual->izquierdo;
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int ABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ABB::auxContador(NodoArbol *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int ABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void ABB::auxAltura(NodoArbol *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}
void ABB::pedirMesaBorrar(){
    int capacidad;
    int nMesa;
    int situacionInt;
    string situacion;
    cout << "Numero mesa: ";
    cin >> nMesa;
    cout << "Capacidad de mesa: ";
    cin >> capacidad;
    cout << "Situación de mesa (1 para Terraza, 2 para Interior): ";
    cin >> situacionInt;

    // Convertir el valor entero a la representación de cadena correspondiente
    situacion = (situacionInt == 1) ? "Terraza" : (situacionInt == 2) ? "Interior" : "desconocido";

    // Validar que la situación ingresada sea válida
    if (situacion == "desconocido") {
        cout << "Situación de mesa no válida. Debe ingresar 1 para terraza o 2 para interior." << endl;
        return;
    }
    Mesa m;
    m.capacidad = capacidad;
    m.numeroMesa = nMesa;
    m.situacion = situacion;

    if (!Buscar(m)){
        cout << "no existe una mesa con ese numero, pruebe de nuevo.";
        return;
    }

    Borrar(m);
    cout << "Mesa borrada correctamente.";

}

void ABB::pedirMesaInsertar(){
    int capacidad;
    int nMesa;
    int situacionInt;
    string situacion;
    cout << "Numero mesa: ";
    cin >> nMesa;
    cout << "Capacidad de mesa: ";
    cin >> capacidad;
    cout << "Situación de mesa (1 para Terraza, 2 para Interior): ";
    cin >> situacionInt;

    // Convertir el valor entero a la representación de cadena correspondiente
    situacion = (situacionInt == 1) ? "Terraza" : (situacionInt == 2) ? "Interior" : "desconocido";

    // Validar que la situación ingresada sea válida
    if (situacion == "desconocido") {
        cout << "Situación de mesa no válida. Debe ingresar 1 para terraza o 2 para interior." << endl;
        return;
    }
    Mesa m;
    m.capacidad = capacidad;
    m.numeroMesa = nMesa;
    m.situacion = situacion;

    if (Buscar(m)){
        cout << "Ya existe una mesa con ese numero, pruebe de nuevo.";
        return;
    }

    Insertar(m);
    cout << "Mesa insertada correctamente.";

}

void ABB::generarMesasAleatorias() {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 1; i <= 20; ++i) {
        Mesa mesa;
        mesa.numeroMesa = i;
        mesa.capacidad = (rand() % 2 == 0) ? 4 : 8; // Dos tipos de mesas de 4 y 8
        if (i <= 10){
            mesa.situacion = "Terraza";
        } else if (i > 10){
            mesa.situacion = "Interior";
        }
        Insertar(mesa);
    }

}
