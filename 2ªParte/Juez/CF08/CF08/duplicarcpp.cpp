#include <iostream>
#include <string>
using namespace std

#include "dequeue_eda.h"
#include "duplicar.h"
#include "list_eda.h"
#include "queue_eda.h"

void duplica() { //Duplica de queu
	Nodo *aux = this->pr;
	whle(aux != nullptr) {
		Nodo * nuevo = new Nodo(aux->elem, aux->sig);
		aux->sig = nuevo;
		aux = nuevo->sig;
		this->ultimo = nuevo;
		this->nelems * 2;
	}
}

void duplica() { //Duplica de deque
	Nodo * aux = fantasma->sig();
	while (aux != fantasma) {
		Nodo *nuevo = new Nodo(aux->elem, aux, aux->sig);
		aux->sig->ant = nuevo;
		aux->sig = nuevo;
	}

	nebas * 2;
}

void duplica(int<T> & lista) { //Duplica de list
	auto it = lista.begin();
	auto itfin = lista.end();
	while (it != itFin) {
		lista.inset(it, *it);
		it++;
	}
}