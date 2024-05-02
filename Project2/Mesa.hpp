#ifndef MESA_HPP
#define MESA_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Lista.hpp"

using namespace std;

class Mesa {
public:
    int numeroMesa;
    int capacidad; // 4 u 8 personas
    string situacion; // Terraza o Interior
    Lista pedidos;
    bool esIgual(const Mesa&) const;
    bool usada;
    bool operator>(const Mesa& ) const;
    bool operator<(const Mesa& ) const;
    Mesa();
    string toString();
private:
    friend class Lista;
    friend class Pedido;
};

#endif // MESA_HPP
