//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int buscaBin(vector<int> vector, int a, int b) {
	int min, m;
	// Pre : v esta ordenado entre 0 . . longitud (v)1
	// ( 0 <= a <= l o n g i t u d ( v ) ) && ( -1 <= b <= longitud(v) - 1) && (a <= b + 1)
		// todos l o s elementos a la izquie rda de ’a ’ son <= x
		// todos l o s elementos a la derecha de ’b ’ son > x
	if (a + 1 == b) // Con solo un elemento es el propio elemento
		min = vector[a];

	else if (a + 2 == b) { // Con 2 elementos es el menor
		if (vector[a] < vector[a + 1]) {
			min = vector[a];
		}
		else {
			min = vector[a + 1];
		}
	}
	else { // Miramos en que mitad
		m = (a + b) / 2;
		if (vector[m] < vector[m + 1] && vector[m] > vector[m - 1])
			min = buscaBin(vector, a, m - 1);
		else if (vector[m] > vector[m + 1] && vector[m] < vector[m - 1]) {
			min = buscaBin(vector, m + 1, b);
		}

		else
			min = vector[m];
	}
	return min;
	// Post : devuelve el mayor i (0 <= i <= longitud(v) - 1) que cumple v[i] <= x
	// s i x es menor que todos l o s elementos de v , devuelve 1
}


void resuelveCaso() {
	int min, elemento;
	vector<int> vector;
	int nElementos;
	cin >> nElementos;
	for (int i = 0; i < nElementos; i++) {
		cin >> elemento;
		vector.push_back(elemento);
	}
	min = buscaBin(vector, 0, vector.size());
	cout << min << endl;

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