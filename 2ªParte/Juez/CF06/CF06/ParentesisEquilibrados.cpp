#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "stack"
using namespace std;

void pasar_a_postfija(string & expresion) { 
	string basura; stack<char> pila;
	bool ok = true;
	char caracter;
	for (char c : expresion) {
		if (isdigit(c)) pila.push(c);
		else if (c == '(' || c == '[' || c == '{') {
			 pila.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (pila.size() == 0) ok = false;
			else {
				caracter = pila.top();
				if (c == ')' && caracter == '(') {
					pila.pop();
				}
				else if (c == ']' && caracter == '[') {
					pila.pop();
				}
				else if (c == '}' && caracter == '{') {
					pila.pop();
				}
				else ok = false;
			}

		}
	}
	
	if (pila.size() > 0) ok = false;
	if (ok) cout << "SI" << "\n";
	else cout << "NO" << "\n";
	
}

bool resuelveCaso() {
	string expresion;
	getline(cin, expresion);
	//Leer caso de prueba

	if (!std::cin)
		return false;
	pasar_a_postfija(expresion);

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