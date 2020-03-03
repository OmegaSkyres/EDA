#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;
/*

Title: Jugando a las canicas

*/

#define MAX 1000

int ballGameG(const vector<int> V, const int N, int& winner, int& balls, const int i, const int j) {
	if (i == j) { //Solo hay un elemento
		balls = V[i];
		return balls;
	}
	if (i + 1 == j) { 
		if (V[i] > V[j]) {
			winner = i;
			balls += (V[i] / 2);
		}
		else {
			winner = j;
			balls += (V[i] / 2);
		}
	}

	else {
		int mitad = (i + j + 1) / 2, izq, der;
		izq = ballGameG(V, N, winner, balls, i, mitad);
		der = ballGameG(V, N, winner, balls, mitad, j);
	}
	return balls;
	
}

int ballGame(const vector<int> V, const int N, int& winner, int& balls) {
	//Start coding here
	winner = balls = 0;
	ballGameG(V, N, winner, balls,0, N-1);
	return balls = balls + V[winner];
}

int main(int argc, char *args[]) {
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	vector<int> V(MAX);
	string W[MAX];
	int N;
	int balls, winner;
	for (; cin >> N;)
	{
		for (int n = 0; n < N; n++) {
			cin >> W[n] >> V[n];
		}
			ballGame(V, N, winner, balls);
			cout << W[winner] << " " << balls << endl;
		
		return 0;
	}

}