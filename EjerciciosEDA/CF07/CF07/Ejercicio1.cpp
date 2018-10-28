//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	int nElementos, j, aux = 0, division = 0;
	cin >> nElementos;
	j = nElementos - 1;
	vector<int>datos(nElementos);
	for (int i = 0; i < nElementos; i++) {
		cin >> datos[i];
	}
	if (!datos.empty()) {
		for (int i = 0; i < nElementos; i++) {
			
			if (datos[i] < 0) {
				while (datos[j] < 0 && j > 0 && i < j) {
					j--;
					
				}
				aux = datos[i];
				datos[i] = datos[j];
				datos[j] = aux;
			}
		
		}
		while (division < datos.size() && datos[division] >= 0) {
			division++;
		}
		cout << division << endl;
	}
	

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