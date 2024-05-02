
class Nodo
{
    private:
        Reserva valor;
        Nodo *siguiente;
        Nodo *anterior;
    friend class listas;


    public:
        Nodo(Reserva v, Nodo *sig = NULL, Nodo *ant = NULL)
        {
            valor = v;
            siguiente = sig;
            anterior = ant;
        }
};
typedef Nodo *pnodo;
