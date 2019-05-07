//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include "hashmap_eda.h"
using namespace std;



void resuelveCaso() {
	unordered_map<int, int> emisiones;
	int numCapitulos, capitulo, repeticiones = 0, contador = 0, longMax = 0;
	cin >> numCapitulos;
	for (int i = 0; i <= numCapitulos; i++) {
		cin >> capitulo;
		if (emisiones.count(capitulo) > 0 && repeticiones <= emisiones[capitulo]) { // Miramos si existe alguna emision de ese episodio y si el numero de repeticiones de la emision es menor o igual al numero de emisiones de ese episodio.
			contador = 0;
			repeticiones = emisiones[capitulo] + 1;	
		}

		contador++;
		emisiones[capitulo] = i;
		if (contador > longMax) {
			longMax = contador;
		}

	}
	cout << longMax << endl;
	   
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}