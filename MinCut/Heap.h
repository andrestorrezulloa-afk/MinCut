#pragma once
#include "Nodo2.h"
#include <algorithm>
#include <fstream>
#define TAM 100

using namespace std;

template <class T>
class Heap
{
private:
    Nodo2<T>* vec[TAM];
    int ultimo;
public:
    Heap();
    ~Heap();
    void RecuperarArribaAbajo(int pos);
    void RecuperarAbajoArriba(int pos);
    void Insertar(T distancia, T Vo, T Vd);
    Nodo2<T>* Sacar();  
    bool EstaVacia();
    int getCantidadAristas();
    void mostrarCola();
};

template<class T>
inline Heap<T>::Heap()
{
    ultimo = 0;
    for (int i = 0; i < TAM; i++) {
        vec[i] = NULL;
    }
}

template<class T>
inline Heap<T>::~Heap()
{
    for (int i = 1; i <= ultimo; i++) {
        delete vec[i];
    }
}

template<class T>
inline void Heap<T>::RecuperarArribaAbajo(int pos)
{
    int menor = pos;
    int hijoIzq = 2 * pos;
    int hijoDer = 2 * pos + 1;


    if (hijoIzq <= ultimo && vec[hijoIzq]->getKey() < vec[menor]->getKey())
        menor = hijoIzq;

    if (hijoDer <= ultimo && vec[hijoDer]->getKey() < vec[menor]->getKey())
        menor = hijoDer;

    if (menor != pos) {
        swap(vec[pos], vec[menor]);
        RecuperarArribaAbajo(menor);
    }
}

template<class T>
inline void Heap<T>::RecuperarAbajoArriba(int pos)
{
    if (pos > 1) {
        int padre = pos / 2;

        if (vec[pos]->getKey() < vec[padre]->getKey()) {
            swap(vec[pos], vec[padre]);
            RecuperarAbajoArriba(padre);
        }
    }
}

template<class T>
inline void Heap<T>::Insertar(T distancia, T Vo, T Vd)
{
    if (ultimo == 0) {
        ultimo = 1;
        vec[ultimo] = new Nodo2<T>(distancia, Vo, Vd);
    }
    else if (ultimo < TAM - 1) {
        ultimo += 1;
        vec[ultimo] = new Nodo2<T>(distancia, Vo, Vd);
        RecuperarAbajoArriba(ultimo);
    }
    else {
        cout << "Cola de prioridad llena" << endl;
    }
}

template<class T>
inline Nodo2<T>* Heap<T>::Sacar()
{
    if (ultimo == 0) {
        return NULL;
    }

    Nodo2<T>* minElemento = vec[1];

    if (ultimo == 1) {
        vec[1] = NULL;
        ultimo = 0;
    }
    else {
        vec[1] = vec[ultimo];
        vec[ultimo] = NULL;
        ultimo -= 1;
        RecuperarArribaAbajo(1);
    }

    return minElemento;
}

template<class T>
inline bool Heap<T>::EstaVacia()
{
    return ultimo == 0;
}

template<class T>
inline int Heap<T>::getCantidadAristas()
{
    return ultimo;
}

template<class T>
inline void Heap<T>::mostrarCola()
{
    cout << "Cola de Prioridad (Distancia-Vo-Vd):" << endl;
    for (int i = 1; i <= ultimo; i++) {
        cout << vec[i]->getKey() << " - " << vec[i]->getVo()
            << " - " << vec[i]->getVd() << endl;
    }
    cout << endl;
}