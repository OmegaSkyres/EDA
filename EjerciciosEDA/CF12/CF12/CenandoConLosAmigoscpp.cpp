//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(int numeroE) {
	int maximo = 0, suma = 0, contador = 0, diaIni = 0, i = 0, auxS = 0, auxC = 0, auxM = 0;
	bool ok = true;
	vector<int> datos(numeroE);
	for (i = 0; i < numeroE; i++) {
		cin >> datos[i];
	}
	i = 0;
	while (i < numeroE) {
		suma += datos[i];
		if (suma <= 0) {
			contador = 0;

		}





		if (datos[i] > 0) {
			contador++;
			maximo = datos[i];
			if (maximo > auxM) {
				auxM = maximo;
			}
			if (suma > auxS) {
				suma += datos[i];
				auxS = suma;
				if (ok) {
					diaIni = i;
					ok = false;
				}
				auxC = contador;
			}
			else if (suma == auxS) {
				if (contador < auxC) {
					auxC = contador;
				}
			}
		}
		
		i++;
	}
	
	cout << auxS << " " << diaIni << " " << auxC << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numeroE = 0;
	// Resolvemos
	while (std::cin >> numeroE) {
		resuelveCaso(numeroE);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}