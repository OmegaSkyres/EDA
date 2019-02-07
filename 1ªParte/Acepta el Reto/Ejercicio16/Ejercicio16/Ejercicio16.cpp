// Nombre del Grupo LOVELACE

/*
Definición: Dado V[N] de enteros, el índice i es un pico si V[i] es el mayor elemento de V[0..i].
	Especifica y deriva un algoritmo de coste lineal que reciba un vector y calcule la suma
	de todos los valores almacenados en los picos de V.
*/




#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int resuelve(vector<int> &datos) {
	int  suma = 0;
	// P { datos.size() > 0 }
	// I { 1<= i <= datos.size() - 1 }
	// I { suma = Sum k :: 0 < k < i :: datos[k] > datos[k + 1] && datos[k] > datos[k - 1]
	// Cota datos.size() - i
	for (int i = 1; i < datos.size() - 1; i++) {
		if (datos[i] > datos[i + 1] && datos[i] > datos[i - 1]) {
			suma += datos[i];
		}
	}
	return suma;
	// El coste del algoritmo es de orden datos.size(), por que da datos.size() vueltas, por lo tanto el coste es costante.
	
	// Q {suma = Sum k :: 0 < k < datos.size() - 1 :: datos[k] > datos[k + 1] && datos[k] > datos[k - 1] }
}

void resuelveCaso() {
	int nElementos = 0;
	cin >> nElementos;
	vector<int> datos(nElementos);
	for (int i = 0; i < nElementos; i++) {
		cin >> datos[i];
	}

	cout << resuelve(datos) << endl;
}

int main() {
	// Resolvemos
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


	return 0;
}