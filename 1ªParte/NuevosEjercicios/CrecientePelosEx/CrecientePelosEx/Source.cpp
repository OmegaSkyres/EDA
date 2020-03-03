//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//coste lineal O(n)=> O(v.size()-1) Ya que recorre el vector de principio a fin, o incluso no llega al final
//P: v!=null
bool resuelveCaso(const vector<int>datos, const int numR, const int numElementos) {
	bool aburrido = true;
	int contador = 0;
	for (int i = 0; i < numElementos - 1; i++) {
		if (datos[i] < datos[i + 1] && datos[i+1] - datos[i] == 1) {
			if (datos[i] == datos[i + 1]) {
				contador++;
				if (contador < numR) {
					aburrido = false;
				}
				else {
					aburrido = true;
				}
			}
		}
	}
	return aburrido;
}
//Q
//porPelos = forall u:: 0<=u<v.size()-1 ==> v[u]>v[+1] && v[u+1]-v[u] == 1
//aburrido = #v[u] : forall u:: 0<=u<v.size()-1 ==> #v[u] < repeticones

int main() {
	// Para la entrada por fichero.

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	int numElementos, numR;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numR;
		cin >> numElementos;
		vector<int> datos(numElementos);
		for (int j = 0; j < numElementos; j++) {
			cin >> datos[j];
		}
		if (resuelveCaso(datos, numR, numElementos)) cout << "SI" << endl;
		else cout << "NO" << endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}