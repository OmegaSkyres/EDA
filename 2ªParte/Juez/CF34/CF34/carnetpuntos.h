#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
using namespace std; 


class carnet_puntos {
private:
	unordered_map<string, int> conductores;
	vector<int> por_puntos;
public:
	//constructor
	carnet_puntos() : por_puntos(16) {
		//inicializar vector, por defecto suele estar inicializado
	};

	void nuevo(string dni) {
		if (conductores.count(dni) > 0) {
			throw domain_error("Conductor duplicado.");
		}
		else {
			conductores.insert({ dni,15 });
			por_puntos[15]++; // No se porque.
		}
	}

	void quitar(string dni, int puntos) {
		if (conductores.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		por_puntos[conductores[dni]]--;

		conductores[dni] = conductores[dni] - puntos;
		if (conductores[dni] < 0) {
			conductores[dni] = 0;
		}
		por_puntos[conductores[dni]]++;
	}

	int consultar(string dni) {
		if (conductores.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else return conductores[dni];
		
	}

	int cuantosConPuntos(int puntos) {
		int numero;
		if (puntos < 0 || puntos > 15) {
			throw domain_error("Puntos no validos.");
		}
		return por_puntos[puntos];
	}



};
