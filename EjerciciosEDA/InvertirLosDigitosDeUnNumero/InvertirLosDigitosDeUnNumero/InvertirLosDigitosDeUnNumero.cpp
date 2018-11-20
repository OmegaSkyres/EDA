
// Roberto Torres Prensa

#include <iostream>
#include <fstream>
using namespace std;


struct sol {
	int numero = 0;
	int pot = 1;
};

//{P: 0 <= n <= (2^31)-1}
sol invertir(long long int numero) {

	sol resultado;
	if (numero != 0) {
		resultado = invertir(numero / 10);
		resultado.numero += (numero % 10 * resultado.pot);
		resultado.pot = resultado.pot * 10;
	}
	return resultado;
}
//{Q: solucion = invertir(n/10)}
 

void resuelveCaso(long long int numero) {
	sol resultado = invertir(numero);
	
	
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


