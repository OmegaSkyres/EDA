//Roberto Torres Prensa

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<int> sol, int n, int p, const int k, vector<int> marcas, vector<int> coste, vector<int> superficie, int cost, int super, int m) {
	if ((k >= 1) && (coste[k] + coste[m] > p)) return false;
	return true;
}


void adornosNav(vector<int> sol, int n, int p, const int k, vector<int> marcas, vector<int> coste, vector<int> superficie, int cost, int super, int &maxS){
	if (k == n) {
		if (superficie[k] + super > maxS) {
			maxS = superficie[k] + super;
			return;
		}
	}
	for (int m = 0; m < n; m++) {
		if (isValid(sol, n, p, k, marcas, coste, superficie, cost, super, m)) {
			sol[k] = m;
			marcas[m] = 1;
			adornosNav(sol, n, p, k + 1, marcas, coste, superficie, cost, super, maxS);
			marcas[m] = 0;
		}
	}
		
}



int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int n, p, cost, super, maxS = 0;
	for (; cin >> n >> p;)
	{
		vector<int> coste(n);
		vector<int> superficie(n);
		vector<int> sol(1000);
		vector<int> marcas(1000);
		for (int i = 0; i < n; i++) {
			cin >> cost >> super;
			coste[i] = cost;
			superficie[i] = super;
		}
		cost = super = 0;
		adornosNav(sol, n, p, 0, marcas, coste, superficie, cost, super, maxS);
		cout << maxS << endl;
	}
	return 0;
	
}