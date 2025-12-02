#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
#include <chrono>
#include <vector>
#include <algorithm>
#include "Grafo.h"
#include "Lista8.h"
#include "Heap.h"

using namespace std;
using namespace std::chrono;  // Añadido aquí

template<typename T>
class corteMinimo
{
private:
    Grafo<T> grafoOriginal;

public:
    void leerArchivo();
    Grafo<T> getGrafo();
    void FuncionKarger();

    corteMinimo();

    T sacarNodoAleatorio(Grafo<T>& grafoParam, int cantidadDeNodos);
    

    T sacarAdyacenciaAleatoria(Grafo<T>& grafoParam, T nodo);
    
};
template<typename T>
inline corteMinimo<T>::corteMinimo()
{
    srand((unsigned int)time(NULL));
}
template<typename T>
inline T corteMinimo<T>::sacarNodoAleatorio(Grafo<T>& grafoParam, int cantidadDeNodos)
{
    
        T Aux = T();
        if (cantidadDeNodos > 0) {
            string* vec = grafoParam.getVectorNodos();
            int indice = rand() % cantidadDeNodos;
            Aux = vec[indice];
        }
        return Aux;
    
}
template<typename T>
inline T corteMinimo<T>::sacarAdyacenciaAleatoria(Grafo<T>& grafoParam, T nodo)
{
    
        T Aux = T();

        Lista8<Vertice<T>>* lista = grafoParam.getHash().accederHash(nodo);
        if (lista != NULL && lista->getPrimero() != NULL) {
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
template<typename T>
inline void corteMinimo<T>::leerArchivo()
{
    grafoOriginal.LeerArchivo();
    cout << "Grafo cargado con " << grafoOriginal.getNumDeVerticesActuales() << " nodos" << endl;
}

template<typename T>
inline Grafo<T> corteMinimo<T>::getGrafo()
{
    return grafoOriginal;
}

template<typename T>
inline void corteMinimo<T>::FuncionKarger()
{
    // Iniciar medición de tiempo
    auto inicio = high_resolution_clock::now();

    int mejorCorte = INT_MAX;
    int iteracionMejor = 0;
    int b = 0;
    leerArchivo();

   

    for (int i = 0; i < 50000; i++)
    {
        cout << "\n--- Iteracion " << (i + 1) << " ---" << endl;

        Grafo<T> grafoCopia = grafoOriginal;

        

        int contracciones = 0;

        while (grafoCopia.getNumDeVerticesActuales() > 2)
        {
            string nodo = sacarNodoAleatorio(grafoCopia, grafoCopia.getNumDeVerticesActuales());
            string ady = sacarAdyacenciaAleatoria(grafoCopia, nodo);
            if(b==0)  cout << "Nodos iniciales: " << "nodo: " << nodo << " Adyacente: " << ady << endl;
           
            if (!ady.empty()) 
            {
                b++;
                grafoCopia.ContraerAristas(nodo, ady);
                contracciones++;
            }
            else 
            {
                
                break;
            }
        }

        int corteActual = 0;
        if (grafoCopia.getNumDeVerticesActuales() == 2) 
        {
            b = 0;
            string* nodos = grafoCopia.getVectorNodos();
            if (nodos != NULL) {
                Lista8<Vertice<T>>* lista = grafoCopia.getHash().accederHash(nodos[0]);
                if (lista != NULL && lista->getPrimero() != NULL) 
                {
                    Caja<Vertice<T>>* vertice = lista->getPrimero();
                    while (vertice != NULL) {
                        if (vertice->getValor().getNombre() == nodos[0]) 
                        {
                            corteActual = vertice->getValor().getAdyacentes().getContador();
                            break;
                        }
                        vertice = vertice->getSiguiente();
                    }
                }
            }
        }
        cout << "Grafo Final" << endl;
        grafoCopia.MostrarGrafo();
        cout << "Contracciones: " << contracciones << ", Corte: " << corteActual;

        if (corteActual < mejorCorte) 
        {
            mejorCorte = corteActual;
            iteracionMejor = i + 1;
            cout << " ¡NUEVO MEJOR CORTE!";
        }
        cout << endl;
    }

    // Finalizar medición de tiempo
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    // Mostrar resultados
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Mejor corte minimo: " << mejorCorte << " aristas" << endl;
    cout << "Iteracion del mejor corte: " << iteracionMejor << endl;
    cout << "Tiempo total de ejecucion: " << duracion.count() << " milisegundos" << endl;
    cout << "Tiempo total de ejecucion: " << duracion.count() / 1000.0 << " segundos" << endl;
}


