
#ifndef PELICULA_H
#define PELICULA_H

#include <stdexcept>
#include <iostream>
//#include <fstream>

#include "horas.h"

using namespace std;

class pelicula {
private:
	horas _horaComienzo, _duracion, _horaFin; string _titulo;

public:
	//a la hora de crear un objeto hay que comprobar si se puede crear, es decir
	//si los datos que se dan son correctos o validos
	pelicula(horas horaC = 0, horas dur = 0, string title = "") :_horaComienzo(horaC), _duracion(dur), _titulo(title)
	{
		_horaFin = horaC + dur;

	}

	horas horaComienzo() {
		return _horaComienzo;
	}

	horas horaFin() {
		return _horaFin;
	}

	horas duracion() {
		return _duracion;
	}

	string titulo() {
		return _titulo;
	}
	void print(ostream& out = cout)const {
		cout << _horaFin << " " << _titulo;
	}

	bool operator <(const pelicula& p) const {
		if (p._horaFin < _horaFin) {
			return false;
		}
		else {
			if (p._horaFin == _horaFin) {
				//para ordenar alfabeticamente en caso de "empate"
				if (p._titulo < _titulo) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				return true;
			}
		}
	}


};


#endif

