
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;

#include "queue_eda.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
template<class T>
class Reordenando : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    void reordenando() {

    }

    void print() {

    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numElementos, elemento;
    if (numElementos == 0)
        return false;
    Reordenando<int> cola;
    for (int i = 0; i < numElementos; i++) {
        cin >> elemento;
        cola.push(elemento);
    }
    cola.reordenando();
    cola.print();



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
