
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "stack_eda.h"
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    stack<pair<string,int>> pila;
    int numCasos;
    string fecha;
    int numVictimas;
    cin >> numCasos;
    if (!std::cin)  // fin de la entrada
        return false;
    else {
        for (int i = 0; i < numCasos; i++) {
            cin >> fecha >> numVictimas;
            while (pila.size() >= 1) {
                if (pila.top().second > numVictimas) {
                    cout << pila.top().first << endl;
                    break;
                }   
                else {
                    pila.pop();
                }
            }
            if(pila.empty()) {
                cout << "NO HAY" << endl;
            }
            pila.push(make_pair(fecha, numVictimas));

        }
        // leer los datos de la entrada
        cout << "---" << endl;
       
        return true;
    }
     
   
    // escribir solución
 
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    while (resuelveCaso());
   

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
