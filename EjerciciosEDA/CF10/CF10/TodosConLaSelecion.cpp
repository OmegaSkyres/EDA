//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	int numeroP, contadorG = 0, contadorRepeticionesG = 0, contadorJ = 0;
	cin >> numeroP;
	vector<int> datos(numeroP);
	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	for (int i = 0; i < numeroP - 1; i++) {
		if (datos[i] > 0 && datos[i + 1] > 0) {
			contadorG = contadorG++;
		}
	}
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
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