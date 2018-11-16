
// Roberto Torres Prensa

#include <iostream>

#include <fstream>
using namespace std;

bool resuelve(long long int numero, int &longitud) {
	int aux;
	bool polidivisible = true;
	if (numero < 10) { //Caso Base
		aux = numero % longitud;
	}
	else
	{
		polidivisible = resuelve(numero / 10, longitud);
		longitud++;
		aux = numero % longitud;
		
	}
	if (aux != 0) {
		polidivisible = false;
	}
	return polidivisible;
}

bool resuelveCaso(long long int &numero) {
	int longitud = 1;
	//Leer caso de prueba

	if (resuelve(numero, longitud)) {
		cout << "POLIDIVISIBLE" << endl;
	}
	else cout << "NO POLIDIVISIBLE" << endl;

	
	return true;
}


int main() {
	/*
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/
	long long int numero;
	while (std::cin >> numero) {
		resuelveCaso(numero);
	}
	/*
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
*/
	return 0;
}