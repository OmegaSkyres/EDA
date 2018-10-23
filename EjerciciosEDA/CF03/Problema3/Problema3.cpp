//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<int> &datos, int &valorP) {
	bool ok = true;
	for (int i = 0; i > valorP; i--) {
		
	}
	if (datos[i] < datos[i - 1]) {

	}
	cout << "NO" << endl,
	cout << "SI" << endl;
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
	cin >> numerosV >> valorP;
	vector<int> datos(numerosV);
	for (int i = 0; i < numerosV; i++) {
		cin >> datos[i];
	}
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso(datos,valorP);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}