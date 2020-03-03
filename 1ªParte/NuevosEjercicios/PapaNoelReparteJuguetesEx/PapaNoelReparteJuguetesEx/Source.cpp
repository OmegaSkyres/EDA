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

bool esValida(int sol[], int m, int k, int marcas[]) {
	if ((marcas[m] + 1) > C[m]) return 0;
	if (k % 2 && (T[sol[k - 1]] == T[m])) return false;
	if ((k % 2) && ((P[k / 2][m] + P[k / 2][sol[k - 1]]) < S)) return 0;
	if ((k % 2) && (sol[k - 1] >= m)) return 0;

	return true;
}

void resolver(int sol[], int k, int marcas[], int& bestScore) {
	for (int i = 0; i < M; i++) {
		sol[k] = i;
		if (esValida(sol,i, k, marcas)) {
			if (k == 2 * N) {
				outputSol(sol, k);
				bestScore = 1;
			}
			else {	
				marcas[i] += 1;
				resolver(sol, k + 1, marcas, bestScore);
				marcas[i] -= 1;
			}
			
		}
	}
}

int main() {
	
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

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