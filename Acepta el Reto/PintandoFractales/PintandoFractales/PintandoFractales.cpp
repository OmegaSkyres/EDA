//Roberto Torres Prensa			


#include <iostream>
#include <fstream>
using namespace std;



int resuelveCaso(long int numero) {
	long int suma = 0;

	if (numero == 1) { //Caso BASE
		suma = 4;
	}
	else {
		suma = resuelveCaso(numero / 2) * 4 + numero * 4; //CASO RECURSIVO
		
	}
	return suma;
}

int main() {
	/*
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/
	int suma;
	int numero;
	
	// Resolvemos
	while (cin >> numero) {
		suma = resuelveCaso(numero);
		cout << suma << endl;
	}

	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/
	return 0;
}