//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int minVectorG(const vector<int>datos, const int i, const int j) {
	if (i + 1 >= j) { //Hay 2 elemento
		if (datos[i] > datos[j]) {
			return datos[j];
		}
		else {
			return datos[i];
		}
	}
	else {
		int mitad = (i + j) / 2;
		if (datos[mitad] < datos[i]){
			return minVectorG(datos, mitad, j);
		}
		else {
			return minVectorG(datos, i, mitad);
		}
	}
	

}

//Analisis y justificacion del coste
/*
   Costes
   


*/

void minVector(const vector<int>datos, const int numElementos) {
	cout << minVectorG(datos, 0, numElementos) << endl;
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
	while (std::cin >> numElementos) {
		vector<int> datos(numElementos);
		for (int j = 0; j < numElementos; j++) {
			cin >> datos[j];
		}
		minVector(datos, numElementos-1);
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}