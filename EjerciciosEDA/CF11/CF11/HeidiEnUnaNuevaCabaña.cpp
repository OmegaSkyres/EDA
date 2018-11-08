//Roberto Torres Prensa

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void ordenar(vector<int> &datos) {
	int aux;

	for (int i = 0; i < datos.size(); i++) {
		for (int j = 0; j < datos.size() - 1; j++) {
			if (datos[j] < datos[j + 1]) { // Ordena el array de mayor a menor
				aux = datos[j];
				datos[j] = datos[j + 1];
				datos[j + 1] = aux;
			}
		}
	}

}

//Coste de la funcion: O(n), ya que recorre todos los n elementos del vector



int resolver(vector<int> datos, vector<int>& sol, int l) {
	int cont = 1, max = 0, i;
	int longitud = datos[datos.size() - 1];

	for (i = datos.size() - 2; i >= 0; i--)
	
	{
		if (datos[i] > longitud) { 
			if (cont >= l) {
				sol.push_back(i + cont);
				if (cont > max)
					max = cont;
			}
			cont = 1;
			longitud = datos[i];
		}

		else if (datos[i] == longitud) 
			cont++;

		else { 
			if (cont >= l) {
				sol.push_back(i + cont);
				if (cont > max)
					max = cont;
			}
			cont = 0;
		}
	}

	if (cont != 0) { 
		if (cont >= l) {
			sol.push_back(i + cont);
			if (cont > max)
				max = cont;
		}
	}

	return max;
}


bool resuelveCaso() {
	int numero, l, maximo;
	cin >> numero;
	if (!std::cin)
		return false;
	cin >> l;

	vector<int> sol;
	vector<int> datos(numero);
	for (int i = 0; i < numero; i++) {
		cin >> datos[i];
	}

	maximo = resolver(datos, sol, l);
	ordenar(sol);

	cout << maximo << " " << sol.size();
	for (int i = 0; i < sol.size(); i++) {
		cout << " " << sol[i];
	}
	cout << endl;
	return true;
}


int main() {

	
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}