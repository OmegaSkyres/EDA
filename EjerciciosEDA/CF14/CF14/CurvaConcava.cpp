//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	vector<int> vector;
	int nElementos;
	cin >> nElementos;
	for (int i = 0; i < nElementos; i++) {
		cin >> vector[i];
	}
}

	int buscaBin(vector<int> vector, int a, int b) {
		// Pre : v esta ordenado entre 0 . . longitud (v)1
		// ( 0 <= a <= l o n g i t u d ( v ) ) && ( -1 <= b <= longitud(v) - 1) && (a <= b + 1)
			// todos l o s elementos a la izquie rda de ’a ’ son <= x
			// todos l o s elementos a la derecha de ’b ’ son > x
			int p, m;
		if (a == b + 1)
			p = a - 1;
		else { // a <= b
			m = (a + b) / 2;
			if (vector[m] <= x)
				p = buscaBin(vector, x, m + 1, b);
	
			else
				p = buscaBin(vector, x, a, m - 1);
		}
		return p;
		// Post : devuelve el mayor i (0 <= i <= longitud(v) - 1) que cumple v[i] <= x
		// s i x es menor que todos l o s elementos de v , devuelve 1
	}
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado}

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