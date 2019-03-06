#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <string>
#include <iostream>
#include "complejo.h"

using namespace std;

class complejo {
private: int numIteraciones;
		 float parteReal, parteImaginaria;

public:
	complejo();
	complejo(float numReal, float numImaginaria, int numeroIteraciones) : parteReal(numReal), parteImaginaria(numImaginaria), numIteraciones(numeroIteraciones) {
		
	}

	float getNumReal() {
		return parteReal;
	}

	float getParteImaginaria() {
		return parteImaginaria;
	}

	int getNumIteraciones() {
		return numIteraciones;
	}
	
	complejo operator +(const complejo &c) const {
		float nR, nI;
		nR = parteReal + c.parteReal;
		nI = parteImaginaria + c.parteImaginaria;
		return complejo(nR, nI, numIteraciones);
	}

	complejo operator * (const complejo &c)const {
		float nR, nI;
		nR = parteReal * c.parteReal;
		nI = parteReal * c.parteReal;
		return complejo(nR, nI, numIteraciones);
	}

	int operator%(const complejo &c)const {
		int sol;

		sol = sqrt((parteReal * parteReal) + (parteImaginaria * parteImaginaria));

		return sol;
	}


};

	inline istream &operator>>(istream &in, complejo &c) {
		float r, i;
		int t;

		cin >> r >> i >> t;

		c = complejo(r, i, t);

		return in;
	}



#endif#pragma once
