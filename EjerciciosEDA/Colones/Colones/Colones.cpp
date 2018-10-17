//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//{P: true}
void resuelveCaso() {
	int numeroP, contadorC = 0, i = 0, aux = 0;
	cin >> numeroP;
	vector<int> datos(numeroP);
	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	if (!datos.empty()) {
		aux = datos[numeroP - 1];
		for (i = numeroP - 1; i > 0; i--) {
			if (aux < datos[i - 1]) {
				contadorC++;
			}

			if (aux > datos[i - 1]) {
				aux = datos[i - 1];
			}
		}
	}
	
	cout << contadorC << endl;
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