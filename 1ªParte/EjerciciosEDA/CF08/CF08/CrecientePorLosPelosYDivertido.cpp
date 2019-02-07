//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//coste lineal O(n)=> O(v.size()-1) Ya que recorre el vector de principio a fin, o incluso no llega al final
//P: v!=null
void resuelveCaso() {
	int repeticiones = 0, j, contadorE = 1, nElementos, aux;
	bool porPelos = true;
	bool aburrido = true;
	cin >> repeticiones;
	cin >> nElementos;
	vector<int> datos(nElementos);
	for (j = 0; j < nElementos; j++) {
		cin >> datos[j];
	}
	aux = datos[0];
	//cota datos.size() - i
	//I: 0<= i <=datos.size()-1
	//I: porPelos = forall u:: 0<=u<i ==> v[u]>v[+1] && v[u+1]-v[u] == 1
	//I: aburrido = #v[u] : forall u:: 0<=u<i ==> #v[u] < repeticiones
	for (int i = 0; i < (j - 1); i++) {
		if (aux < datos[i + 1] && datos[i + 1] - aux == 1 && contadorE <= repeticiones) {
			aux = datos[i + 1];
			contadorE = 1;	
		}
		else if (aux == datos[i + 1]) {
			contadorE++;
		}
		else {
			porPelos = false;
		}
	
	}
	if (contadorE > repeticiones) {
		aburrido = false;
	}
	//resuelve aqui tu caso
	if (aburrido && porPelos) {
		cout << "SI" << endl;
	}
	else cout << "NO" << endl;
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