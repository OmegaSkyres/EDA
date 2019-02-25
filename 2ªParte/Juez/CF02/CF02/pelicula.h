#ifndef pelicula_h
#define pelicula_h

#include <string>
using namespace std;

#include "horario.h"

class pelicula {
private:
	horario horaInicio;
	horario horaFin;
	horario duracion;
	string nombreP;

public:
	pelicula(horario inicio, horario duracion, string nombre);
	pelicula(); //Constructo vacio
	~pelicula(); //Destructor
	void print();
	string getNombre();
	bool operator>(pelicula &peli);
	bool operator<(pelicula &peli);
	horario operator+();
	
		

};





#endif