//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Precondición P{Exist z: 0<= alturaE < z &&  z = v[i] }

void resuelveCaso() {
	int numeroE = 0, alturaE = 0, inicio = 0, fin = 0, contadorI = 0, contadorF = 0;
	cin >> numeroE >> alturaE;
	vector<int> v(numeroE);
	for (int i = 0; i < numeroE; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < numeroE; i++) {
		if (v[i] > alturaE) {
			contadorI++;
		}
		else {
			contadorI = 0;
		}
		if (contadorF < contadorI) { //Al ser menor estricto aseguras que en caso de empate te quedas con el de la izquierda por que es el primero que lees
			inicio = i + 1 - contadorI;
			fin = i;
			contadorF = contadorI;
		}
		
		
		
	}
	cout << inicio << " " << fin << endl;
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
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