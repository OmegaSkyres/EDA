
// Roberto Torres Prensa

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void resolver(vector<vector<int>> const &tiempos, vector<bool> &marcaje, vector<int> &acumulado, int k, int &nFuncionarios, int &sumaMin, int &sum) {
	for (int i = 0; i < nFuncionarios; i++) {
		if (!marcaje[i]) {
			sum += tiempos[i][k];
			marcaje[i] = true;
		}

		if (k == nFuncionarios - 1) {
			if (sum < sumaMin) {
				sumaMin = sum;
			}

		}
		else {
			resolver(tiempos, marcaje, acumulado, k + 1, nFuncionarios, sumaMin, sum);
		}
		marcaje[i] = false;
		sum -= tiempos[i][k];
	}


}


bool resuelveCaso() {
	int	nFuncionarios;
	cin >> nFuncionarios;
	//Leer caso de prueba
	int sumaMin, sum = 0;
	vector<vector<int>> tiempos(nFuncionarios, vector<int>(nFuncionarios));
	vector<bool> marcaje(nFuncionarios);
	vector<int> acumulado;

	if (nFuncionarios == 0) {
		return false;
	}
	for (int i = 0; i < nFuncionarios; i++) {
		for (int j = 0; j < nFuncionarios; j++) {
			cin >> tiempos[i][j];
		}
		
	}
	sumaMin = INT_MAX;
	resolver(tiempos, marcaje, acumulado, 0, nFuncionarios, sumaMin, sum);
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