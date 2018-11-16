
// Roberto Torres Prensa

#include <iostream>

#include <fstream>
using namespace std;

bool resuelve(int numero, int &longitud) {
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

bool resuelveCaso() {
	int numero, longitud = 1;
	cin >> numero;
	//Leer caso de prueba

	if (!std::cin)
		return false;
	if (resuelve(numero, longitud)) {
		cout << "POLIDIVISIBLE" << endl;
	}
	else cout << "NO POLIDIVISIBLE" << endl;

	
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}