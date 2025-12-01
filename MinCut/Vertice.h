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
    T getNombre();
    void setNombre(T Nombre);
    Lista8<string>& getAdyacentes();

    bool operator==(const Vertice<T>& otro) const {
        return Nombre == otro.Nombre;
    }

    template<typename U>
    friend ostream& operator<<(ostream& os, const Vertice<U>& v);
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

template<typename U>
ostream& operator<<(ostream& os, const Vertice<U>& v)
{
    os << v.Nombre;
    return os;
}
