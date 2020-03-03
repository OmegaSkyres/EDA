#ifndef queue_afortunado
#define queue_afortunado

#include <iostream>
using namespace std;
#include "queue_eda.h"

template <class T>
class Afortunado : public queue<int> {
	using Nodo = typename queue<T>::Nodo;

public:
	void resolver(queue<int>& lista, int salto) {
		int contador = 0;
		while (lista.size() > 1) {
			if (contador == salto) {
				this->pop();
				contador = 0;
			}
			else {
				this->push(this->front());
				this->pop();
				contador++;
			}

		}

	}

	void print() {
		Nodo* nodo = this->prim;
		if (this->size() > 0) {
			cout << this->front() << endl;
		}
	}


};

#endif // !queue_afortunado

