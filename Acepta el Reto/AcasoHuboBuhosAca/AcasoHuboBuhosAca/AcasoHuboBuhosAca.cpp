
// Roberto Torres Prensa

#include <iostream>

#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool resolver(char frase[], int i, int longitud, int j) {
	if (i == longitud) { //Caso base
		return true;
	}
	else { //Caso recursivo
		if (frase[i] == frase[j - i - 1]) {
			return resolver(frase, i + 1, longitud, j);
		}
		else {
			return false;
		}


	}
}


bool resuelveCaso() {

	//Leer caso de prueba
	string entrada;
	int longitud;
	char frase[100];
	getline(cin, entrada);
	if (entrada == "XXX")
		return false;

	int j = 0;
	for (int i = 0; i < entrada.size(); i++) {
		if (entrada[i] != ' ') {
			frase[j] = tolower(entrada[i]);
			j++;
		}
	}
	longitud = j / 2;
	if (resolver(frase, 0, longitud, j)) {
		cout << "SI" << endl;
	}
	else cout << "NO" << endl;
	//Resolver problema
	//Escribir resultado
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
	while (resuelveCaso());
	/*
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
*/
	return 0;
}