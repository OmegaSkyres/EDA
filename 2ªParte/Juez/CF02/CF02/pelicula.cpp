
// Roberto Torres Prensa

// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "pelicula.h"  // propios o los de las estructuras de datos de clase

// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta

pelicula::pelicula(horas inicio, horas duracion, string nombre) {
	horaInicio = inicio;
	horaFin = duracion;
	nombreP = nombre;
}

pelicula::pelicula() {}

string pelicula::getNombre() {
	return nombreP;
}

void pelicula::print() {
	cout << nombreP << "\n";
}


string pelicula::getNombre() {
	return this->nombreP;
}

horas pelicula::getHoraFin() {
	return this->horaFin;

}

horas pelicula::getHoraInicio() {
	return this->horaInicio;
}

horas pelicula::getDuracion() {
	return this->getDuracion;
}

horas pelicula::setHoraFin(horas h) {
	this->horaFin = h;
}
void opera(vector<pelicula> &peliculas) {
	horas h;
	for (int i = 0; i < peliculas.size(); i++) {
		h = peliculas[i].getHoraInicio + peliculas[i].getDuracion;
		peliculas[i].setHoraFin(h);
	}
}


void imprime(vector<pelicula> &peliculas) {
	sort(peliculas);//ordenar
	for (int i = 0; i < peliculas.size(); i++) {
		cout << peliculas[i].getNombre << peliculas[i].getHoraFin;
	}
}

void resuelveCaso(int numCasos) {
	horas inicio, fin, duracion;
	vector<pelicula> peliculas(numCasos);
	string nombre;
	// leer los datos de la entrada
	int hora, min, segundo;
	char aux;
	for (int i = 0; i < numCasos; i++) {
		cin >> hora >> aux >> min >> aux >> segundo;

		duracion = horas(hora, min, segundo);
		getline(cin, nombre);
		peliculas[i] = pelicula(inicio, duracion, nombre);
		opera(peliculas);
		imprime(peliculas); //Imprime y ordena
	}

	// escribir soluci�n
}
/*
bool pelicula::operator>(pelicula &other) {
	if (other.horaFin > horaFin) {
		return false;
	}
	else {
		return true;
	}
}

bool pelicula::operator<(pelicula &other) {
	if (other.horaFin < horaFin){
		return false;
	}
	else {
		return true;
	}
}
*/

/*
int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
*/

