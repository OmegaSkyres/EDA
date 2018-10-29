//Roberto Torres Prensa	


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelve(vector<int> &datos) {
	int contador = 0;
	for (int i = 0; i < datos.size(); i++) {
		if (datos[i] % 2 == 0) {
			datos[contador] = datos[i];
			contador++;
		}
		else {
			datos[i] = 0;
		}
	}
	datos.resize(contador);
	for (int i = 0; i < datos.size(); i++) { // o si no cambiar datos.size por contador
		if (datos[i] != 0) {
			cout << datos[i] << " ";
		}
		else cout << " ";
	}
	cout << endl;
}

void resuelveCaso() {
	int nElementos;
	cin >> nElementos;
	vector<int> datos(nElementos);
	for (int i = 0; i < nElementos; i++) {
		cin >> datos[i];
	}
	resuelve(datos);
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