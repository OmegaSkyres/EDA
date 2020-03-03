//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000


int canicasG(vector<string>& datos, vector<int> &valores, int a, int b, int &numCanicas) {
	if (a + 1 == b) {
		if (valores[a] >= valores[b]) {
			numCanicas = numCanicas + valores[a] + (valores[b] / 2);
			return a;
		}
		else {
			numCanicas = numCanicas + valores[b] + (valores[a] / 2);
			return b;
		}

	}
	else {
		int mitad = (a + b) / 2, ganadorIz, ganadorD, numCanicasIz = 0, numCanicasD = 0;
		ganadorIz = canicasG(datos, valores, a, mitad, numCanicasIz);
		ganadorD = canicasG(datos, valores, mitad+1, b, numCanicasD);
		if (numCanicasIz >= numCanicasD) {
			numCanicas = numCanicasIz + (numCanicasD / 2);
			return ganadorIz;
		}
		else {
			numCanicas = numCanicasD + (numCanicasIz/2);
			return ganadorD;
		}
	}
	

}


void canicas(vector<string> datos, vector<int>& valores, int numElementos) {
	int numCanicas = 0, ganador = 0;
	ganador = canicasG(datos, valores, 0, numElementos - 1, numCanicas);
	cout << datos[ganador] << " " << numCanicas << endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numElementos;
	for (; cin >> numElementos;) {
		vector<string> datos(numElementos);
		vector<int> valores(numElementos);
		for (int i = 0; i < numElementos; i++) {
			cin >> datos[i] >> valores[i];
		}
		canicas(datos, valores, numElementos);
	}
	return 0;
}
	
