//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<int> &v) {
	int p = -1;
	int numCeros = 0, numUnos = 0;
	int i = 0;
	// -1 < p < v.length && 0 <= i <= v.length
	// numCeros = #k : 0 <= k < i : v[k] = 0
	// uno = #k : 0 <= k < i : v[k] = 1
	//p = numCeros(v,0,p+1) = numUnos(v,0,p+1)
	//forall z : p < z < i ==> numCeros(v,0,z+1) != numUnos(v,0,z+1)
	//Funcion de Cota v.length - i;
	while (i < v.size()) {
		if (v.at(i) == 0) {
			numCeros++;
		}
		if (v.at(i) == 1) {
			numUnos++;
		}
		if (numCeros == numUnos) {
			p = i;
		}
		i++;
	}
	cout << p << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numerosV;
	unsigned int numCasos;
	std::cin >> numCasos;

	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numerosV;
		vector<int> v(numerosV);
		for (int i = 0; i < numerosV; i++) {
			cin >> v[i];
		}
		resuelveCaso(v);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

//Postcondicion{-1<= p < v.lenght && (#k:0<=k<=p : v[k] == 0) = (#k :0 <= k <= p::v[n] = 1)