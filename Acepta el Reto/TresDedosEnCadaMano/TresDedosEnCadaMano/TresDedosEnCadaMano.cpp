//Roberto Torres Prensa


#include <iostream>
#include <fstream>
using namespace std;

void resuelve(int n) {
	int base;

	base = n / 6;
	if (n >= 6) {
		resuelve(base);
	}

	cout << n % 6;
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