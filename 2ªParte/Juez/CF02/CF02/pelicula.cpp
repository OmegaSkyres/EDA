
// Roberto Torres Prensa

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "pelicula.h"  // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

pelicula::pelicula(horario inicio, horario duracion, string nombre) {
	horaInicio = inicio;
	horaFin = duracion;
	nombreP = nombre;
}

pelicula::pelicula() {}

string pelicula::getNombre() {
	return nombreP;
}

void pelicula::print() {
	print();
}

void resuelveCaso(int numCasos) {
	horario inicio, fin, duracion;
	vector<pelicula> peliculas(numCasos);
	string nombre;
	// leer los datos de la entrada
	int hora, min, segundo;
	char aux;
	for (int i = 0; i < numCasos; i++) {
		cin >> hora >> aux >> min >> aux >> segundo;

		duracion = horario(hora, min, segundo);
		getline(cin, nombre);
		peliculas[i] = pelicula(inicio, duracion, nombre);

	}

	// escribir solución
}

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

horario operator+(horario other) {
	
}

int main() {
	return 0;
}

