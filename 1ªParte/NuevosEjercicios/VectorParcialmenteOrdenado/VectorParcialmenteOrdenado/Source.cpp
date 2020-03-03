//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000


bool parcialmenteOrdenadoG(vector<int> &datos, int a, int b, int &mx, int &mn) {
	if (a + 1 == b) {
		mx = max(datos[a], datos[b]);
		mn = min(datos[a], datos[b]);
		return datos[a] <= datos[b];
		
	}	
	else{
		int mitad = (a + b) / 2;
		int maxD, maxIz, minD, minIz;
		bool izq = parcialmenteOrdenadoG(datos, a, mitad, maxIz, minIz);
		bool der = parcialmenteOrdenadoG(datos, mitad+1, b, maxD, minD);
		mx = max(maxD, maxIz);
		mn = min(minD, minIz);
		return izq && der && maxIz <= maxD && minIz <= minD;
	}

}


void parcialmenteOrdenado(vector<int> datos, int max, int min) {
	if (parcialmenteOrdenadoG(datos, 0, datos.size() - 1, max, min)){
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int elemento, max = 0, min = 0;
	for (cin >> elemento; elemento; cin >> elemento) {
		vector<int> datos;
		while (elemento != 0) {
			datos.push_back(elemento);
			cin >> elemento;
		}
		parcialmenteOrdenado(datos, max, min);
	}
	return 0;
}