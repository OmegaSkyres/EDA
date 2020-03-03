//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string gritoG(const int n, const int i, const int j) {
	if (n == 1) {
		if (i <= j) {
			return gritoG(n-1,i,(j - (n + 1))/2);
		}
		if ((j + (n + 2) + 1) <= i) {
			return gritoG(n - 1, i - (j + (n + 2)), (j - (n + 1)) / 2);
		}
		if (i == j + 1) {
			return "B";
		}
		if (i == j + (n + 2)) {
			return "H";
		}
		return "U";
		
	}
	

}

//Analisis y justificacion del coste
/*
   Costes
   n = numero de elementos
   T(n) = c0 si n = 1
		  c1 si n = 2
		  T(n/2) +c2 >2

		  A == 1
		  B == 2          A = B^K ==> 1 = 2^0 (1=1) ==> O(n^k*LogN) = O(1*logN) = O(logN)
		  K == 0


*/

void grito(int palabra, int elemento) {
	cout << gritoG(palabra, 0, elemento) << endl;
}


int main() {
	// Para la entrada por fichero.

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos

	int elemento = 0;
	int palabra = 0;
	// Resolvemos
	while (std::cin >> palabra) {
		cin >> elemento;
		grito(palabra, elemento);
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}