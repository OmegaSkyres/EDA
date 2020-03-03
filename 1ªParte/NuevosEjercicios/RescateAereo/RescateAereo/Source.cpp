// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema

void resolver(const vector<int> datos, const int numEdificios, const int altura) {
	int contador = 0, solB = 0, a = 0, b = 0;
	for (int i = 0; i < numEdificios; i++) {
		if (datos[i] > altura) {
			contador++;
		}
		else {	
			if (contador > solB) {
				solB = contador;
				a = i - contador;
				b = i - 1;
			}
			contador = 0;
		}
	}
	cout << a << " " << b << endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int numCasos, numEdificios, altura;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> numEdificios >> altura;
		vector<int> datos(numEdificios);
		for (int i = 0; i < numEdificios; i++) {
			cin >> datos[i];
		}
		resolver(datos, numEdificios, altura);
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}