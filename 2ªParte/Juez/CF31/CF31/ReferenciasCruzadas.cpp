
// Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>	
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

bool resuelveCaso() {
	map<string, vector<int>> valores;
	int numCasos;
	string frase, clave, trash;
	cin >> numCasos;
	if (numCasos == 0) {
		return false;
	}
	getline(cin, trash);
	for (int i = 0; i < numCasos; i++) {
		getline(cin, frase);
		stringstream ss(frase);
		ss.clear();
		ss.str(frase);
		while (ss >> clave) {
			if (clave.length() > 2) {
				transform(clave.begin(), clave.end(), clave.begin(), ::tolower);
				if (valores.count(clave)) {
					vector<int>& v_ref = valores[clave];
					if (v_ref.empty() || v_ref[v_ref.size() - 1] < i + 1) {
						valores[clave].push_back(i + 1);
					}
				}
				else {
					valores[clave].push_back(i + 1);
				}
			}
		}
	}
	for (auto it = valores.begin(); it != valores.cend(); it++) {
		std::cout << it->first;
		for (int i = 0; i < it->second.size(); i++)
			std::cout << " " << it->second[i];
		std::cout << "\n";
	}
	cout << "----" << endl;
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