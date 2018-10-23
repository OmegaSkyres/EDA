//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<int> v) {
	int p = -1;
	int cero = 0, uno = 1;
	int i = 0;
	while (i < v.size()) {
		if (v.at == 0) {
			cero++;
		}
		if (v.at == 1) {
			uno++;
		}
		if (cero == uno) {
			p = i;
		}
		i++;
	}
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

//Postocondicion{-1<= p < v.lenght && (#k:0<=k<=p : v[k] == 0) = (#k :0 <= k <= p::v[n] = 1)