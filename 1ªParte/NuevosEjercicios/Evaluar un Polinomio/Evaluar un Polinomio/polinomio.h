#ifndef polinomio_h
#define polinomio_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class polinomio {

private:
	struct monomio {//structura de pares
		int coeficiente;
		int exponente;
	};
	vector<monomio> poli;
public:
	polinomio() {

	}
	
	void add(int coeficiente, int exponente) {
		monomio x;
		x.coeficiente = coeficiente;
		x.exponente = exponente;
		poli.push_back(x);
	}

	void ordena() {
		for (int i = 0; i < poli.size() - i - 1; i++) {
			if (poli[i].exponente > poli[i+1].exponente) {
				swap(poli[i], poli[i + 1]);
			}
		}
	}

	int evalua(const int valor) {
		int val = 0;
		for (int i = 0; i < poli.size(); i++) {
			val += (poli[i].coeficiente * pow(valor, poli[i].exponente));
		}
		return val;
	}



};




#endif // !polinomio_h

