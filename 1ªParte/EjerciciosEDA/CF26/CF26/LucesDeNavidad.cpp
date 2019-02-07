
// Roberto Torres Prensa

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void tratarSolucion(std::vector <int>& solucion, int const& k) {
	for (int i = 0; i <= k; i++) {
		cout << solucion[i] << " ";
	}

	cout << endl;
}


bool esValida(vector<int> &consumos, vector<int> &solucion, vector<int> &marcaje, int k, int &longitud, int &numeroColores, int &consumoMaximo, int &consumoAct, int &contBombillas, int &i) {
	if (consumoAct <= consumoMaximo){
		if (marcaje[i] <= k + 1 + 1 - marcaje[i]) {
			if (k >= 2) {
				if (solucion[k] == solucion[k + 1] == solucion[k + 2]) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}
		}
		else {
			return false;
		}
		
	}
	else {
		return false;
	}
	
}


void resolver(vector<int> &solucion, vector<int> &marcaje, vector<int> &consumos, int k, int &longitud, int &numeroColores, int &consumoMaximo, int &consumoAct, int &contBombillas) {
	for (int i = 0; i < numeroColores; i++) {
		solucion[k] = i;
		consumoAct += consumos[i];
		marcaje[i]++;
		if (esValida(consumos, solucion, marcaje, k, longitud, numeroColores, consumoMaximo, consumoAct, contBombillas, i)) {
			if (k == longitud - 1) {
				tratarSolucion(solucion, k);
				contBombillas++;
			}
		}
		else {
			resolver(solucion, marcaje, consumos, k + 1, longitud, numeroColores, consumoMaximo, consumoAct, contBombillas);
		}

		consumoAct -= consumos[i];
		marcaje[i] --;
		
	}
}

bool resuelveCaso() {
	int longitud, numeroColores, consumoMaximo;
	cin >> longitud >> numeroColores >> consumoMaximo;
	vector<int> solucion(longitud);
	vector<int> marcaje(numeroColores);
	vector<int> consumos(numeroColores);

	int consumoAct = 0, contBombillas = 0;
	for (int i = 0; i < numeroColores; i++) {
		cin >> consumos[i];
	}
	resolver(solucion, marcaje, consumos, 0, longitud, numeroColores, consumoMaximo, consumoAct, contBombillas);
	//Leer caso de prueba

	if (!std::cin)
		return false;


	//Resolver problema
	//Escribir resultado
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}