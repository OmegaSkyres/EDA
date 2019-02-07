#include <iostream>
using namespace std;

//Precondicion:
// 0 <= n
int alreves(int n, int digitos)
{
	int resto, cocie;

	if (n < 10)     // Si tenemos un número de dígitos menor a 2, devolvemos n
		return n;
	else
	{
		resto = n % 10;
		cocie = n / 10;
		return resto * digitos + alreves(cocie, digitos / 10);
	}

//Postcondicion:
// sol%2 != 0

//Analisis del coste: plantea la recurrencia e indica la solucion de la misma

/*
	T(n) = {
			Co si n < 10
			T(n-1) + Co si n >= 10
		   }
	con n = numero de digitos
	Por lo tanto T(n) pertenece a O(n)
*/
}

void resuelveCaso() {
	int numero, rev;
	int digitos = 1;
	int tmp;
	cout << "Introduce un numero: ";
	cin >> numero;
	// Hacemos un número 10^(numero de cifras-1) asi sabremos en numero de cifras


	tmp = numero;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		digitos = digitos * 10;
	}

	rev = alreves(numero, digitos);

	if (rev == numero)
		cout << "CAPICUA" << endl;
	else
		cout << "NO CAPICUA" << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	
	system("PAUSE");
	return 0;
}

