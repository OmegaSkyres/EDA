//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(int x, int n) {
	int k = 31.543, potencia = 0;
	if (n == 0) {
		potencia = 1;
	}
	else if(n == 1) {
		potencia = x;
	}
	else {
		potencia = x;
		potencia = potencia * x;
		resuelveCaso(potencia, n - 1);

	}
	

}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int x, n;
	// Resolvemos
	cin >> x >> n;
	while (x != 0 && n != 0) {
		resuelveCaso(x, n);
		cin >> x >> n;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}