//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(int numeroP) {
	int contadorG = 0, contadorRepeticionesG = 0, contadorJ = 0, maximoG = 0;
	vector<int> datos(numeroP);
	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	for (int i = 0; i < numeroP; i++) {
		if (datos[i] > 0) {
			contadorG++;
		}
		else {
			contadorG = 0;
		}
		if (contadorG > maximoG ) {
			maximoG = contadorG;
			contadorRepeticionesG = 1;
			contadorJ = i + 1;
		}
		else if (contadorG == maximoG && contadorG > 0) {
			contadorRepeticionesG++;
			contadorJ = i + 1;
		}
	}
	contadorJ = numeroP - contadorJ;

	cout << maximoG << " " << contadorRepeticionesG << " " << contadorJ << endl;

	
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numeroP;
	// Resolvemos
	while (std::cin >> numeroP) {
		resuelveCaso(numeroP);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}