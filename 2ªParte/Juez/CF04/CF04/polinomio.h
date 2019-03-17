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
	polinomio(int coeficiente = 0, int exponente = 0) : coef(coeficiente), expo(exponente) {

	}

	int getCoef() {
		return coef;
	}

	int getExpo() {
		return expo;
	}

	
};

inline istream & operator>> (istream &salida, polinomio &poli) {
	int coeficiente, exponente;
	salida >> coeficiente >> exponente;
	
	poli = polinomio(coeficiente, exponente);
	return salida;
}

#endif