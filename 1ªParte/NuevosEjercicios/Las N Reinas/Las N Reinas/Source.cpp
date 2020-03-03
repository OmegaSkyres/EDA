//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resolver(vector<int>& solucion, vector<bool> &marcas, int k, int &n) {
	for (int i = 0; i < (n*n); i++) {
		if (!marcas[i]) {
			solucion[i] = i;





		}

	}
	

}

bool resuelveCaso() {
	int n;
	//resuelve aqui tu caso
	   //Lee los datos
	   //Calcula el resultado
	   //Escribe el resultado
	
	cin >> n;
	vector<int> solucion(n);
	vector<bool> marcaje(n, false);

	if (!std::cin)
		return false;

	resolver(solucion,marcaje,1,n)

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}