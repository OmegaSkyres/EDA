
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "conjunto.h"  // propios o los de las estructuras de datos de clase
using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    char tipo;
    int numElementos, elemento;
    string nombre;
    set<int> listN;
    set<string> listP;
    cin >> tipo;
    if (tipo == 'N') {
        cin >> numElementos;
        cin >> elemento;
        while (elemento != -1) {
            listN.insert(elemento);
            cin >> elemento;
        }
    }
    else if (tipo == 'P') {
        cin >> numElementos;
        cin >> nombre;
        while (nombre != "FIN") {
            listP.insert(nombre);
            cin >> nombre;
        }
    }

    if (!std::cin)  // fin de la entrada
        return false;


    // escribir sol

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
