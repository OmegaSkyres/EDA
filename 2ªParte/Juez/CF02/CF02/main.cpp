#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "pelicula.cpp"
#include "horas.cpp"

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	if (numCasos == 0) { //Termina

	}
	else {
		for (int i = 0; i < numCasos; ++i) {}
		resuelveCaso(numCasos);
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
