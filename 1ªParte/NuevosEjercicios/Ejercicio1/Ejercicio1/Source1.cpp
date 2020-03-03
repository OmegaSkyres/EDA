//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int resuelveCaso(int entrada) {
	return entrada * 2;
}

int main() {
	


	unsigned int numCasos;
	int entrada;
	std::cin >> numCasos;
	
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> entrada;
		cout << resuelveCaso(entrada) << endl;
	}

	return 0;
}