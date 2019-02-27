#ifndef pelicula_h
#define pelicula_h

#include <string>
using namespace std;

#include "horas.h"

class pelicula {
private:
	horas horaInicio;
	horas horaFin;
	horas duracion;
	string nombreP;

public:
	pelicula(horas inicio, horas duracion, string nombre);
	pelicula(); //Constructo vacio
	~pelicula(); //Destructor
	void print();
	string getNombre();
	horas getHoraFin();
	horas getHoraInicio();
	horas getDuracion();
	horas setHoraFin(horas h);
	//bool operator>(pelicula &peli);
	//bool operator<(pelicula &peli);
	
	
		

};





#endif