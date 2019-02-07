//Iker burgoa muñoz
//Roberto torres
#include <stdio.h>
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;





const unsigned int MAX = 100000;
//Define aqui tu funcion recursiva

int resuelve(int a[], int b[], int i, int j)
{
	int valor;
	if (i == j)
		/*
		Un elemento A tiene un elemento y  B está vacio devuelvo el elemento de a
		*/
	{
		valor = a[i];
	}
	else if (i + 1 == j)
	{
		/*
		B tiene un elemento por eso comparo con i y devuelvo siempre el valor en A
		*/
		if (a[i] == b[i]) { valor = a[j]; }
		else valor = a[i];
	}
	else
	{
		int m = (i + j) / 2;
		//juegas con a
		if (a[m] >= b[m])
		{
			//derecha
			valor = resuelve(a, b, m, j);
		}
		else valor = resuelve(a, b, i, m); //izquierda
	}
	return valor;
}

//Analisis y justificacion del coste
/*
   Costes
   n = numero de elementos
   T(n) = c0 si n = 1
		  c1 si n = 2
		  T(n/2) +c2 >2

		  A == 1
		  B == 2          A = B^K ==> 1 = 2^0 (1=1) ==> O(n^k*LogN) = O(1*logN) = O(logN)
		  K == 0




*/


void resuelve() {
	//Lectura de datos
	int n, m;
	int a[MAX], b[MAX];
	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> a[i]; }
	for (int i = 0; i < n - 1; ++i) { cin >> b[i]; }

	//Calculo y escritura del resultado
	int elemento;
	elemento = resuelve(a, b, 0, n - 1);
	//Llama aqui a tu funcion recursiva
	if (elemento % 2 == 0) {
		cout << elemento << endl;
	}
	else {
		cout << "PESO IMPAR" << endl;
	}
	
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("sample1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	unsigned int numCasos;
	cin >> numCasos;
	// Resolvemos
	while (numCasos--) {
		resuelve();
	}
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}
