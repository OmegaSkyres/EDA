// Altura de un árbol

// Construye un árbol binario a partir de la entrada y después
// calcula de forma recursiva su altura
// O(N)

// versión con extensión de la clase bintree del TAD dado en clase (Alberto Verdejo)

#include <fstream>
#include <iostream>
#include <algorithm>

#include "bintree_eda.h"
using namespace std;

/*
template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;
	public:
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}
	int altura() {
		return altura(this->raiz);
	}

	private:
	int altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura(r->left), altura(r->right));
		}
	}
};	


// lee un árbol binario de la entrada estándar
// Transparencia 10 del tema "Tipos de datos arborescentes" 
template <typename T>
bintree_ext<T> leerArbolext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbolext(vacio);
		auto dr = leerArbolext(vacio);
		return { iz, raiz, dr };
	}
}
*/

int calculaAltura(bintree<char> arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		return 1 + std::max(calculaAltura(arbol.left()), calculaAltura(arbol.right()));
	}
}

int calculaNumeroNodos(bintree<char> arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		int izq = calculaNumeroNodos(arbol.left());
		int der = calculaNumeroNodos(arbol.right());
		return 1 + izq + der;
	}
}

int calculaNumeroHojas(bintree<char> arbol) {
	int hoja = 0;
	if (arbol.empty()) {
		return 0;
	}
	else if (arbol.left().empty() && arbol.right().empty()){
		return 1;
	}
	else {
		return calculaNumeroHojas(arbol.left()) + calculaNumeroHojas(arbol.right());
	}
}

void resuelveCaso() {
	int nElementos;
	bintree<char> arbol;
	arbol = leerArbol('.');
	cout << calculaNumeroNodos(arbol) << " " << calculaNumeroHojas(arbol) << " " << calculaAltura(arbol) << endl;
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
