#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include "fecha.h"
using namespace std;
using medico = string;
using paciente = string;

class consultorio {
private: 
	unordered_map<medico, map<fecha, paciente>> listaMedicos;
	int dia;


public:
	void nuevoMedico(medico m) {
		if (listaMedicos.count(m) > 0) {
			//No lo modificamos
		}
		else {
			listaMedicos.insert({ m,{ } });
		}
	}
	void pideConsulta(paciente p, medico m, fecha f) {
		if (listaMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		if (listaMedicos[m].count(f) > 0) {
			throw domain_error("Fecha ocupada");
		}
		listaMedicos[m].insert({ f, p });

	}
	paciente siguientePaciente(medico m) {
		if (listaMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		auto it = listaMedicos[m].begin();
		if (it == listaMedicos[m].end()) {
			throw domain_error("No hay pacientes");
		}
		return it->second;
	}
	void atiendeConsulta(medico m) {
		if (listaMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}
		auto it = listaMedicos[m].begin();
		if (it == listaMedicos[m].end()) {
			throw domain_error("No hay pacientes");
		}
		listaMedicos[m].erase(it);
	}
	vector<pair<paciente,fecha>> listaPacientes(medico m, int dia) {
		if (listaMedicos.count(m) == 0) {
			throw domain_error("Medico no existente");
		}

		map<fecha, paciente> citas = listaMedicos[m];
		vector<pair<paciente, fecha>> lista_pacientes;
		for (auto const& i : citas) {
			if (i.first.getDia() == dia)
				lista_pacientes.push_back({ i.second, i.first });
		}

		return lista_pacientes;
	}



};