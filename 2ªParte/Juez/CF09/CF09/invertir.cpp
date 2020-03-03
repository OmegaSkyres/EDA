
#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
	void print(std::ostream& o = std::cout) const {
		if (!this->empty()) {
			Nodo* nodo = this->prim;
			for (int i = 0; i < this->nelems; i++) {
				cout << nodo->elem << " ";
				nodo = nodo->sig;
			}
		}
	}

	void invierte() {
		int n = this->nelems;
		Nodo* actual = this->prim;
		Nodo* sig = NULL;
		Nodo* prev = NULL;
		while (actual != NULL) {
			sig = actual->sig;
			actual->sig = prev;
			prev = actual;
			actual = sig;
		}
		this->prim = prev;
	}
	
	
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!cin) return false;
	ListaDuplica<int> lista;
	// creamos la lista
	while (n != 0) {
		lista.push(n);
		std::cin >> n;
	}
	// la duplicamos
	lista.invierte();
	// y la mostramos
	std::cout << lista << '\n';
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
