// Francisco Calero Velasco
// E09
#include <iostream>
#include <iomanip>
#include <fstream>
#include "polinomio.h"
#include <stdexcept>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
	polinomio pol; 
	int c, e; 
	std::cin >> c >> e; 

    if (!std::cin)
        return false;

	while (c != 0 || e != 0)
	{
		pol.add(c, e); 
		std::cin >> c >> e;
	}

	int numDatosEv;
	std::cin >> numDatosEv;
	int x; 

	for (int i = 0; i < numDatosEv; i++)
	{
		std::cin >> x; 
		std::cout << pol.evaluar(x) << " ";
	}
	std::cout << std::endl; 
    return true;
}

int main() 
{
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 

		 while (resuelveCaso());
	 
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}