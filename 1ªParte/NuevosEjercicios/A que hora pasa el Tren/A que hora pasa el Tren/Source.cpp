
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

#include "horas.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
  
    // leer los datos de la entrada
    int numTrenes, numHoras;
    cin >> numTrenes >> numHoras;
    if (numTrenes == 0 && numHoras == 0) {
        return false;
    }

    vector<horas> datos(numTrenes);
    for (int i = 0; i < numTrenes; i++) {
        cin >> datos[i];
    }
    horas h;
    for (int i = 0; i < numHoras; i++) {
        try {
            cin >> h;
            //auto p = lower_bound(datos.begin(), datos.end(), h);
            for (int i = 0; i < numTrenes; i++) {
                if (datos[i] < h) {
                    if (i == numTrenes - 1) {
                        cout << "NO" << endl;
                    }
                    //No hacemos nada 
                }
                else {
                    cout << datos[i] << endl;
                    break;
                }
            }
            /*
            if (p == datos.end()) {
                cout << "NO\n";
            }
            else {
                //*p = objeto que está apuntando ese iterador
                cout << *p << "\n";
            }
            */
        }
        catch (invalid_argument const& e) {
            cout << e.what() << "\n";
        }

    }

    cout << "---" << endl;;
    
    return true;
    // escribir solución
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
