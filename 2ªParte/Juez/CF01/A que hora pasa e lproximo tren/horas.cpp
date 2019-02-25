

// Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "horas.h"

bool resuelveCaso() {
	int nH, nC;
	horas h;
	cin >> nH >> nC;

	if (nH && nC == 0)
		return false;

	vector<horas> horario(nH);
	for (int i = 0; i < nH; i++) {
		cin >> horario[i];
	}
	for (int i = 0; i < nC; i++) {
		cin >> h;
		
	}
	auto p = lower_bound(horario.begin(), horario.end(), h);
	if (p = horario.end()) {
		cout << "NO\n";
	}
	else
		cout << *p << "\n";
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
