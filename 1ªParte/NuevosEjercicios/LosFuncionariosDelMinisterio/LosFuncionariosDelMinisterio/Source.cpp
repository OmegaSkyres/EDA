//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resolver(vector<vector<int>> datos, vector<bool> trabajo, vector<bool> funcionario, int numFuncionarios, int k, int asignacionA, int &asignacionOp) {
	if (k == numFuncionarios) {
		if (asignacionA < asignacionOp) {
			asignacionOp = asignacionA;
		}
	}
	for (int i = 0; i < numFuncionarios; i++) {
		if (!trabajo[i]) {
			for (int j = 0; j < numFuncionarios; j++) {
				if (!funcionario[j]) {
					asignacionA += datos[i][j];
					trabajo[i] = true;
					funcionario[j] = true;
					resolver(datos, trabajo, funcionario, numFuncionarios, k + 1, asignacionA, asignacionOp);
					asignacionA -= datos[i][j];
					trabajo[i] = false;
					funcionario[j] = false;
				}
			}
		}
	}
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numFuncionarios, asignacionOp = 1000;
	cin >> numFuncionarios;
	vector<vector<int>> datos(numFuncionarios, vector<int>(numFuncionarios));
	vector<bool> trabajo(numFuncionarios);
	vector<bool> funcionario(numFuncionarios);
	while (numFuncionarios != 0) {
		for (int i = 0; i < numFuncionarios; i++) {
			for (int j = 0; j < numFuncionarios; j++) {
				cin >> datos[i][j];
			}
		}
		for (int i = 0; i < numFuncionarios; i++) {
			trabajo[i] = false;
			funcionario[i] = false;
		}
		resolver(datos, trabajo, funcionario,numFuncionarios,0,0,asignacionOp);
		cout << asignacionOp << endl;
		asignacionOp = 1000; 
		cin >> numFuncionarios;
	}
	

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}