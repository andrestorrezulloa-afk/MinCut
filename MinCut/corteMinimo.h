#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include "Grafo.h"
#include "Lista8.h"

using namespace std;

template<typename T>
class corteMinimo
{
private:
    Grafo<T>* grafo; 
public:
   
    corteMinimo()
    {
        grafo = nullptr;
        srand((unsigned int)time(nullptr)); 
    }

    
    void setGrafo(Grafo<T>* g)
    {
        this->grafo = g;
    }

    
    T sacarNodoAleatorio()
    {
        T Aux = T();
        if (grafo != nullptr) {
            T* vec = grafo->getVectorNodos();
            int indice = rand() % 5; //Posible cambio para que sea dinamico en caso de que contraiga lo requiera
             Aux = vec[indice];
        }
        return Aux;
    }

    // saca una adyacencia aleatoria del nodo dado
    T sacarAdyacenciaAleatoria(T nodo)
    {
		T Aux = T();
        if (grafo != NULL) {
            // obtenemos la lista de vertices desde el Hash
            Lista8<Vertice<T>>* lista = grafo->getHash().accederHash(nodo);
            if (lista != NULL || lista->getPrimero() != NULL) {
                Caja<Vertice<T>>* aux = lista->getPrimero();
                while (aux != nullptr)
                {
                    if (aux->getValor().getNombre() == nodo) break;
                    aux = aux->getSiguiente();
                }

                if (aux != nullptr) {
                    Lista8<T>& adyacentes = aux->getValor().getAdyacentes();
                    int n = adyacentes.getContador();
                    if (n == 0) return T();

                    int r = rand() % n;
                    Caja<T>* ady = adyacentes.getPosicion(r);
                    Aux = ady->getValor();
                }
            }
        }
		return Aux;
    }
};
