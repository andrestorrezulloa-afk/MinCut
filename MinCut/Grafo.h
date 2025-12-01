#include <unordered_map>
#include <string>
#include "Vertice.h"
#include "Hash.h"
using namespace std;
#pragma once

template<typename T>
class Grafo
{
private:
    Hash<Vertice<T>> grafo;
    string vec[5];
public:
    Grafo();
    void Insertar(T Vo, T Vd);
    void LeerArchivo();
    void MostrarGrafo();
    string* getVectorNodos() { return vec; }
    Hash<Vertice<T>>& getHash() { return grafo; }

};

template<typename T>
Grafo<T>::Grafo()
{
}

template<typename T>
void Grafo<T>::Insertar(T Vo, T Vd)
{
    Lista8<Vertice<T>>* listaNodos = grafo.accederHash(Vo);

    if (listaNodos != NULL) {
        Caja<Vertice<T>>* aux = listaNodos->getPrimero();
        while (aux != nullptr)
        {
            if (aux->getValor().getNombre() == Vo)
            {

                Caja<string>* auxAdy = aux->getValor().getAdyacentes().getPrimero();
                bool existe = false;
                while (auxAdy != nullptr)
                {
                    if (auxAdy->getValor() == Vd) { existe = true; break; }
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
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
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
}


template<typename T>
void Grafo<T>::MostrarGrafo()
{
    grafo.MostrarHash(); 
}
