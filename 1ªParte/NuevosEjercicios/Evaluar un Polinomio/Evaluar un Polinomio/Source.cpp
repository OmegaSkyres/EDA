
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "polinomio.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    polinomio p;
    int coeficiente, exponente, nValores, valor;
    // leer los datos de la entrada
    cin >> coeficiente >> exponente;
    if (!std::cin)
        return false;

    while (coeficiente != 0 || exponente != 0)
    {
        p.add(coeficiente, exponente);
        cin >> coeficiente >> exponente;
        
    }
    p.ordena();
    cin >> nValores;
    for (int i = 0; i < nValores; i++) {
        cin >> valor;
        cout << p.evalua(valor) << " ";
    }
    cout << endl;



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
