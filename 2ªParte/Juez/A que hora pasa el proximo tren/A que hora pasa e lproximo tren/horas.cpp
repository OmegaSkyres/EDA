
// Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "conjunto.h"

bool resuelveCaso() {
	int numeroT, numeroH, HH, MM, SS;
	vector<string> horas;
	vector<string> horaDelSiguiente;
	cin >> numeroT >> numeroH;

	if (numeroT && numeroH == 0)
		return false;

	for (int i = 0; i < numeroT; i++) {
		horas[i].push_back;
	}
	for (int i = 0; i < numeroH; i++) {
		horaDelSiguiente[i].push_back
	}
	//Resolver problema
	//Escribir resultado
	return true;
}

class horas {
private:
	
public:
	
	bool operator<(horas const& that) const {
		return hora() < that.hora();
	}
	bool operator>(horas const& that) const {
		return that < *this;
	}
};

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