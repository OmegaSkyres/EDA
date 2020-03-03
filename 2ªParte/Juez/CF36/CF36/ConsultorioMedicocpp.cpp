
// Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include "consultorio.h"
using namespace std;




void resuelveCaso() {
	consultorio consul;
	string operaciones, nombreP, nombreD;
	int dia;
	fecha f;
	cin >> operaciones;
	if (operaciones == "nuevoMedico") {
		cin >> operaciones;
		consul.nuevoMedico(operaciones);
	}
	else if(operaciones == "pideConsulta"){
		cin >> nombreP;
		cin >> nombreD;
		cin >> f;
		consul.pideConsulta(nombreP, nombreD, f);
	}
	else if (operaciones == "siguientePaciente") {
		cin >> operaciones;
		consul.siguientePaciente(operaciones);
	}
	else if (operaciones == "atiendeConsulta") {
		cin >> operaciones;
		consul.atiendeConsulta(operaciones);
	}
	else if (operaciones == "listaPacientes") {
		cin >> nombreD;
		cin >> dia;
		consul.listaPacientes(nombreD, dia);
	}

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