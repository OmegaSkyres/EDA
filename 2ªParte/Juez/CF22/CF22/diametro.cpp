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



int height(bintree<char>arbol, int& ans)
{
	if (arbol.empty())
		return 0;

	int left_height = height(arbol.left(), ans);

	int right_height = height(arbol.right(), ans);

	// update the answer, because diameter of a 
	// tree is nothing but maximum value of 
	// (left_height + right_height + 1) for each node 
	ans = max(ans, 1 + left_height + right_height);

	return 1 + max(left_height, right_height);
}

int diameter(bintree<char>arbol)
{
	if (arbol.empty())
		return 0;
	int maximo = 0; // This will store the final answer 
	int height_of_tree = height(arbol, maximo);
	return maximo;
}

void resuelveCaso() {
	char elemento = '.';
	bintree<char> arbol;
	arbol = leerArbol(elemento);
	int resultado = diameter(arbol);
	cout << resultado << endl;
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
