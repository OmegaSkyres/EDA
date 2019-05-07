//Roberto Torres Prensa


// Altura de un árbol

// Construye un árbol binario a partir de la entrada y después
// calcula de forma recursiva su altura
// O(N)

// versión con extensión de la clase bintree del TAD dado en clase (Alberto Verdejo)

#include <fstream>
#include <iostream>
#include <algorithm>

#include "treemap_eda.h"
using namespace std;



// Roberto Torres Prensa


bool resuelveCaso() {

	//Leer caso de prueba
	int numCasos;
	string autor, resultado, trash;
	map<string, int> clase;
	cin >> numCasos;
	if (numCasos == 0)
		return false;
	getline(cin, trash);
	for (int i = 0; i < numCasos; i++) {
		getline(cin, autor);
		clase.insert({ autor, 0 });
		getline(cin, resultado);
		if (resultado == "CORRECTO") {
			clase[autor]++;
		}
		else {
			clase[autor]--;
		}
	}

	for (auto const& cv : clase) {
		if (cv.valor != 0) {
			cout << cv.clave << ", " << cv.valor << endl;
		}
	}

	cout << "---" << endl;

	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}