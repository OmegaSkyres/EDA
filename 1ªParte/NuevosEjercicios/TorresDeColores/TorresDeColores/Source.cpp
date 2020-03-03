//Roberto Torres Prensa


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000
const char* spanish[3] = { "azul ","rojo ", "verde " };


bool esValida(vector<int> sol, int k, int altura, const int lr, const int lv, const int la, int r, int v, int a) {
		if (r > lr || v > lv || a > la) return false; // Esta dentro de los limites.
		if (k > 0 && sol[k] == sol[k - 1] == 2) return false; //Nunca hay 2 verdes seguidos
		if (v > a) return false;
		if (k == 0 && sol[k] != 1) return false;
		if ((k == altura - 1) && (r <= (v + a))) return false;
		return true;
}

void outputsol(vector<int> sol, int altura) {
	for (int n = 0; n < altura; n++) cout << spanish[sol[n]];
	cout << endl;
}

void resolver(vector<int> sol, int marcaje, int k, const int altura, const int lr, const int lv, const int la, int r, int v, int a) {
	if (k == altura) {
		marcaje = 1;
		outputsol(sol,altura);
		return;
	}
	for (int i = 0; i < 3; i++) {
		sol[k] = i;
		if (esValida(sol, k, altura, lr, lv, la, r+(sol[k] == 1), v+(sol[k] == 2), a+(sol[k] == 0))) {
			a += (sol[k] == 0);
			r += (sol[k] == 1);
			v += (sol[k] == 2);
			resolver(sol, marcaje, k + 1, altura, lr, lv, la, r, v, a);
			a -= (sol[k] == 0);
			r -= (sol[k] == 1);
			v -= (sol[k] == 2);
		}
	}

}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int altura, marcaje = 0, lr, lv, la, k;
	cin >> altura >> lr >> lv >> la;
	vector<int> sol(altura);
	while (altura != 0 && lr != 0 && lv != 0 && la != 0) {
		resolver(sol, marcaje, 0, altura, lr, lv, la,0,0,0);
		if(marcaje == 0) cout << "SIN SOLUCION" << endl << endl;
		cin >> altura >> lr >> lv >> la;
	}
	return 0;
}

