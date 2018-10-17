
#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	long long int numM, muroA, muroS, saltoA = 0, saltoB = 0, aux = 0;
	cin >> numM;
	cin >> muroA;
	aux = muroA;
	for (long long int i = 1; i < numM; i++) {
		cin >> muroS;
		if (muroS > aux) {
			saltoA++;
		}
		else if (muroS < aux) {
			saltoB++;
		}
		aux = muroS;
		

	}
	cout << saltoA << " " << saltoB << endl;
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
}

int main() {
	// Para la entrada por fichero.
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (long long int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	*/
	return 0;
}
