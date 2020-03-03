
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

 // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
template <class T>
class Lista : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

private:
    int nElementos;

public:
 
    void insertaEnListaEnlazada(Lista &lista2, int posicion) {
        if (lista2.empty()) {
            return;
        }
        else if (this->nElementos == 0 && lista2.nElementos != 0) {
            this->prim = lista2.prim;
            this->ult = lista2.ult;
        }
        else {
            nElementos = this->nelems + lista2.size();
            if (posicion == 0) {
                lista2.ult->sig = this->prim;
                this->prim = lista2.prim;

            }
            else {
                Nodo* nodo = this->prim;
                Nodo* nodol = lista2.prim;

                for (int i = 0; i < posicion - 1; i++) {
                    Nodo* sig = nodo->sig;
                    nodo = sig;
                }
                lista2.ult->sig = nodo->sig;
                nodo->sig = nodol;
            }
            
        }
        lista2.prim = nullptr;
        lista2.ult = nullptr;
        lista2.nelems = 0;

    }

    void print() {
        Nodo* nodo = this->prim;
        for (int i = 0; i < nElementos; i++) {
            cout << nodo->elem << " ";
            nodo = nodo->sig;
        }
        cout << endl;
    }



};


bool resuelveCaso() {
    int nElementosLP, elemento, nElementosLS, posicion;

    // leer los datos de la entrada
    cin >> nElementosLP;
    if (!std::cin)  // fin de la entrada
        return false;
    Lista<int> lista1, lista2;
    for (int i = 0; i < nElementosLP; i++) {
        cin >> elemento;
        lista1.push(elemento);
    }
    cin >> nElementosLS >> posicion;
    for (int i = 0; i < nElementosLS; i++) {
        cin >> elemento;
        lista2.push(elemento);
    }
    lista1.insertaEnListaEnlazada(lista2, posicion);
    lista1.print();

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
