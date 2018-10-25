//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//{P: 0 < datos.size() <= 10000 && forall k: 0 <= k < datos.size() ==> -50 <= datos[k] <= 60}
void resuelveCaso() {
	int numeroP, contadorP = 0, contadorV = 0;
	cin >> numeroP;
	vector<int> datos(numeroP);
	//{I: 1 <= i < datos.size()}
	//{I: contadorP = #u: i <= u < datos.size() - 1: datos[u - 1] < datos[u] > datos[u + 1] < i}
	//{I: contadorV = #u: forall k: 1 <= k < n-1: a[k] < a[k+1] && a[k] < a[k-1]} // No se si esta hace falta

	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	for(int i = 1; i < numeroP - 1; i++){
		if (datos[i] > datos[i + 1] && datos[i] > datos[i - 1]) {
			contadorP++;
		}
		else if (datos[i] < datos[i + 1] && datos[i] < datos[i - 1]) {
			contadorV++;
		}
	}
	cout << contadorP << " " << contadorV << endl;
}
//{Q: contadorP = #u: 1 <= u < datos.size() - 1: datos[u - 1] < datos[u] > datos[u + 1]}
//{Q: contadorV = #u: 1 <= u < datos.size() - 1: datos[u - 1] > datos[u] < datos[u + 1]}
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