
// NOMBRE Y APELLIDOS

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void resolver(std::vector<std::vector<int>> const& v, std::vector<bool>& marcaje, std::vector<int>& acumulados, int k, int& n, int& sumMin, int& sum) {
	for (int i = 0; i < n; i++) {
		if (!marcaje[i]) {
			sum += v[i][k];
			marcaje[i] = true;
		}
		if (k == n - 1) {
			if (sum < sumMin) {
				sumMin = sum;
			}
		}
		else {
			if (sum + acumulados[k + 1] < sumMin) {
				resolver(v, marcaje, acumulados, k + 1, n, sumMin, sum);
			}
		}
		marcaje[i] = false;
		sum -= v[i][k];
	}
	
}


bool resuelveCaso() {
	int numeroFuncionarios, sumMin;
	//Leer caso de prueba
	cin >> numeroFuncionarios;
	if (numeroFuncionarios == 0) {
		return false;
	}
	vector<vector<int>> tiempos(numeroFuncionarios, vector<int>(numeroFuncionarios));
	vector<bool> marcaje(numeroFuncionarios);
	vector<int> acumulado;
	for (int i = 0; i < numeroFuncionarios; i++) {
		for (int j = 0; j < numeroFuncionarios; j++) {
			cin >> tiempos[i][j];
		}
	}
	//acumulado = acumulados(tiempos, numeroFuncionarios);
	sumMin = INT_MAX;

	resolver(tiempos, marcaje, acumulado, 0, numeroFuncionarios, sumMin);


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