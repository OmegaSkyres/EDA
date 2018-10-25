//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	int numeros, maximo = 0, posMax = 0, suma = 0;
	cin >> numeros;
	vector<int> datos(numeros);
	for (int i = 0; i < numeros; i++) {
		cin >> datos[i];
	}
	maximo = datos[0];
	if (datos.empty()) {
		suma = 0;
	}
	else {
		for (int i = 0; i < numeros - 1; i++) {
			if (datos[i] < datos[i + 1]) {
				maximo = datos[i + 1];
				posMax = i;
			}
		}
		if (datos[posMax] != 0) {
			for (int i = 0; i < numeros; i++) {
				if (datos[i] != maximo) suma += datos[i];
			}
		}
		
			
	}
	cout << suma << endl;

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
