//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	int numeros, maximo = 0, posMax = 0, suma = 0, i = 0;
	cin >> numeros;
	vector<int> datos(numeros);
	for (int i = 0; i < numeros; i++) {
		cin >> datos[i];
	}
	if (datos.empty()) {
		suma = 0;
	}
	else {
		maximo = datos[0];
		for (int i = 1; i < numeros; i++) { //Calcula el Maximo y empiezas a mirar desde el 1 porque el primer elemento siempre va a ser el maximo
			if (maximo < datos[i]) {	
				maximo = datos[i];
			}
		}
		if (!datos.empty() && maximo != 0){
			while (i < datos.size()) {
				if (datos[i] != maximo) {
					suma += datos[i];
				}
				i++;
			}
		}

		
			
	}
	cout << suma << endl;

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
