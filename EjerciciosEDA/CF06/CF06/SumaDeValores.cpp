//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//P: datos!=null
// Coste lineal en funcion de v.Length: O(n)
void resuelveCaso() {
	int numeros, maximo = 0, posMax = 0, suma = 0, i = 0;
	cin >> numeros;
	vector<int> datos(numeros);
	//cota v.size()-i
	//I: 0<=i<=v.size()
	//I: maximo = forall w:: 0<=w<i==> maximo>v[w]
	//I: forall u:: 0<=u<maximo<i =>  && (sum(v[u]) - #maximo*maximo)
	for (int i = 0; i < numeros; i++) {
		cin >> datos[i];
	}
	if (datos.empty()) {
		suma = 0;
	}
	else {
		maximo = datos[0];
		for (int i = 1; i < numeros; i++) { //Calcula el Maximo y empiezas a mirar desde el 1 porque el primer elemento siempre va a ser el maximo
			if (maximo < datos[i]) {	
				maximo = datos[i];
			}
		}
		if (maximo != 0){
			while (i < datos.size()) {
				if (datos[i] != maximo) {
					suma += datos[i];
				}
				i++;
			}
		}

		
			
	}
	cout << suma << endl;

}
//Q: maximo = forall w:: 0<=u<datos.size()==> maximo>v[w]
//Q: suma = forall u:: 0<=u<maximo<datos.size() =>  && (sum(v[u]) - #maximo*maximo) 

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
