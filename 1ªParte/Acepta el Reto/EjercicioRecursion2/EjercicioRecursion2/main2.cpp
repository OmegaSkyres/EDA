// Roberto Torres Prensa
#include <iostream>
#include <vector>
using namespace std;


bool resuelve(vector<int> &datos, int a, int b, int k) {
	int posicion, mitad;
	bool ok, ok2, ok3, disperso = false;

	if (a == b) {
		disperso = true;
	}
	else {
	
		if (abs(datos[b - 1] - datos[a]) >= k) {
			disperso = true;
			
			
		}
	}
	
	
	return disperso;
}
//Analisis y justificacion del coste
/*
   Costes
   n = numero de elementos
   T(n) = c0 si n = 1
		  T(n/2) +c2 > 1

		  A == 3
		  B == 2          A = B^K ==> 2 llamadas de tamaño la mitad + 1 tamaño del vector = O(n)
		  K == 0




*/

void resuelveCaso(int nTiradas, int dispersion) {
	bool ok, ok1, ok2;
	int elemento, mitad;
	vector<int> datos;
		for (int i = 0; i < nTiradas; i++) {
			cin >> elemento;
			datos.push_back(elemento);
		}

		mitad = (0 + datos.size() / 2);
		ok = resuelve(datos, 0, datos.size(), dispersion);
		ok1 = resuelve(datos, 0, mitad, dispersion);
		ok2 = resuelve(datos, mitad, datos.size(), dispersion);
	
	if (ok && ok2 && ok2) {
		cout << "SI" << endl;
	}
	else
		cout << "NO" << endl;
	
}


int main() {
	int nTiradas, dispersion;
	while (std::cin >> nTiradas >> dispersion) {
		resuelveCaso(nTiradas, dispersion);
	}
	


	system("PAUSE");
	return 0;
}


