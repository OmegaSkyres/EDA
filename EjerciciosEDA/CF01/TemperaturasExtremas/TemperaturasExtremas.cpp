//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//{P: true}
void resuelveCaso() {
	int numeroP, contadorP = 0, contadorV = 0;
	cin >> numeroP;
	vector<int> datos(numeroP);
	//{I: 1 <= i < datos.size()}
	//{I: contadorP = #u: forall k: 1 <= k < n-1: a[k] > a[k+1] && a[k] > a[k-1]}
	//{I: contadorV = #u: forall k: 1 <= k < n-1: a[k] < a[k+1] && a[k] < a[k-1]}
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
//{Q: contadorP = #u: forall k: 1 <= k < n-1: a[k] > a[k+1] && a[k] > a[k-1]}
//{Q: contadorV = #u: forall k: 1 <= k < n-1: a[k] < a[k+1] && a[k] < a[k-1]}
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