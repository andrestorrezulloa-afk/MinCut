#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include "Grafo.h"
#include "Lista8.h"
#include "Heap.h"

using namespace std;

template<typename T>
class corteMinimo
{
private:
    Grafo<T>* grafo; 
    Heap<T>* HeapAuxiliar;
public:
   
    Grafo<T>* getGrafo();
    void FuncionKarger();

    corteMinimo()
    {
        grafo = NULL;
        srand((unsigned int)time(NULL));
    }

    
    void setGrafo(Grafo<T>* g)
    {
        this->grafo = g;
    }

    
    T sacarNodoAleatorio()
    {
        T Aux = T();
        if (grafo != NULL) {
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
                while (aux != NULL)
                {
                    if (aux->getValor().getNombre() == nodo) break;
                    aux = aux->getSiguiente();
                }

                if (aux != NULL) {
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

template<typename T>
inline Grafo<T>* corteMinimo<T>::getGrafo()
{
    return grafo;
}

template<typename T>
inline void corteMinimo<T>::FuncionKarger()
{
    for () {
        
        grafo.LeerArchivo();
        // Copia
        grafo.MostrarGrafo();

        while (g.getNumDeVerticesActuales() > 2) {

            string nodo = cm.sacarNodoAleatorio();
            cout << "\nNodo aleatorio seleccionado: " << nodo << endl;

            string ady = cm.sacarAdyacenciaAleatoria(nodo);

            if (!ady.empty())
                cout << "Adyacencia aleatoria del nodo " << nodo << ": " << ady << endl;
            else
                cout << "El nodo " << nodo << " no tiene adyacencias." << endl;


            grafo.ContraerAristas(nodo, ady);
            grafo.MostrarGrafo();
            grafo.getVectorNodos();
            cout << endl;
        }
    }
}


