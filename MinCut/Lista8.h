#pragma once
#include <iostream>
#include "Caja.h"
using namespace std;

template<typename T>
class Lista8
{
private:
    Caja<T>* primero;
    Caja<T>* ultimo;
    int contador;
public:
    Lista8();
    void Insertar_Fin(T valor);
    void Insertar_Inicio(T valor);

    bool Eliminar_Fin();
    void Eliminar_Inicio();
    void EliminarTodo();

    Caja<T>* getPrimero();
    Caja<T>* getUltimo();
    Caja<T>* getPosicion(int posicion);

    Caja<T>* buscar(T valor, Caja<T>*& aux);
    bool buscarRec(T valor, Caja<T>*& aux);

    bool EliminarValor(T valor);
    int getContador();
    void MostrarListaConsola(); 
};

template<typename T>
inline Lista8<T>::Lista8()
{
    this->primero = NULL;
    this->ultimo = NULL;
    this->contador = 0;
}

template<typename T>
inline void Lista8<T>::Insertar_Fin(T valor)
{
    if (primero == NULL)
    {
        primero = new Caja<T>(valor, NULL, NULL);
        ultimo = primero;
        contador++;
    }
    else {
        ultimo->setSiguiente(new Caja<T>(valor, ultimo, NULL));
        ultimo = ultimo->getSiguiente();
        contador++;
    }
}

template<typename T>
inline void Lista8<T>::Insertar_Inicio(T valor)
{
    if (primero == NULL) {
        primero = new Caja<T>(valor, NULL, NULL);
        ultimo = primero;
        contador++;
    }
    else {
        Caja<T>* aux = primero;
        primero = new Caja<T>(valor, NULL, primero);
        aux->setAnterior(primero);
        contador++;
    }
}

template<typename T>
inline bool Lista8<T>::Eliminar_Fin()
{
    bool control = false;

    if (primero == ultimo && primero != NULL) {
        delete primero;
        primero = NULL;
        ultimo = NULL;
        control = true;
        contador--;
    }
    else {
        if (primero != NULL) {
            Caja<T>* aux = ultimo;
            ultimo = ultimo->getAnterior();
            if (ultimo) ultimo->setSiguiente(NULL);
            delete aux;
            control = true;
            contador--;
        }
    }
    return control;
}

template<typename T>
inline void Lista8<T>::Eliminar_Inicio()
{
    if (primero == ultimo && primero != NULL) {
        delete primero;
        primero = NULL;
        ultimo = NULL;
        contador--;
    }
    else {
        if (primero != NULL) {
            Caja<T>* aux = primero;
            primero = primero->getSiguiente();
            if (primero) primero->setAnterior(NULL);
            delete aux;
            contador--;
        }
    }
}

template<typename T>
inline void Lista8<T>::EliminarTodo()
{
    while (primero != NULL) {
        Eliminar_Inicio();
    }
    contador = 0;
}

template<typename T>
inline Caja<T>* Lista8<T>::getPrimero()
{
    return primero;
}

template<typename T>
inline Caja<T>* Lista8<T>::getUltimo()
{
    return ultimo;
}

template<typename T>
inline Caja<T>* Lista8<T>::getPosicion(int posicion)
{
    Caja<T>* aux = primero;
    int cont = 0;
    while (cont != posicion && aux != NULL) {
        aux = aux->getSiguiente();
        cont++;
    }
    return aux;
}

template<typename T>
inline Caja<T>* Lista8<T>::buscar(T valor, Caja<T>*& aux)
{
    Caja<T>* control = NULL;
    while (aux != NULL) 
    {
        if (valor == aux->getValor()) 
        {
            control = aux;
            return control;
        }
        aux = aux->getSiguiente();
    }
    return control;
}

template<typename T>
inline bool Lista8<T>::buscarRec(T valor, Caja<T>*& aux)
{
    if (aux == NULL) return false;
    if (valor == aux->getValor()) return true;
    aux = aux->getSiguiente();
    return buscarRec(valor, aux);
}

template<typename T>
inline bool Lista8<T>::EliminarValor(T valor)
{
    Caja<T>* aux = primero;
    bool control = false;

    if (primero == NULL) {
        return false;
    }
    Caja<T>* resul = buscar(valor, aux);
    if (resul != NULL) {
        if (resul == primero) {
            Eliminar_Inicio();
            control = true;
        }
        else if (resul == ultimo) {
            Eliminar_Fin();
            control = true;
        }
        else {
            Caja<T>* auxAnterior = resul->getAnterior();
            Caja<T>* auxSiguiente = resul->getSiguiente();
            auxAnterior->setSiguiente(auxSiguiente);
            auxSiguiente->setAnterior(auxAnterior);
            delete resul;
            control = true;
            contador--;
        }
    }
    return control;
}

template<typename T>
inline int Lista8<T>::getContador()
{
    return contador;
}

template<typename T>
inline void Lista8<T>::MostrarListaConsola()
{
    Caja<T>* aux = primero;
    bool first = true;
    while (aux != NULL)
    {
        if (!first) cout << ", ";
        cout << aux->getValor(); 
        first = false;
        aux = aux->getSiguiente();
    }
    cout << endl;
}
