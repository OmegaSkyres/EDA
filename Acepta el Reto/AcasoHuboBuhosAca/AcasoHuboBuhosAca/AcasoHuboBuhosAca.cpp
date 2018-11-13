
// Roberto Torres Prensa

#include <iostream>

#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool resolver(char &frase, int i, int tamaño) {
	if (i == tamaño) { //Caso base

	}
	else //Caso recursivo
	resolver(frase, i+1, tamaño - 1),

	return ok;
}


bool resuelveCaso() {

	//Leer caso de prueba
	string entrada;
	char frase[100];
	getline(cin, entrada);
	if (entrada != "XXX")
		return false;


	for (int i = 0; i < entrada.size(); i++) {
		if (entrada[i] != ' ') {
			frase[i] = tolower(entrada[i]);
		}
	}
	
	//Resolver problema
	//Escribir resultado
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