//Roberto Torres Prensa


#include <iostream>
#include <fstream>
using namespace std;

void resuelve(long long int base) {
	int resultado = 0;
	if (base < 6) { //Caso Base
		resultado = base;
	}
	else { //Caso Recursivo
		resuelve(base / 6);
		
		
	}
	cout << resultado % 6;
}

void resuelveCaso() {
	long long int base;
	cin >> base;
	resuelve(base);
	cout << endl;
}

int main() {
	// Para la entrada por fichero.
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}