//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//{P: 0 < v.Length && forall k:: 0 <= k < v.Length == > v[k] > 0}

void resuelveCaso() {
	int numeroE = 0, alturaE = 0, inicio = 0, fin = 0, contadorI = 0, contadorF = 0;
	cin >> numeroE >> alturaE;
	vector<int> v(numeroE);
	for (int i = 0; i < numeroE; i++) {
		cin >> v[i];
	}
	//{I: 0 <= i < v.Length}
	//{I: contadorI = #u: forall k: 0 <= k < v.Length: v[k] > t}
	//{I: contadorF = #w: forall k: 0 <= k < v.Length: v[k] > t}
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
//Coste lineal O(n)=>O(v.size()) ya que recorre una vez el vector desde 0 hasta v.size() con el bucle for
//cota v.size()-i
//Q: #u :: forall 0<=u<.size() ==> v[u]>h

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