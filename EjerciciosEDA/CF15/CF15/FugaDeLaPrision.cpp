//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

char busquedaBin(vector<char> datos, char X1, char X2) {
	char resultado = 0, mitad;
	if (X1 + 2 == X2) { //Si el vector solo tiene dos elementos 
		resultado = datos[X1] + 1;
	}
	else {
		mitad = (X1 + X2) / 2;
		if (datos[mitad] - datos[0] == mitad) {
			resultado = busquedaBin(datos, mitad, X2);
		}
		else {
			resultado = busquedaBin(datos, X1, mitad + 1);
		}

	}

	return resultado;
}

char soluciona(vector<char> datos, char X1, char X2) {
	char resultado;
	if (X2 != datos[datos.size() - 1]) {
		resultado = X2;
	}
	else if (X1 != datos[0]) {
		resultado = X1;
	}
	else {
		resultado = busquedaBin(datos, 0, datos.size());
	}

	return resultado;
}


void resuelveCaso() {
	char X1, X2, lectura, resultado = 0;
	vector<char> datos;
	
	cin >> X1 >> X2;
	for (int i = 0; i < (X2 - X1); i++) {
		cin >> lectura;
		datos.push_back(lectura);
	}


	resultado = soluciona(datos, X1, X2);


	cout << resultado << endl;
}



int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}