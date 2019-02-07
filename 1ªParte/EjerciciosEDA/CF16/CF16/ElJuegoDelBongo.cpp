//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool resolver(vector<int> datos, int numeroCantado, int inicio, int fin, int resultado) {
	int mitad;
	mitad = (inicio + fin) / 2;
	bool ok = false;
	if (inicio + 1 == datos.size()) {
		if (inicio + numeroCantado == datos[inicio]) {
			resultado = datos[inicio];
			ok = true;
		}
	}
	else if (!ok) {
		if (numeroCantado + mitad == datos[mitad]){
			resultado = datos[mitad];
			ok = true;
		}
		else if (datos[mitad] > mitad + numeroCantado) {
			resolver(datos, numeroCantado, inicio, mitad, resultado);	
		}

		else if (datos[mitad] < mitad + numeroCantado){
			resolver(datos, numeroCantado, mitad, fin, resultado);
		}
	}

	return ok;
}


void resuelveCaso() {
	int cantidadNumeros, numeroCantado, resultado = 0, elemento;
	vector<int> datos;
	bool encontrado;
	cin >> cantidadNumeros >> numeroCantado;
	for (int i = 0; i < cantidadNumeros; i++) {
		cin >> elemento;
		datos.push_back(elemento);
	}

	encontrado = resolver(datos, numeroCantado, 0, datos.size(), resultado);
	if (encontrado)
	cout << resultado << endl;
	else cout << "NO" << endl;
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