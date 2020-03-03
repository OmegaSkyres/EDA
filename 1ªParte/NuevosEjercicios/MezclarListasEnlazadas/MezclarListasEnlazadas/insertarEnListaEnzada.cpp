#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

template <class T>
class MezclaListas : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:

	void mezclar(MezclaListas<int> &lista2) {
		int nelemsLista1 = this->nelems;
		int nelemsLista2 = lista2.nelems;
		int nTotal = this->nelems + lista2.nelems;
		
		if (lista2.empty()) {
			return;
		}
		else if (this->empty() && !lista2.empty()) {
			this->prim = lista2.prim;
			this->ult = lista2.ult;
			this->nelems = lista2.nelems;
		}
		else {
			Nodo* sigl1 = this->prim;
			Nodo* sigl2 = lista2.prim;
			Nodo* menor;
			if (sigl1 == nullptr) {
				this->prim = lista2.prim;
			}
			else if (sigl2 != nullptr) {
				if (sigl1->elem <= sigl2->elem) {
					menor = sigl1;
					sigl1 = sigl1->sig;
					nelemsLista1--;
				}
				else {
					this->prim = sigl2;
					menor = sigl2;
					sigl2 = sigl2->sig;
					nelemsLista2--;
				}
				while (sigl1 != nullptr && sigl2 != nullptr) {
					if (sigl1->elem <= sigl2->elem) {
						menor->sig = sigl1;
						menor = menor->sig;
						sigl1 = sigl1->sig;
						nelemsLista1--;
					}
					else {
						menor->sig = sigl2;
						menor = menor->sig;
						sigl2 = sigl2->sig;
						nelemsLista2--;
					}
				}
				if (nelemsLista1 > 0) {
					menor->sig = sigl1;
				}
				else if (nelemsLista2 > 0) {
					menor->sig = sigl2;
				}
			}
		}
		lista2.prim = nullptr;
		lista2.ult = nullptr;
		lista2.nelems = 0;
		
	}

	void print() {
		Nodo* nodo = this->prim;
		while (nodo != nullptr) {
			cout << nodo->elem << " ";
			nodo = nodo->sig;
		}
		cout << endl;

	}

};



bool resuelveCaso() {
	MezclaListas<int> lista;
	MezclaListas<int> lista2;
	int elemento;
	cin >> elemento;
	// creamos la lista
	while (elemento != 0) {
		lista.push(elemento);
		cin >> elemento;
	}
	cin >> elemento;
	while (elemento != 0) {
		lista2.push(elemento);
		cin >> elemento;
	}
	// la duplicamos
	lista.mezclar(lista2);
	// y la mostramos
	lista.print();
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}