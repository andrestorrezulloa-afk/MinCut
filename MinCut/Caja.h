#pragma once
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
class Caja
{
private:
    T valor;
    Caja<T>* siguiente;
    Caja<T>* anterior;

public:
    Caja();
    Caja(T& valor, Caja<T>* anterior = nullptr, Caja<T>* siguiente = nullptr);
    Caja(Caja<T>& otra);
    Caja<T>& operator=(Caja<T>& otra);

    T& getValor();
    T getValorT() { return valor; }
    Caja<T>* getSiguiente();
    Caja<T>* getAnterior();
    void setSiguiente(Caja<T>* CajaE);
    void setAnterior(Caja<T>* CajaE);
    void setValor(T valor);
};

template<typename T>
inline Caja<T>::Caja()
{
    this->anterior = nullptr;
    this->siguiente = nullptr;
    this->valor = T();
}

template<typename T>
inline Caja<T>::Caja(T& valor, Caja<T>* anterior, Caja<T>* siguiente)
{
    this->anterior = anterior;
    this->siguiente = siguiente;
    this->valor = valor;
}

template<typename T>
inline Caja<T>::Caja(Caja<T>& otra)
{
    this->valor = otra.valor;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

template<typename T>
inline Caja<T>& Caja<T>::operator=(Caja<T>& otra)
{
    if (this != &otra) {
        this->valor = otra.valor;
    }
    return *this;
}

template<typename T>
inline void Caja<T>::setSiguiente(Caja<T>* CajaE)
{
    this->siguiente = CajaE;
}

template<typename T>
inline void Caja<T>::setAnterior(Caja<T>* CajaE)
{
    this->anterior = CajaE;
}

template<typename T>
inline T& Caja<T>::getValor()
{
    return valor;
}

template<typename T>
inline Caja<T>* Caja<T>::getSiguiente()
{
    return siguiente;
}

template<typename T>
inline Caja<T>* Caja<T>::getAnterior()
{
    return anterior;
}

template<typename T>
inline void Caja<T>::setValor(T valor)
{
    this->valor = valor;
}