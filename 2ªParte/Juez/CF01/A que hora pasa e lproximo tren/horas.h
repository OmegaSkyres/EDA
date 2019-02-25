#ifndef horas_h
#define horas_h

#include <string>
using namespace std;


class horas {
private:
	int hora;
public:
	horas();
	~horas();
	

	bool operator<(horas const& that) const {
		return horas() < that.hora();
	}
	bool operator>(horas const& that) const {
		return that < *this;
	}
	

};

#endif