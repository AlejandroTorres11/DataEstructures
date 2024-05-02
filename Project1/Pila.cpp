#include "Pila.hpp"


Pila::Pila()
{
    ultimo=NULL;
}
bool Pila::estaVacia(){
    if (!ultimo){
        return true;
    } else {
        return false;
    }

}

void Pila::insertar(Mesa mesa)
{
    pnodoMesa nuevo;
    nuevo= new NodoMesas(mesa,ultimo);
    ultimo=nuevo;
}
void Pila::volcarPila(Pila &p){//vuelca la pila de la izquierda sobre la derecha.
    Mesa mesaVolcada;
    while (!estaVacia()){
        mesaVolcada= extraer();
        p.insertar(mesaVolcada);
    }

}
/*
Pila Pila::invertirPila(){
    Pila pVacia;
    volcarPila(pVacia);
    return(pVacia);
}
*/

Mesa Pila::extraer()
{
    pnodoMesa nodo;
    Mesa mesa;

    if(!ultimo)
    {
        return mesa;
    }
    nodo= ultimo;
    ultimo= nodo-> siguiente;
    mesa= nodo-> valorMesa;

    delete nodo;
    return mesa;
}
void Pila::borrarPila()
{
    if(!estaVacia()){
            while(!estaVacia())
            {
                extraer();
            }
    }else{
        cout<<"\n Proceso Realizado\n";
    }


}

void Pila::mostrar()
{
    pnodoMesa aux= ultimo;
    cout<<"\nPila de mesas: \n";
    while(aux)
    {
        cout<<"->"<<aux-> valorMesa.toString()<<endl;
        aux= aux->siguiente;
    }
    cout<<endl;
}



void Pila::generarMesasAleatorias() {
    srand(static_cast<unsigned>(time(0)));
    borrarPila();
    int mesasTerraza = 0;
    for (int i = 1; i <= 20; ++i) {
        Mesa mesa;
        mesa.numeroMesa = i;
        mesa.capacidad = (rand() % 2 == 0) ? 4 : 8; // Dos tipos de mesas de 4 y 8
        if (mesasTerraza <= 7){
            mesa.situacion = "Terraza";
        } else if (mesasTerraza > 7){
            mesa.situacion = (rand() % 3 == 0) ? "Terraza" : ((rand() % 2 == 0) ? "Interior" : "Interior");
        }
        if (mesa.situacion == "Terraza") {
            mesasTerraza++;
        }


        insertar(mesa);
    }

}
Pila::~Pila()
{
    pnodoMesa aux;
    while(ultimo)
    {
        aux=ultimo;
        ultimo=ultimo->siguiente;
        delete aux;
    }
}
