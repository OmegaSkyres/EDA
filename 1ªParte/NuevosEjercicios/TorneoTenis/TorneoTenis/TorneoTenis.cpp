//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int torneoG(vector<string> datos, int a, int b, const int round, int& numPartidos) {
	int min, m;
	if (a + 1 == b){ // Con solo un elemento es el propio elemento
		if (datos[a] == "NP" && datos[a + 1] == "NP") {
			numPartidos = 0;
		}
		else {
			numPartidos = 1;
		}
	}
	else { // Miramos en que mitad
		m = (a + b) / 2;
		torneoG(datos, 0, m, numPartidos);
		torneoG(datos, m + 1, b, numPartidos);
		
	}
	return numPartidos;
	// Post : devuelve el mayor i (0 <= i <= longitud(v) - 1) que cumple v[i] <= x
	// s i x es menor que todos l o s elementos de v , devuelve 1
}


void torneo(const vector<string> datos, const int numElementos, const int round) {
	int numPartidos = 0;
	cout << torneoG(datos, 0, datos.size(), round ,numPartidos);;

}



int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numElementos, ronda;
	std::cin >> numElementos >> ronda;
	vector<string> datos(numElementos);
	// Resolvemos
	for (int i = 0; i < numElementos; ++i) {
		cin >> datos[i];
	}
	torneo(datos, datos.size(), ronda);


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}