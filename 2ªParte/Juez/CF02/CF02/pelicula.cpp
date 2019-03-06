#include <iostream>
#include <fstream>
#include "pelicula.h"
#include <algorithm>
#include <vector>
using namespace std;

//Roberto Torres Prensa


bool resuelveCaso() {
	int numCasos;
	cin >> numCasos;

	if (numCasos == 0) {
		return false;
	}
	vector<pelicula> v(numCasos);

	for (int i = 0; i < numCasos; i++) {
		horas c, d;
		string t = "";

		cin >> c >> d;

		getline(cin, t);

		v[i] = pelicula(c, d, t);
	}
	//ordenamos el vector
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].horaFin() << " " << v[i].titulo() << endl;
	}
	cout << "---" << endl;


	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}