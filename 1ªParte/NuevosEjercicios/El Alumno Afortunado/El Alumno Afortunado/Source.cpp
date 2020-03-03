
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"  // propios o los de las estructuras de datos de clase
#include "queue_afortunado.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta


bool resuelveCaso() {
    int numAlumnos, salto, contador = 1;
    // leer los datos de la entrada
    cin >> numAlumnos >> salto;
    if (!std::cin)  // fin de la entrada
        return false;
    
    Afortunado<int> lista;
    while (contador <= numAlumnos) {
        lista.push(contador);
        contador++;
    }
    lista.resolver(lista, salto);
    lista.print();


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
