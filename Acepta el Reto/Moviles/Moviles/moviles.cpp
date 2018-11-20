
// Roberto TOrres Prensa

#include <iostream>

#include <fstream>
using namespace std;

void resolver() {


}


bool resuelveCaso() {

	//Leer caso de prueba
	int pI, pD, dI, dD;
	cin >> pI >> dI >> pD >> dD;
	if (pI == 0 && dI == 0 && pD == 0 && dD == 0)
		return false;
		
	if (resolver()) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	//Resolver problema
	//Escribir resultado
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}