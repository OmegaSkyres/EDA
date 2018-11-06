//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int resolver(vector<int> &datos, vector<int> &solucion, int llano) {
	int contador = 1, max = 0, i;
	int longitud = datos.size() - 1;
	for (i = datos.size() - 2; i >= 0; i--) {
		if (datos[i] > longitud) {
			if (contador >= llano) {
				solucion.push_back(i + contador);
				if (contador > max) {
					max = contador;
				}
			}
			contador = 1;
			longitud = datos[i];
		}

		else if (datos[i] == longitud) {
			contador++;
		}

		else {
			if (contador >= llano) {
				solucion.push_back(i + contador);
				if (contador > max) {
					max = contador;
				}
			}
			contador = 0;
		}
	}

	if (contador != 0) {
		if (contador >= llano) {
			solucion.push_back(i + contador);
			if (contador > max) {
				max = contador;
			}
		}
	}
	return max;
}

void ordenar(vector<int> &datos) {
	int aux = 0;
	for (int i = 0; i < datos.size(); i++) {
		for (int j = 0; j < datos.size() - 1; j++) {
			if (datos[j] < datos[j + 1]) {
				aux = datos[j];
				datos[j] = datos[j + 1];
				datos[j + 1] = aux;
			}
		}
	}
}


bool resuelveCaso() {
	int llano, max, nElementos;
	cin >> nElementos;
	if (!std::cin) {
		return false;
	}
	cin >> llano;
	vector<int> datos(nElementos);
	vector<int> solucion;
	for (int i = 0; i < nElementos; i++) {
		cin >> datos[i];
	}
	max = resolver(datos, solucion, llano);
	ordenar(solucion);

	cout << max << " " << solucion.size();
	for (int i = 0; i < solucion.size(); i++) {
		cout << " " << solucion[i];
	}
	cout << endl;

	return true;
}




int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numeroP;
	// Resolvemos
	resuelveCaso();
	


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}