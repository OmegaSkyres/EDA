//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int elementoPerdidoG(const vector<int> datos, const vector<int> datos2, const int a, const int b) {
	if (a == b) {
		return datos[a];
	}
	if (a + 1 == b) {
		if (datos[a] != datos2[a]) {
			return datos[a];
		}
		else {
			return datos[b];
		}
	}
	else {
		int mitad = (a + b) / 2;
		if (datos[mitad] >= datos2[mitad]) {
			return elementoPerdidoG(datos, datos2, mitad, b);
		}
		else if (datos[mitad] < datos2[mitad]) {
			return elementoPerdidoG(datos, datos2,a, mitad);
		}
	}
}


void elementoPerdido(const vector<int> datos, const vector<int> datos2, const int numElementos) {
	cout << elementoPerdidoG(datos, datos2, 0, numElementos - 1) << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	unsigned int numCasos;
	int numElementos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numElementos;
		vector<int> datos(numElementos);
		vector<int> datos2(numElementos - 1);
		for (int i = 0; i < numElementos; i++) {
			cin >> datos[i];
		}
		for (int i = 0; i < numElementos - 1; i++) {
			cin >> datos2[i];
		}
		elementoPerdido(datos, datos2, numElementos);

		
	}

	return 0;
}