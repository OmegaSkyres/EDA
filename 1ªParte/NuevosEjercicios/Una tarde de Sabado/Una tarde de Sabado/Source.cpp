
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "horas.h"  // propios o los de las estructuras de datos de clase
#include "pelicula.h"

typedef horas Solucion;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
Solucion resolver(vector<horas> datos, vector<horas> duracion, vector<string> nombres) {
    for (int i = 0; i < datos.size(); i++) {
       Solucion sol = datos[i] + duracion[i];
       return sol;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int numCasos;
    cin >> numCasos;
    if (numCasos == 0)
        return false;
    string t = "";
    vector<pelicula> datos(numCasos);
    for (int i = 0; i < numCasos; i++) {
        horas c, d;
        string t = "";

        cin >> c >> d;

        getline(cin, t);

        datos[i] = pelicula(c, d, t);


    }
    sort(datos.begin(), datos.end());
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i].horaFin() << " " << datos[i].titulo() << endl;
    }
    cout << "---" << endl;

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
