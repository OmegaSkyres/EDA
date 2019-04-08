// Altura de un �rbol

// Construye un �rbol binario a partir de la entrada y despu�s
// calcula de forma recursiva su altura
// O(N)

// versi�n con extensi�n de la clase bintree del TAD dado en clase (Alberto Verdejo)

#include <fstream>
#include <iostream>
#include <algorithm>

#include "treemap_eda.h"
using namespace std;



// Roberto Torres Prensa


bool resuelveCaso() {

	//Leer caso de prueba
	int numCasos;
	getline(cin, numCasos);

	if (!std::cin)
		return false;


	//Resolver problema
	//Escribir resultado
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}