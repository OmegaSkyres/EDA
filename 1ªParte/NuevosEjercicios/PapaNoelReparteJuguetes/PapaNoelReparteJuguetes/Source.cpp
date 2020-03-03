//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10000;
static int C[MAX];
static char T[MAX];
static int P[MAX][MAX];

static int M, N, S;

void outputSol(const int sol[], const int N)
{
	for (int n = 0; n < N; n++) cout << sol[n] << " ";
	cout << endl;
}


int isValid(const int sol[], const int k, const int m, const int marcas[]) {
	if ((marcas[m] + 1) > C[m]) return 0;
	if (k % 2 && (T[sol[k - 1]] == T[m])) return 0;
	if ((k % 2) && ((P[k / 2][m] + P[k / 2][sol[k - 1]]) < S)) return 0;
	if ((k % 2) && (sol[k - 1] >= m)) return 0;
	return 1;
}

void resolver(int sol[], int k, int marcas[], int &bestScore) {

	if (k == 2 * N) { //Si el numero de juguetes a repartir es 2 * por el valor de entrada N;
		outputSol(sol, k);
		bestScore = 1;
		return;
	}
	for (int m = 0; m < M; m++) {
		if (isValid(sol, k, m, marcas)) {
			sol[k] = m;
			marcas[m] += 1;
			resolver(sol, k + 1, marcas, bestScore);
			marcas[m] -= 1;
		}
	}
	return;
}


int main() {	
	int sol[MAX];
	int bestScore;
	int marcas[MAX];
	for (; cin >> M >> N >> S;)
	{
		string word;
		for (int m = 0; m < M; m++) cin >> C[m];
		for (int m = 0; m < M; m++) { 
			cin >> word; 
			T[m] = word[word.length() - 1];
		}
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++) cin >> P[n][m];
		for (int m = 0; m < M; m++) marcas[m] = 0;
		bestScore = 0;
		resolver(sol, 0, marcas, bestScore);
		cout << endl;
		if (!bestScore) cout << "SIN SOLUCION" << endl << endl;
	}
	return 0;
}