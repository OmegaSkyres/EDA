
//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<int> &datos, int &valorP, int &numerosV) {
	bool ok = true;
	if (!datos.empty() && (0 <= valorP) && (valorP < datos.size())) {
		int maximo = datos[0], minimo;
		int i;
		for (i = 0; i <= valorP; i++) {
			if (maximo < datos[i]) {
				maximo = datos[i];
			}
		}

		for (i; i < numerosV; i++) {
			minimo = datos[i];
			if (maximo >= minimo){
				ok = false;
			}
		}
	}

	if (ok) cout << "SI" << endl;
	else cout << "NO" << endl;

}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	int numerosV, valorP, contadorC = 0, i = 0;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numerosV >> valorP;
		vector<int> datos(numerosV);
		for (int i = 0; i < numerosV; i++) {
			cin >> datos[i];
		}
		resuelveCaso(datos, valorP, numerosV);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
