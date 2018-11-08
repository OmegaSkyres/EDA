//Roberto Torres Prensa			


#include <iostream>
#include <fstream>
using namespace std;



int resuelveCaso(int numero) {
	int suma = 0;
	
	if (numero <= 9) { //Caso BASE
		cout << numero;
		return numero;
	}
	else {
		suma = resuelveCaso(numero / 10) + numero % 10; //CASO RECURSIVO
		cout << " + " << numero % 10;
		return suma;
	}
	
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int suma;
	int numero;
	cin >> numero;
	// Resolvemos
	while(numero >= 0){
		suma = resuelveCaso(numero);
		cout << " = " << suma << endl;
		cin >> numero;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}