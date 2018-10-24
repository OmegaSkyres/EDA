//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<int> v) {
	int p = -1;
	int cero = 0, uno = 0;
	int i = 0;
	// -1 < p < v.length && 0 <= i <= v.length
	// cero = #k : 0 <= k < i : v[k] = 0
	// uno = #k : 0 <= k < i : v[k] = 1
	//p = Numcero(v,0,p+1) = numUno(v,0,p+1)
	//forall z : p < z < i ==> numCero(v,0,z+1) != numUno(v,0,z+1)
	//Funcion de Cota v.length - i;
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