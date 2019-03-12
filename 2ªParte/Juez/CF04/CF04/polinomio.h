#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>


using namespace std;

class polinomio {
private: 
	int coef, expo;

public:
	polinomio(int coeficiente, int exponente) : coef(coeficiente), expo(exponente) {

	}

	int getCoef() {
		return coef;
	}

	int getExpo() {
		return expo;
	}

	inline istream & operator>> (istream &salida, polinomio &polinomio) {
		int coeficiente, exponente;
		char aux;
		salida >> coeficiente >> exponente;
		polinomio = polinomio(coeficiente, exponente);
		return salida;
	}
}

#endif