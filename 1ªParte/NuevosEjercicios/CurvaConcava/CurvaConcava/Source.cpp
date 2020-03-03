//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int curvaConcavaG(vector<int> datos, int a, int b) {
	if (a == b) {
		return datos[a];
	}
	if (a + 1 == b) {
		if (datos[a] > datos[b]) {
			return datos[b];
		}
		else {
			return datos[a];
		}
	}
	else {
		int mitad = (a + b) / 2;
		if (datos[mitad] < datos[mitad + 1] && datos[mitad] > datos[mitad-1]) {
			return curvaConcavaG(datos, a, mitad-1);
		}
		else if (datos[mitad] > datos[mitad + 1] && datos[mitad] < datos[mitad - 1]) {
			return curvaConcavaG(datos, mitad+1, b);
		}
		else {
			return datos[mitad];
		}
	}
}

void curvaConcava(vector<int> datos, int numElementos) {
	cout << curvaConcavaG(datos, 0, numElementos-1) << endl;

}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numElementos;
	while (std::cin >> numElementos) {	
		vector<int> datos(numElementos);
		for (int i = 0; i < numElementos; i++) {
			cin >> datos[i];
		}
		curvaConcava(datos, numElementos);
	}
	return 0;
}