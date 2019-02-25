
#ifndef horario_h
#define horario_h

#include <string>
using namespace std;

class horario {
private: int hora;
private: int minuto;
private: int segundo;

public:
	horario(int hora, int min, int segundo);
	horario();
	~horario()

};


#endif