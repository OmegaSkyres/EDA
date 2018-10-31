//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//{P: 0 < datos.size() <= 1000 && forall k: 0 <= k < datos.size() ==> 0 <= datos[k] <= 10}
void resuelveCaso() {
	int numeroP = 0, contadorB = 0, contadorS = 0;
	cin >> numeroP;
	if(numeroP!= 0){
		vector<int> datos(numeroP);
		//{I: 1 <= i < datos.size()}
		//{I: contadorB = #u: i <= u < datos.size() - 1: datos[i] == 5 datos[u] > datos[u + 1] < i}
		//{I: contadorS = #u: i <= u < datos.size() - 1: datos[i] == 9 datos[u] < datos[u + 1] < i}

		for (int i = 0; i < numeroP; i++) {
			cin >> datos[i];
		}
		for (int i = 1; i < numeroP - 1; i++) {
			if (datos[i] > datos[i + 1] && datos[i] == 5) { //Condición de Bombardeo
				contadorB++;
			}
			else if (datos[i] < datos[i + 1] && datos[i] == 9) { //Condición de llegada de ayudas
				contadorS++;
			}
		}
	}
	
	cout << contadorB << " " << contadorS << endl;
}
//Funcion de Cota datos.size() - 1
//{Q: contadorB = #u: 1 <= u < datos.size() - 1: datos[i] == 5 datos[u] > datos[u + 1]}
//{Q: contadors = #u: 1 <= u < datos.size() - 1: datos[i] == 9 datos[u] < datos[u + 1]}
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