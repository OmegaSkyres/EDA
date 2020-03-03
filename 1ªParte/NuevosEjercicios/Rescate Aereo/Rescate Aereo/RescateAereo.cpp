//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//coste lineal O(n)=> O(v.size()-1) Ya que recorre el vector de principio a fin, o incluso no llega al final
//P: v!=null
void resuelveCaso(vector<int>datos, int altura) {
	int contadorF = 0, contadorI = 0, inicio = 0, fin = 0;
	bool ok = false;
	for (int i = 0; i < datos.size(); i++) {
		if (datos[i] > altura) {
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
	int numEdificios, alturaT;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numEdificios;
		cin >> alturaT;
		vector<int> datos(numEdificios);
		for (int j = 0; j < numEdificios; j++) {
			cin >> datos[j];
		}
		resuelveCaso(datos, alturaT);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}