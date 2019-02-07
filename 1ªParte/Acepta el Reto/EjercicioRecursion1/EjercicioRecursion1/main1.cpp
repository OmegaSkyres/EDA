#include <iostream>
#include <vector>
using namespace std;


int resuelve(vector<int> &datos, int a, int b) {
	int posicion, mitad;
	//Caso base
	if (a == b) { // Un unico elemento
		posicion = a;
	}
	else if (a + 2 == b) { 
		if (datos[a] == datos[a + 1]) {  // Con 3 elemenos al final
			posicion = b;
		}
		else {  // Con 3 elemenos al principio
			posicion = a;
		}
	}
	
	else { //Caso recursivo 
		mitad = (a + b) / 2;
		if ((mitad - a) % 2 == 0) {
			if (datos[mitad] != datos[mitad + 1]) {
				posicion = resuelve(datos, a, mitad);
			}
			else {
				posicion = resuelve(datos, mitad, b);
			}

		}
		else {
			if (datos[mitad] != datos[mitad + 1]) {
				posicion = resuelve(datos, mitad + 1, b);
			}
			else {
				posicion = resuelve(datos, a, mitad - 1);
			
			}
		}
		

	}

	return posicion;
}

//Analisis y justificacion del coste
/*
   Costes
   n = numero de elementos
   T(n) = c0 si n = 1
		  c1 si n = 3
		  T(n/2) +c2 >3

		  A == 1
		  B == 2          A = B^K ==> 1 = 2^0 (1=1) ==> O(n^k*LogN) = O(1*logN) = O(logN)
		  K == 0




*/

void resuelveCaso() {

	int nElementos, elemento, posicion;
	vector<int> datos;
	cin >> nElementos;
	for (int i = 0; i < nElementos; i++) {
		cin >> elemento;
		datos.push_back(elemento);
	}

	posicion = resuelve(datos, 0, datos.size() - 1);
	cout << posicion << endl;
}


int main() {
	int entrada;

	cin >> entrada;
	for (int i = 0; i < entrada; i++) {
		resuelveCaso();
	}


	system("PAUSE");
	return 0;
}


 