//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(int numeroP) {
	int llano, posIni = 0, longitud = 0, contadorllanos = 0, contador = 0, aux = 0;
	bool ok = false;
	cin >> llano;
	vector<int> datos(numeroP);
	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	for (int i = numeroP - 1; i >= 1; i--) {
		if (datos[i] < datos[i - 1]) {
			posIni = datos[i - 1];
			contador++;
			ok = true;
		}
		
		else if (datos[i] == datos[i - 1]) {
			aux++;
			if(ok) contador++;
			else {
				posIni = datos[i];
			}
			
		}
		
		else {
			contador = 0;
			aux = 0;
			ok = false;
		}
		if (contador == llano) {
			contadorllanos++;
		}
		if (aux > longitud) {
			longitud = aux;
		}
	}
	if (contadorllanos == 0) {
		longitud = 0;
		cout << longitud << " " << contadorllanos << endl;
	}
	cout << longitud << " " << contadorllanos << " " << posIni << endl;
	
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numeroP;
	// Resolvemos
	while (std::cin >> numeroP) {
		resuelveCaso(numeroP);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}