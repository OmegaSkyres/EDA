//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//coste lineal O(n)=>O(v.size()) ya que solo se recorre una vez el vector
//P: v!=null
void resuelveCaso(int numeroP) {
	int contadorG = 0, contadorRepeticionesG = 0, contadorJ = 0, maximoG = 0;
	vector<int> datos(numeroP);
	for (int i = 0; i < numeroP; i++) {
		cin >> datos[i];
	}
	//cota v.size()-i
	//I: 0<=i<=datos.size()
	//I: #u::forall u :: 1<=u<i ==> datos[u]>0 && datos[u-1]>0::#u && #w::forall w:: u<=w<i ==> datos[w]!=datos[u]::#w
	for (int i = 0; i < numeroP; i++) {
		if (datos[i] > 0) {
			contadorG++;
		}
		else {
			contadorG = 0;
		}
		if (contadorG > maximoG ) {
			maximoG = contadorG;
			contadorRepeticionesG = 1;
			contadorJ = i + 1;
		}
		else if (contadorG == maximoG && contadorG > 0) {
			contadorRepeticionesG++;
			contadorJ = i + 1;
		}
	}
	contadorJ = numeroP - contadorJ;

	cout << maximoG << " " << contadorRepeticionesG << " " << contadorJ << endl;
	//Q: maximoG == #u::forall u :: 1<=u<v.size() ==> v[u]>0 && v[u-1]>0::#u
	//contadorRepeticionesG == #maxR
	//ContadorJ == #w::forall w:: u<=w<v.size() ==> v[w]!=v[u]::#w
	
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numeroP;
	// Resolvemos
	while (std::cin >> numeroP) {
		resuelveCaso(numeroP);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}