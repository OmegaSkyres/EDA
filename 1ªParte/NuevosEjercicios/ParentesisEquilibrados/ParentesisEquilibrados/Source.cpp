
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "stack.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(string cadena) {
    bool ok = true;
    stack<char> pila;
    char caracter;
    for (char c : cadena) {
        if (c == '(' || c == '[' || c == '{') {
            pila.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (pila.size() == 0) ok = false;
            else {
                caracter = pila.top();
                if (c == ')' && caracter == '(') {
                    pila.pop();
                }
                else if (c == ']' && caracter == '[') {
                    pila.pop();
                }
                else if (c == '}' && caracter == '{') {
                    pila.pop();
                }
                else ok = false;
            }

        }
       
    }
    if (pila.size() > 0) ok = false;
    return ok;

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
    string cadena;
    getline(cin, cadena);
   

    if (!std::cin)  // fin de la entrada
        return false;

    if (resolver(cadena)) {
        cout << "SI" << endl;
    }
    else cout << "NO" << endl;

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
