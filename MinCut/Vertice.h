#pragma once
#include "Lista8.h"
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class Vertice
{
private:
    T Nombre;
    Lista8<string> Adyacentes;
public:
    Vertice();
    Vertice(T Nombre);
    Vertice(Vertice<T>& otra);
    Vertice<T>& operator=(Vertice<T>& otra);

    T getNombre();
    void setNombre(T Nombre);
    Lista8<string>& getAdyacentes();

    bool operator==(Vertice<T>& otro)
    {
        return Nombre == otro.Nombre;
    }
};

template<typename T>
Vertice<T>::Vertice()
{
    this->Nombre = T();
}

template<typename T>
Vertice<T>::Vertice(T Nombre)
{
    this->Nombre = Nombre;
}

template<typename T>
Vertice<T>::Vertice(Vertice<T>& otra) : Nombre(otra.Nombre), Adyacentes(otra.Adyacentes)
{
}

template<typename T>
Vertice<T>& Vertice<T>::operator=(Vertice<T>& otra)
{
    if (this != &otra) {
        this->Nombre = otra.Nombre;
        this->Adyacentes = otra.Adyacentes;
    }
    return *this;
}

template<typename T>
inline T Vertice<T>::getNombre()
{
    return Nombre;
}

template<typename T>
void Vertice<T>::setNombre(T Nombre)
{
    this->Nombre = Nombre;
}

template<typename T>
Lista8<string>& Vertice<T>::getAdyacentes()
{
    return Adyacentes;
}