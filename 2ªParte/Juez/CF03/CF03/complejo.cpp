

//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "complejo.h"



bool resuelveCaso() {
	complejo c, aux;
	int i = 0;
	bool ok = true;
	cin >> c;
	aux = c;
	int n = c.getNumIteraciones();
	while (ok && i < n) {
		if (c%c < 2) {
			ok = false;
		}
		else {
			c = (c*c) + aux;
		}
		i++;
	}
	return ok;
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
			if (resuelveCaso()) {
				cout << "SI" << "/n";
			}
			else {
				cout << "NO" << "/n";
			}
		}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
#endif
		return 0;
	}

