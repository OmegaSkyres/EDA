//Roberto Torres Prensa

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void ordenar(vector<int> &datos) {
	int temporal;

	for (int i = 0; i < datos.size(); i++) {
		for (int j = 0; j < datos.size() - 1; j++) {
			if (datos[j] < datos[j + 1]) { // Ordena el array de mayor a menor
				temporal = datos[j];
				datos[j] = datos[j + 1];
				datos[j + 1] = temporal;
			}
		}
	}

}

//Coste de la funcion: O(n), ya que recorre todos los n elementos del vector en busca de llanos

//requires l > 1

int resolver(vector<int> datos, vector<int>& sol, int l) {
	int cont = 1, max = 0;
	int i;
	int h = datos[datos.size() - 1];

	for (i = datos.size() - 2; i >= 0; i--)
		//invariant 0 <= i <= datos.size() - 2
		//decreases i
	{
		if (datos[i] > h) { //si se encuentra una altura mas alta que las vistas hasta el momento
			if (cont >= l) {
				sol.push_back(i + cont);
				if (cont > max)
					max = cont;
			}
			cont = 1;
			h = datos[i];
		}

		else if (datos[i] == h) //si la altura es igual
			cont++;

		else { //si pasamos a una altura mas baja
			if (cont >= l) {
				sol.push_back(i + cont);
				if (cont > max)
					max = cont;
			}
			cont = 0;
		}
	}

	if (cont != 0) { //si el ultimo elemento es un llano el bucle no lo contabiliza
		if (cont >= l) {
			//sol.push_back(j - cont + 1);
			sol.push_back(i + cont);
			if (cont > max)
				max = cont;
		}
	}

	return max;
}

//ensures 0 <= sol.size() <= datos.size() / l
//ensures max == max p, q :: 0 <= p <= q < datos.size() - 2 :: forall i :: p <= i <= q ==> datos[i] >= l 

bool resuelveCaso() {
	int n, l, max;
	cin >> n;
	if (!std::cin)
		return false;
	cin >> l;

	vector<int> sol;
	vector<int> datos(n);
	for (int i = 0; i < n; i++) {
		cin >> datos[i];
	}

	max = resolver(datos, sol, l);
	ordenar(sol);

	cout << max << " " << sol.size();
	for (int i = 0; i < sol.size(); i++) {
		cout << " " << sol[i];
	}
	cout << endl;
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