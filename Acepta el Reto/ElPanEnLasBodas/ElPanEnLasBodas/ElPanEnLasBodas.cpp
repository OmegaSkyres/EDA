
// Roberto Torres Prensa

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool resuelveCaso() {
	int numeroA;
	char mesa;
	bool comerD = true, comerI = true;

	cin >> numeroA;
	if (numeroA == 0) {
		return false;
	}
	std::vector<char> v;
	for (int i = 0; i < numeroA; i++) {
		cin >> mesa;
		v.push_back(mesa);
	}
	for (int i = 0; i < v.size() && (comerD || comerI);  i++){
		if (v.at(i) == 'I') { 
			comerI = false;
		}
		else if (v.at(i) == 'D') {
			comerD = false;
		}
		
	}
	if (!comerD && !comerI) {
		cout << "ALGUNO NO COME" << endl;
	}
	else cout << "TODOS COMEN" << endl;
	return true;
}


int main() {
	/*
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/
	while (resuelveCaso());
	/*
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
*/
	return 0;
}