#ifndef COLAPEDIDOS_HPP
#define COLAPEDIDOS_HPP
#include "NodoPedidos.hpp"
#include "Pedido.hpp"


class ColaPedidos
{
public:
    ColaPedidos();
    ~ColaPedidos();
    int contarElementos();
    void insertarPedido(Pedido pedido);
    Pedido eliminarPedido();
    void mostrarPedidos();
    bool estaVacia(); // Para Pedidos
private:
    pnodoPedido primero, ultimo;

};



#endif // COLAPEDIDOS_HPP
