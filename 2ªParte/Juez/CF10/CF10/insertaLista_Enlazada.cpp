﻿//Roberto Torres Prensa

#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

template <class T>
class Lista : public queue<T> {
	using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
	void print(std::ostream & o = std::cout) const {
		if (!this->empty()) {// la lista no est� vac�a
			Nodo * nodo = this->prim;
			for (int i = 0; i < this->nelems; i++) {
				cout << nodo->elem << " ";
				nodo = nodo->sig;
			}
		}
	}

	// Duplicar los nodos de una lista
	void insertaEnListaEnlazada(Lista<int> lista2) {
		

		// COMPLETAR


	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, Lista<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int n, elementosInsertar, posicion;
	std::cin >> n;
	if (!cin) return false;
	Lista<int> lista;
	Lista<int> elementos;
	// creamos la lista
	for(int i = 0; i < n; i++) {
		lista.push(i);
	}
	cin >> elementosInsertar >> posicion;
	for (int i = 0; i < elementosInsertar; i++) {
		elementos.push(i);
	}
	// insertamos en la lista
	lista.insertaEnListaEnlazada(lista);
	// y la mostramos
	std::cout << lista << '\n';
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}