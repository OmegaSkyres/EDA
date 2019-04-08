// Altura de un árbol

// Construye un árbol binario a partir de la entrada y después
// calcula de forma recursiva su altura
// O(N)

// versión con extensión de la clase bintree del TAD dado en clase (Alberto Verdejo)

//Roberto Torres Prensa

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;


template <typename T>
T calculaMinimo(bintree<T>arbol) {
	T minimo = arbol.root();
	if (arbol.empty()) {
		return 0;
	}
	else {
		if (arbol.right().empty() && arbol.left().empty()) {
			 minimo = arbol.root();
		}
		else {
			T izq = calculaMinimo(arbol.left());
			if (minimo > izq) {
				minimo = izq;
			}
			T der = calculaMinimo(arbol.right());
			if (minimo > der) {
				minimo = der;
			}

		}
	}
	return minimo;
	
}
bool resuelveCaso() {
	string caso;
	cin >> caso;
	if (!std::cin) return false;
	
	if (caso == "N") {
		int elemento = -1;
		bintree<int> arbol;
		arbol = leerArbol(elemento);
		cout << calculaMinimo(arbol) << endl;
	}
	else if (caso == "P") {
		string palabra = "#";
		bintree<string> arbol;
		arbol = leerArbol(palabra);
		cout << calculaMinimo(arbol) << endl;
	}
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
