//Adrian de Andres
//Roberto Torres
//F23

// comentario sobre la solución y su coste

#include <iostream>
#include <fstream>
#include "hashmap_eda.h"
#include <vector>
#include <algorithm>

using namespace std;

int buscaNumero(unordered_map<int, vector<int>> mapa, int num, int pos) {
	auto numero = mapa.find(num);

	if (numero == mapa.end())
		return -1;
	else {
		if (numero->valor.size() < pos)
			return -1;
		else {
			return numero->valor[pos - 1];
		}
	}
}

bool resuelveCaso() {
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;
   
   unordered_map<int, vector<int>> mapa;

   int num;
   for (int i = 0; i < N; i++) {
	   cin >> num;
	   mapa.insert(num);
	   mapa.find(num)->valor.push_back(i);
   }

   for (int i = 0; i < M; i++) {
	   int k, v;
	   cin >> k >> v;
	   int sol = buscaNumero(mapa, v, k);

	   if (sol == -1)
		   cout << "NO HAY" << endl;
	   else
		   cout << sol + 1 << endl;
   }
   
   cout << "---\n";
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
