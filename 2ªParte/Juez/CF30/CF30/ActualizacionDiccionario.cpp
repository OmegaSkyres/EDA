//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include "treemap_eda.h"
using namespace std;

void resolver(map<std::string, int> antiguoDiccionario, map<std::string, int> nuevoDiccionario,
	vector<string>& anadidos, vector<string>& eliminados, vector<string>& modificados) {
	bool encontrado = false;
	auto itA = antiguoDiccionario.begin();
	auto itN = nuevoDiccionario.begin();

	while (itA != antiguoDiccionario.end()) { //Recorremos todo el diccionario antiguo
		if (nuevoDiccionario.count(itA->clave)) { //Si el nuevo tiene la clave del antiguo, existe
			if (nuevoDiccionario.find(itA->clave)->valor != antiguoDiccionario.find(itA->clave)->valor)
				modificados.push_back(itA->clave); //Si no es el mismo valor, añadimos la clave a modificados
		}
		else if (nuevoDiccionario.empty()) {
			anadidos.push_back(itA->clave);
		}
		else eliminados.push_back(itA->clave); //Si no tiene la clave, la añadimos a eliminados
		++itA;
	}
	
	while (itN != nuevoDiccionario.end()) {
		if (!antiguoDiccionario.count(itN->clave)) anadidos.push_back(itN->clave);
		++itN;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	map<std::string, int> antiguoDiccionario;
	map<std::string, int> nuevoDiccionario;
	vector<string> anadidos, eliminados, modificados;

	std::string clave, linea1, linea2;
	int valor;

	if (!std::cin) return;


	getline(cin, linea1);
	stringstream ss(linea1);

	while (ss >> clave) {
		ss >> valor;
		antiguoDiccionario.insert({ clave, valor });
	}


	getline(cin, linea2);

	stringstream sa(linea2);

	while (sa >> clave) {
		sa >> valor;
		nuevoDiccionario.insert({ clave, valor });
	}

	resolver(antiguoDiccionario, nuevoDiccionario, anadidos, eliminados, modificados);


	if (!eliminados.empty() || !modificados.empty() || !anadidos.empty()) {
		if (!anadidos.empty()) {
			cout << "+ ";
			for (int i = 0; i < anadidos.size(); ++i)
				cout << anadidos.at(i) << " ";
			cout << endl;
		}


		if (!eliminados.empty()) { //Eliminados
			cout << "- ";
			for (int i = 0; i < eliminados.size(); ++i)
				cout << eliminados.at(i) << " ";
			cout << endl;
		}

		if (!modificados.empty()) { //Modificados
			cout << "* ";
			for (int i = 0; i < modificados.size(); ++i)
				cout << modificados.at(i) << " ";
			cout << endl;
		}
	}
	else cout << "Sin cambios" << endl;

	cout << "----" << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("Casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	cin.get();
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}