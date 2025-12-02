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
    Grafo<T> grafo; 
    Heap<T>* HeapAuxiliar;
public:
	void leerArchivo();
    Grafo<T> getGrafo();
    void FuncionKarger();

    corteMinimo()
    {
      
        srand((unsigned int)time(NULL));
    }

    
    void setGrafo(Grafo<T>* g)
    {
        this->grafo = g;
    }

    
    T sacarNodoAleatorio(int cantidadDeNodos)
    {
        T Aux = T();
        
            T* vec = grafo.getVectorNodos();
            int indice = rand() % cantidadDeNodos; //Posible cambio para que sea dinamico en caso de que contraiga lo requiera
             Aux = vec[indice];
        
        return Aux;
    }

    // saca una adyacencia aleatoria del nodo dado
    T sacarAdyacenciaAleatoria(T nodo)
    {
		T Aux = T();
        
            // obtenemos la lista de vertices desde el Hash
            Lista8<Vertice<T>>* lista = grafo.getHash().accederHash(nodo);
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
        
		return Aux;
    }
};

template<typename T>
inline void corteMinimo<T>::leerArchivo()
{
	grafo.LeerArchivo();
}

template<typename T>
inline Grafo<T> corteMinimo<T>::getGrafo()
{
    return grafo;
}

template<typename T>
inline void corteMinimo<T>::FuncionKarger()
{
  
   
    grafo.MostrarGrafo();

        
    
    while (grafo.getNumDeVerticesActuales() > 2) 
    {

        string nodo = sacarNodoAleatorio(grafo.getNumDeVerticesActuales());
        cout << "\nNodo aleatorio seleccionado: " << nodo << endl;

        string ady = sacarAdyacenciaAleatoria(nodo);
        if (!ady.empty())
            cout << "Adyacencia aleatoria del nodo " << nodo << ": " << ady << endl;
        else
            cout << "El nodo " << nodo << " no tiene adyacencias." << endl;


        grafo.ContraerAristas(nodo, ady);
        //grafo.MostrarGrafo();

        cout << endl;
    }
    
}


