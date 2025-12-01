#include <unordered_map>
#include <string>
#include "Vertice.h"
#include "Hash.h"
#define TAM 5
using namespace std;
#pragma once

template<typename T>
class Grafo
{
private:
    Hash<Vertice<T>> grafo;
    string vec[TAM];
    int NumDeVerticesActuales;
public:
    Grafo();
    void Insertar(T Vo, T Vd);
    void LeerArchivo();
    void MostrarGrafo();
    string* getVectorNodos();
    Hash<Vertice<T>>& getHash();
    int getNumDeVerticesActuales();
    Caja<Vertice<T>>* buscarVertice(Lista8<Vertice<T>>* lista, T nombre);

    int EncontrarIndiceVec(T elemento);
    void EliminarDeVec(T elemento);
    void ContraerAristas(T u, T v);
};

template<typename T>
Grafo<T>::Grafo()
{
    NumDeVerticesActuales = 0;
}

template<typename T>
void Grafo<T>::Insertar(T Vo, T Vd)
{
    Lista8<Vertice<T>>* listaNodos = grafo.accederHash(Vo);

    if (listaNodos != NULL) {
        Caja<Vertice<T>>* aux = listaNodos->getPrimero();
        while (aux != NULL)
        {
            if (aux->getValor().getNombre() == Vo)
            {

                Caja<string>* auxAdy = aux->getValor().getAdyacentes().getPrimero();
                bool existe = false;
                while (auxAdy != NULL)
                {
                    if (auxAdy->getValor() == Vd){
                        existe = true; 
                        break; 
                    }
                    auxAdy = auxAdy->getSiguiente();
                }
                if (!existe) aux->getValor().getAdyacentes().Insertar_Fin(Vd);
                return;
            }
            aux = aux->getSiguiente();
        }
    }

    Vertice<T> nodoNuevo(Vo);
    nodoNuevo.getAdyacentes().Insertar_Fin(Vd);
    grafo.Insertar(nodoNuevo);
}

template<typename T>
void Grafo<T>::LeerArchivo()
{
    ifstream archivo("Min_Cut_NOMBRES Prueba.txt");
    if (archivo.is_open()) {
        string Arista, Adyacente;
        int indexVec = 0; // para ir llenando vec[]
        while (archivo >> Arista)
        {
            vec[indexVec++] = Arista;

            while (archivo >> Adyacente && Adyacente != "-1")
            {
                Insertar(Arista, Adyacente);
            }
        }
        archivo.close();
        NumDeVerticesActuales = indexVec;
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }

}


template<typename T>
void Grafo<T>::MostrarGrafo()
{
    grafo.MostrarHash(); 
}

template<typename T>
inline string* Grafo<T>::getVectorNodos()
{
    return vec;
}

template<typename T>
inline Hash<Vertice<T>>& Grafo<T>::getHash()
{
    return grafo;
}

template<typename T>
inline int Grafo<T>::getNumDeVerticesActuales()
{
    return NumDeVerticesActuales;
}

template<typename T>
inline Caja<Vertice<T>>* Grafo<T>::buscarVertice(Lista8<Vertice<T>>* lista, T nombre)
{
    Caja<Vertice<T>>* aux = lista->getPrimero();
    while (aux != NULL) {
        if (aux->getValor().getNombre() == nombre)
            break;

        aux = aux->getSiguiente();
    }
    return aux;
}

template<typename T>
inline int Grafo<T>::EncontrarIndiceVec(T elemento)
{
    for (int i = 0; i < NumDeVerticesActuales; i++) {
        if (vec[i] == elemento) {
            return i;  
        }
    }
    return -1;  
}

template<typename T>
inline void Grafo<T>::EliminarDeVec(T elemento)
{
    int indice = EncontrarIndiceVec(elemento);
    if (indice != -1) {
        vec[indice] = vec[NumDeVerticesActuales - 1]; // Mover al ultimo
        NumDeVerticesActuales--;
    }
}

template<typename T>
inline void Grafo<T>::ContraerAristas(T u, T v)
{
    // Si el nodo y el adyacente no son iguales
    if (u != v) {
        // Se busca en la hash ambos nodos
        Lista8<Vertice<T>>* listaU = grafo.accederHash(u); 
        Lista8<Vertice<T>>* listaV = grafo.accederHash(v);

        // Si existen las listas
        if (listaU != NULL && listaV != NULL) {
            // Conseguir los nodos buscando en las coliciones del hash
            Caja<Vertice<T>>* nodoU = buscarVertice(listaU, u);
            Caja<Vertice<T>>* nodoV = buscarVertice(listaV, v);

            if (nodoU != NULL && nodoV != NULL) {
                // Conseguimos sus listas de adyaciencia
                Lista8<T>& adyU = nodoU->getValor().getAdyacentes();
                Lista8<T>& adyV = nodoV->getValor().getAdyacentes();

                // Eliminar nodo de la lista de adyaciencia 
                adyU.EliminarValor(v);

                // Procesar cada adyacente del nodo a borrar
                Caja<T>* adyAux = adyV.getPrimero();
                while (adyAux != NULL) {
                    T w = adyAux->getValor(); // Auxiliar para buscar cada uno de las adyaciencias de v

                    if (w != u && w != v) {
                        // Encontrar nodo w
                        Lista8<Vertice<T>>* listaW = grafo.accederHash(w);

                        if (listaW != NULL) {
                            Caja<Vertice<T>>* nodoW = listaW->getPrimero();

                            while (nodoW != NULL) {
                                // En la lista de w cambiamos v (Nodo a borrar) por u (Nodo donde se combinara) 

                                Lista8<T>& adyW = nodoW->getValor().getAdyacentes();
                                Caja<T>* adyWaux = adyW.getPrimero();

                                while (adyWaux != NULL) {
                                    if (adyWaux->getValor() == v)
                                        adyWaux->setValor(u);

                                    adyWaux = adyWaux->getSiguiente();
                                }

                                nodoW = nodoW->getSiguiente();
                            }
                        }
                        // Insertar W
                        adyU.Insertar_Fin(w);
                    }
                    adyAux = adyAux->getSiguiente();
                }
                // Eliminar adyacenciasAUnoMismo
                adyU.EliminarValor(u);
            }
        }
    }
    grafo.Eliminar(v);
    EliminarDeVec(v);
}
