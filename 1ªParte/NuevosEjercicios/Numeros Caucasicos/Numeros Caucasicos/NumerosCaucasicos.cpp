//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool caucasicoG(const vector<int> datos, int ini, int fin, int& pares) {
	bool esCaucasico;

	if (fin - ini <= 1) {
		if (datos[ini] % 2 == 0) {
			pares++;
		}
		if (datos[fin] % 2 == 0) {
			pares++;
		}
		esCaucasico = true;
	}
	else {
		int m = (ini + fin) / 2, paresI = 0, paresD = 0;
		if (!caucasicoG(datos, ini, m, paresI) || !caucasicoG(datos, m + 1, fin, paresD))
			esCaucasico = false;
		else {
			pares = paresI + paresD;
			if (abs(paresI - paresD <= 2))
				esCaucasico = true;
			else
				esCaucasico = false;
		}
	}

	return esCaucasico;
}
	

//Analisis y justificacion del coste
/*
		| c0 si n = 1
 T(n) = |
		| 2T(n/2) + c0 si n > 1

 Despligue:
 T(n) = 2T(n/2) + c0 = 2^2T(n/(2^2)) + 2c0 + c = 2^3T(n/(2^3)) + 2^2c0 + c0 = ... =
 = 2^kT(n/(2^k)) + 2*kc0 + 2^(k-1)c0 + 2^(k-2)c0 + ... + 2^2c0 + 2c0 + 2^0c0

 Coste: O(n)
 */

void caucasico(vector<int>datos, int numElementos) {
	int numCaucasicos = 0;
	if (caucasicoG(datos, 0, numElementos-1, numCaucasicos)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


int main() {
	// Para la entrada por fichero.

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos

	int numElementos = 0;
	// Resolvemos
	cin >> numElementos;
	while (numElementos != 0) {
		vector<int> datos(numElementos);
		for (int j = 0; j < numElementos; j++) {
			cin >> datos[j];
		}
		caucasico(datos, numElementos);
		cin >> numElementos;
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}