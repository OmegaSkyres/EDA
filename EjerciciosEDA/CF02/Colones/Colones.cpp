//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//{P: true}
void resuelveCaso() {
	int numeroP, contadorC = 0, i = 0, aux = 0;
	//{I: 0 < i <= datos.size() - 1}
	//{I: cont = #k: forall u: datos.size() > u > 0: v[u] < v[u-1] && aux = exists w: datos.size() > u >= w > 0: v[u] > v[w] ==> w = u}
	cin >> numeroP;
	vector<int> datos(numeroP);
	for (i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	if (!datos.empty()) {
		aux = datos[numeroP - 1];
		for (i = numeroP - 1; i > 0; i--) {
			if (aux < datos[i - 1]) {
				contadorC++;
			}

			if (aux > datos[i - 1]) {
				aux = datos[i - 1];
			}
		}
	}
	
	cout << contadorC << endl;
}
//{Q: cont = #k: forall u: datos.size() > u > 0: v[u] < v[u-1] && exists w: datos.size() > u >= w > 0: v[u] > v[w] ==> w = u}

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