//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	bool ok = true;
	for (int i = numeroP - 1; i > 0; i--) {
		if (datos[i] < datos[i - 1]) {
			j = k
		}
	}
	cout << "NO" << endl,
	cout << "SI" << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	int numerosV, valorP, contadorC = 0, i = 0;
	cin >> numerosV >> valorP;
	vector<int> datos(numerosV);
	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
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