#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "carnetpuntos.h"
using namespace std;



bool resuelveCaso() {
	string aux;
	int puntos;
	carnet_puntos carnets;

	cin >> aux;

	if (!cin)
		return false;

	while (aux != "FIN") {
		if (aux == "nuevo") {
			cin >> aux;
			try {
				carnets.nuevo(aux);
			}
			catch (domain_error e) {
				cout << "ERROR: " << e.what() << endl;
			}
		}
		else if (aux == "cuantos_con_puntos") {
			cin >> puntos;
			try {
				cout << "Con " << puntos << " puntos hay " << carnets.cuantosConPuntos(puntos) << endl;
			}
			catch (domain_error e) {
				cout << "ERROR: " << e.what() << endl;
			}
		}
		else if (aux == "quitar") {
			cin >> aux >> puntos;
			try {
				carnets.quitar(aux, puntos);
			}
			catch (domain_error e) {
				cout << "ERROR: " << e.what() << endl;
			}
		}
		else if (aux == "consultar") {
			cin >> aux;
			try {
				cout << "Puntos de " << aux << ": " << carnets.consultar(aux) << endl;
			}
			catch (domain_error e) {
				cout << "ERROR: " << e.what() << endl;
			}
		}

		cin >> aux;
	}

	cout << "---" << endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif



	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}