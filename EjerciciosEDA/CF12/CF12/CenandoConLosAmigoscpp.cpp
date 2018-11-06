//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(int numeroE) {
	int maximo = 0, suma = 0, contador = 0, diaIni = 0, contMax = 0;
	bool ok = true;
	vector<int> datos(numeroE);
	for (int i = 0; i < numeroE; i++) {
		cin >> datos[i];
	}
	suma = 0;
	for (int i = 0; i < numeroE; i++) {
		suma += datos[i];

		if (suma <= 0) {
			if (datos[i] <= 0) {
				suma = 0;
			}
			else {
				suma = datos[i];
			}
			contador = 0;
		}

		if (suma > 0) {
			contador++;
			if (suma > maximo) {
				maximo = suma;
				contMax = contador;
				diaIni = i - contador + 1;
			}
			else if (suma == maximo) {
				if (contador < contMax) {
					contMax = contador;
					diaIni = i - contador + 1;
				}
			}
		}



	}
	
	cout << maximo << " " << diaIni << " " << contMax << endl;
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