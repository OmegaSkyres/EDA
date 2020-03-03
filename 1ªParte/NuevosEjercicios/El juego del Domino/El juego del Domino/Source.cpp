#include <iostream>
#include <time.h>
#include <fstream>
#include <climits>
#include <vector>
using namespace std;


void inicializaCompras(std::vector<std::vector<int>>& precio, std::vector<int>& costesMinimosProd, const int& super, const int& prod)
{
	int k;
	for (int i = 0; i < super; i++)
	{
		for (int j = 0; j < prod; j++)
		{
			std::cin >> k;
			if (costesMinimosProd[j] > k) { costesMinimosProd[j] = k; }
			precio[i][j] = k;
		}
	}
}


bool esValido(const std::vector<int>& contador, const std::vector<bool> marcaProd, const  int& i, const int& k)
{
	return  !marcaProd[k] && contador[i] < 3;
}


void comprasSemana(const std::vector<std::vector<int>>& precio, std::vector<bool>& marcaProd, std::vector<int>& contador,
	int k, const int& super, const int& prod, int& suma, int& minimo, int& cont, const std::vector<int>& costesMinimosProd)
{
	cont++;
	for (int i = 0; i < super; i++)
	{
		if (esValido(contador, marcaProd, i, k))
		{
			suma += precio[i][k];
			contador[i]++;
			marcaProd[k] = true;
			if (k == prod - 1)
			{
				if (suma < minimo)
				{
					minimo = suma;
				}
			}
			else {
				if (costesMinimosProd[k + 1] + suma < minimo)//poda
				{
					comprasSemana(precio, marcaProd, contador, k + 1, super, prod, suma, minimo, cont, costesMinimosProd);
				}
			}
			suma -= precio[i][k];
			contador[i]--;
			marcaProd[k] = false;


		}
	}
}


void resuelveCaso()
{
	int numFichas;

	cin >> numFichas;
	std::vector<int> contador(numFichas);
	std::vector<std::vector<int>> precio(super, std::vector<int>(prod));
	std::vector<bool> marcaProd(prod, false);
	std::vector<int>costesMinimosProd(prod, INT_MAX);
	inicializaCompras(precio, costesMinimosProd, super, prod);



	t_ini = clock();
	comprasSemana(precio, marcaProd, contador, 0, super, prod, suma, minimo, cont, costesMinimosProd);
	t_fin = clock();
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	cout << " tiempo " << secs * 1000000.0 << endl;
	cout << minimo << "  " << cont << endl;
}
int main()
{
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	unsigned int n;
	std::cin >> n;
	// Resolvemos
	for (int i = 0; i < n; ++i) {
		resuelveCaso();
	}

	system("PAUSE");
	return 0;

}
