#include <iostream>
#include <ctime>
#include "Grafo.h"
#include "corteMinimo.h"

using namespace std;

int main()
{
    Grafo<string> g;
    g.LeerArchivo();
    g.MostrarGrafo();

    corteMinimo<string> cm;   // constructor clásico
    cm.setGrafo(&g);          // asignás el grafo después

    for (int i = 0; i < 3;i++) {

    string nodo = cm.sacarNodoAleatorio();
    cout << "\nNodo aleatorio seleccionado: " << nodo << endl;

    string ady = cm.sacarAdyacenciaAleatoria(nodo);
    if (!ady.empty())
        cout << "Adyacencia aleatoria del nodo " << nodo << ": " << ady << endl;
    else
        cout << "El nodo " << nodo << " no tiene adyacencias." << endl;

    
        g.ContraerAristas(nodo, ady);
        g.MostrarGrafo();
        cout << endl;
    }
   
    return 0;
}

