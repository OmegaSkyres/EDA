//Roberto Torres Prensa
// Fernando Bellot Rodriguez

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Cancion {
	int duracion;
	int puntuacion;
};


bool ultimoHijoNivel(int k){

}

bool esValido( vector<Cancion> &c, int k)
{
	return  c[k] ;
}


//Implementa aqui tu solucion vuelta atras
//Explicaciones

int vueltaAtras(vector<Cancion> canciones, int cara1, int cara2, int &resultadoOptimo) {
	vector<int> sol, int i = 0, int k, int resultadoOptimo;
	


	if (tama�oA < c[i].duracion) { // Caso Cara A
		tama�oA += c[i].duracion;
	}
	else if (tama�oB < c[i].duracion && tam) { //Caso Cara B
		tama�oB += c[i].duracion;
	}

	else if (T <= tama�oA + c[i].duracion && T <= tama�oB + c[i].duracion) { // No cogerlo





	}
	while (!ultimoHijoNivel(T)) {
		sol[T]=
	}


	return resultadoOptimo;
}




bool casoDePrueba() {
	int N;
	vector<bool> marcador;
	cin >> N;  //  N canciones

	if (N == 0) {
		return false;
	}

	// tiempo en una cara
	int T;
	cin >> T;

	vector<Cancion> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i].duracion >> C[i].puntuacion;
	}

	int puntuacion_mejor;

	puntuacion_mejor = vueltaAtras(C, T, 0, 0, 0);
	//Llama aqui a tu algoritmo vuelta atras


	cout << puntuacion_mejor << '\n';
	//Por si quieres imprimir la solucion mejor
	//  for (auto e : sol_mejor)  cout << e << ' '; cout << '\n';

	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (casoDePrueba());

	// restablecimiento de cin

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
