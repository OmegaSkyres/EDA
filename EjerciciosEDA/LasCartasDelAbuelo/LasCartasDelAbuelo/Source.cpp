
// NOMBRE Y APELLIDOS

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool resuelveCaso() {
	string cadena;
	int numCasos, max = 0, min = 0;
	char caracter1, caracter2;
	bool ok = true;
	cin >> cadena;
	cin >> numCasos;
	if (numCasos == 0) {
		return false;
	}
	for (int i = 0; i < numCasos; i++) {
		cin >> min;
		cin >> max;
		cin.get(caracter1);
		if (min < max) {
			for (int i = min; i <= max; i++) {
				cin.get(caracter1);
				if (caracter1 == caracter2 && ok) {

				}
				else ok = false;
				caracter1 = caracter2;
			}
		}
		else if (min > max) {
			for (int i = max; i >= min; i--) {
				cin.get(caracter2);
				if (caracter2 == caracter1 && ok) {

				}
				else ok = false;
				caracter2 = caracter1;

			}

		}
	}
		if (ok) cout << "SI" << endl;
		else cout << "NO" << endl;



		//Leer caso de prueba

		/*
		if (!std::cin)
			return false;

		*/
		//Resolver problema
		//Escribir resultado
		return true;
	}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/
	while (resuelveCaso());

	// restablecimiento de cin
	/*
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
	*/
}