#include <iostream>
#include <ctime>
#include "Grafo.h"
#include "corteMinimo.h"

using namespace std;

int main()
{
    
	corteMinimo<string> corte;
	corte.leerArchivo();
	
    corte.FuncionKarger();
	corte.getGrafo().MostrarGrafo();
	return 0;
}
