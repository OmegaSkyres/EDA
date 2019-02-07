
// Roberto Torres Prensa

#include <iostream>
#include <fstream>
using namespace std;


struct solucion {
	long long int numero = 0;
	int pot = 1;
};

//{Precondicion: 0 <= n <= (2^31)-1}
solucion invertir(long long int numero) {

	solucion resultado;
	if (numero != 0) {
		resultado = invertir(numero / 10);
		resultado.numero += (numero % 10 * resultado.pot);
		resultado.pot = resultado.pot * 10;
	}
	return resultado;
}

//Analisis del coste: plantea la recurrencia e indica la solucion de la misma
/*
	T(n) = {
			Co si numero != 0
			T(numero-1) + Co si n > 0
		   }
	con numero = valor del elemento
	Por lo tanto T(n) pertenece a O(n)
*/
//{PostCondicion: resultado = invertir(n/10)}
 

void resuelveCaso(long long int numero) {
	solucion resultado = invertir(numero);
	
	
	cout << resultado.numero << endl;

	//Resolver problema
	//Escribir resultado

}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	long long int n;

	while (std::cin >> n) {
		resuelveCaso(n);
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}


