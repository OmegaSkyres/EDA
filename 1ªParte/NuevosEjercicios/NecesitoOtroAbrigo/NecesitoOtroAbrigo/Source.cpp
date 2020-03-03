// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema

bool esValida(vector<int> datosD, vector<int> datosA, vector<int>sol, int numDias, int numAbrigos, int k, vector<int> marcas, const int i) {
	if (k > 0 && sol[k] == sol[k - 1]) return false; //Dos iguales seguidos
	if (datosD[k] > datosA[i]) return false; //No aguante el abrigo
	if (k > 0 && marcas[i] + 1 > (2 + (k / 3))) return false;
	if (k == numDias && sol[0] == sol[k]) return false;
	return true;
}

void resolver(vector<int> datosD, vector<int> datosA, vector<int> &marcas, vector<int>& sol, const int numDias, const int numAbrigos, int k, int &solu) {
	for (int i = 0; i < numAbrigos; i++){
		sol[k] = i;
			if (esValida(datosD, datosA, sol,numDias,numAbrigos,k,marcas, i)) {
				if (k == numDias -1) {
					solu++;
				}
				else
				{
					marcas[i]++;
					resolver(datosD, datosA, marcas, sol, numDias, numAbrigos, k + 1, solu);
					marcas[i]--;
				}
			}
	}
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	int numDias, numAbrigos, solu = 0;
	cin >> numDias >> numAbrigos;
	vector<int> datosD(numDias);
	vector<int> datosA(numAbrigos);
	vector<int> marcas(numAbrigos,0);
	vector<int> sol(numDias);
	while (numDias != 0 && numAbrigos != 0) {
		for (int i = 0; i < numDias; i++) {
			cin >> datosD[i];
		}
		for (int j = 0; j < numAbrigos; j++) {
			cin >> datosA[j];
		}
		resolver(datosD, datosA, marcas, sol, numDias, numAbrigos,0,solu);
		if (solu == 0) cout << "Lo puedes comprar." << endl;
		else cout << solu << endl;
		cin >> numDias >> numAbrigos;
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}