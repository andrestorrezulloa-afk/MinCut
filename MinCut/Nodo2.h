#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Nodo2
{
private:
    int key; // Cantidad de vertices   
    bool marca;
    T Vo;     // Vértice Origen
    T Vd;     // Vértice Destino
public:
    Nodo2(T key, T Vo, T Vd);
    ~Nodo2();

    T getKey();        // Get distancia/peso
    bool getMarca();
    T getVo();         // Get vértice origen
    T getVd();         // Get vértice destino

    void setKey(T key);
    void setMarca(bool marca);
    void setVo(T Vo);
    void setVd(T Vd);
};

template<class T>
inline Nodo2<T>::Nodo2(T key, T Vo, T Vd)
{
    this->key = key;
    this->Vo = Vo;
    this->Vd = Vd;
    this->marca = true;
}

template<class T>
inline Nodo2<T>::~Nodo2()
{
}

template<class T>
inline T Nodo2<T>::getKey()
{
    return key;
}

template<class T>
inline bool Nodo2<T>::getMarca()
{
    return marca;
}

template<class T>
inline T Nodo2<T>::getVo()
{
    return Vo;
}

template<class T>
inline T Nodo2<T>::getVd()
{
    return Vd;
}

template<class T>
inline void Nodo2<T>::setKey(T key)
{
    this->key = key;
}

template<class T>
inline void Nodo2<T>::setMarca(bool marca)
{
    this->marca = marca;
}

template<class T>
inline void Nodo2<T>::setVo(T Vo)
{
    this->Vo = Vo;
}

template<class T>
inline void Nodo2<T>::setVd(T Vd)
{
    this->Vd = Vd;
}