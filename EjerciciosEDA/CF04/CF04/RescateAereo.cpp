//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Precondición P{Exist z: 0<= alturaE < z &&  z = v[i] }

void resuelveCaso() {
	int numeroE = 0, alturaE = 0, inicio = 0, fin = 0, contador = 0, contadorA = 0, inicioA = 0;
	bool ok = true;
	cin >> numeroE >> alturaE;
	vector<int> v(numeroE);
	for (int i = 0; i < numeroE; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < numeroE; i++) {
		if ((v[i] > alturaE) && (ok == true)) {
			ok = false;
			inicio = i;
		}
		else if ((v[i] < alturaE) && (ok == false) && (contadorA < contador)) {
			fin = i - 1;
			ok = true;
			contadorA = contador;
			inicioA = inicio;
			contador = 0;
		}
		if (ok == false) {
			contador++;
		}
		
		
		
	}
	cout << inicioA << " " << fin << endl;
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