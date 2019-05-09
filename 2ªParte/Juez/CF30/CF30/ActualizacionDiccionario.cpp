//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include "treemap_eda.h"
using namespace std;



void resuelveCaso() {
	char c;
	int numero, contador = 0;
	string diccionarioV, diccionarioN, trash;
	map<char, int> secuencia;

	getline(cin, trash);
	getline(cin, diccionarioV);
	getline(cin, diccionarioN);
	stringstream v(diccionarioV); // Used for breaking words 
	stringstream n(diccionarioN);
	while (v >> c)
	{
		v >> numero;
		secuencia[c] = numero;
		contador++;
	}
	while (n >> c)
	{
		n >> numero;
		if (secuencia.count(c) > 0) {
			cout << "+ " << c;
		}
	}

	cout << "Sin cambios" << endl;
	cout << "----" << endl;
	
	
	
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
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