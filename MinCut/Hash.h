#pragma once
#include <cmath>
#include <fstream>
#include <sstream>
#include "Lista8.h"
#include <iostream>

#define TAM 401
#define A 0.61803398875 

using namespace std;

template <class T>
class Hash
{
private:
    Lista8<T> Vec[TAM];
public:
    Hash();
    Hash(Hash<T>& otra);
    Hash<T>& operator=(Hash<T>& otra);
    ~Hash();
    int FuncionHash(string Nombre);
    Lista8<T>* accederHash(string& nombre);
    void Insertar(T objeto);
    bool Eliminar(string nombre);
    void MostrarHash();
    void MostrarHash2(string vec[200], int cantidad);
};

template<class T>
Hash<T>::Hash() {}

template<class T>
Hash<T>::Hash(Hash<T>& otra)
{
    for (int i = 0; i < TAM; i++)
    {
        this->Vec[i] = otra.Vec[i];
    }
}

template<class T>
Hash<T>& Hash<T>::operator=(Hash<T>& otra)
{
    if (this != &otra) {
        for (int i = 0; i < TAM; i++)
        {
            this->Vec[i] = otra.Vec[i];
        }
    }
    return *this;
}

template<class T>
Hash<T>::~Hash() {}

template<class T>
int Hash<T>::FuncionHash(string Nombre)
{
    long long pos = 0;
    for (int i = 0; i < (int)Nombre.length(); i++) {
        pos += Nombre[i] * pow(2, i);
    }
    pos = pos % TAM;
    return abs((int)pos);
}

template<class T>
inline Lista8<T>* Hash<T>::accederHash(string& nombre)
{
    return &Vec[FuncionHash(nombre)];
}

template<class T>
void Hash<T>::Insertar(T objeto)
{
    int pos = FuncionHash(objeto.getNombre());
    Vec[pos].Insertar_Fin(objeto);
}

template<class T >
bool Hash<T>::Eliminar(string nombre)
{
    return Vec[FuncionHash(nombre)].EliminarValor(nombre);
}

template<class T>
void Hash<T>::MostrarHash()
{
    for (int i = 0; i < TAM; i++)
    {
        Caja<T>* auxNodo = Vec[i].getPrimero();
        while (auxNodo != NULL)
        {
            T& nodo = auxNodo->getValor();
            cout << nodo.getNombre() << ": ";
            nodo.getAdyacentes().MostrarListaConsola();
            auxNodo = auxNodo->getSiguiente();
        }
    }
}

template<class T>
void Hash<T>::MostrarHash2(string vec[200], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        Caja<T>* auxNodo = Vec[FuncionHash(vec[i])].getPrimero();
        while (auxNodo != NULL)
        {
            T& nodo = auxNodo->getValor();
            cout << nodo.getNombre() << ": ";
            nodo.getAdyacentes().MostrarListaConsola();
            auxNodo = auxNodo->getSiguiente();
        }
    }
}