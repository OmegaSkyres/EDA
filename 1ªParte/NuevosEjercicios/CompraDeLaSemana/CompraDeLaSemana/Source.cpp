// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// función que resuelve el problema



void resolver(vector<vector<int>> datos, vector<int> &marcaje, const int numSupermercados, const int numProductos, int k, int solucionP, int &solucionO) {
	for (int i = 0; i < numSupermercados; i++) {
		if (marcaje[i] < 3) {
			solucionP += datos[i][k];
			if (solucionP < solucionO) {
				if (k == numProductos - 1) {
					solucionO = solucionP;
				}
				else {
					marcaje[i]++;
					resolver(datos, marcaje, numSupermercados, numProductos, k + 1, solucionP, solucionO);
					marcaje[i]--;
				}
			}
			solucionP -= datos[i][k];
		}
		
		

	}

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int numCasos, numSupermercados, numProductos, solucionO = 100000;
	cin >> numCasos;
	for (int k = 0; k < numCasos; k++) {
		cin >> numSupermercados >> numProductos;
		vector<vector<int>> datos(numSupermercados, vector<int>(numProductos));
		vector<int> marcaje(numSupermercados);
		for (int i = 0; i < numSupermercados; i++) {
			for (int j = 0; j < numProductos; j++) {
				cin >> datos[i][j];
			}
		}
		resolver(datos, marcaje, numSupermercados, numProductos, 0,0, solucionO);
		if (solucionO == 100000) {
			cout << "Sin solucion factible" << endl;
		}
		else cout << solucionO << endl;
	}



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}