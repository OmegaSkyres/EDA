
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>

#include "complejo.h"  // propios o los de las estructuras de datos de clase
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool resolver(complejo<float>& num, int n) {
    bool valido = true;
    int i = 0;
    complejo<float> nuevo = complejo<float>(0, 0);
    while (nuevo.mod() <= 2 && i < n) {
        nuevo = (nuevo * nuevo) + num;
        i++;
    }
    return i == n;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    float a, b;
    int numIteraciones;
    cin >> a >> b >> numIteraciones;
    complejo<float> numero = complejo<float>(a, b);
    
    if (resolver(numero,numIteraciones)) cout << "SI" << endl;
    else cout << "NO" << endl;
    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
