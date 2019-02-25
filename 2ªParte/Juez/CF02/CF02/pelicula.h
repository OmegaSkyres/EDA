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
	string nombre;

public:
	pelicula(horario inicio, horario duracion, string nombre);
	pelicula(); //Constructo vacio
	~pelicula(); //Destructor
	void print();
	bool operator>();
	bool operator<();
	horario operator+();
	
		

};





#endif