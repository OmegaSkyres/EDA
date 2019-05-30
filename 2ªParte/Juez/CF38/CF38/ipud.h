#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

using cancion = string;

class iPud {
private:
	//se puede poner dentro o fuera de la clase
	struct infoCancion {
		string artista;
		int duracion;
		list<cancion> ::iterator it_Playlist;
		list<cancion> ::iterator it_Recientes;
	};

	unordered_map<string, infoCancion> ipud;
	list<cancion> recientes;
	list<cancion> playlist;
	int tiempoTotal;

public:

	iPud() {
		tiempoTotal = 0;
	}

	void addSong(cancion c, string artista, int d) {
		if (ipud.count(c) > 0) {
			throw domain_error("ERROR addSong");
		}
		ipud.insert({ c,{artista, d, playlist.end(), recientes.end()} });
	}

	void addToPlaylist(cancion c) {
		if (ipud.count(c) == 0) {
			throw domain_error("ERROR addToPlaylist");
		}
		if (ipud[c].it_Playlist == playlist.end()) { //Comprabamos si ya existe en la lista 
			ipud[c].it_Playlist = playlist.insert(playlist.end(), c);
			tiempoTotal += ipud[c].duracion;
		}

	}

	cancion current() {
		if (playlist.empty()) {
			throw domain_error("ERROR current");
		}
		else {
			return playlist.front();
		}
	}


	cancion play() {
		if (playlist.empty()) {
			throw domain_error("No hay canciones en Playlist");
		}
		else {
			cancion actual = playlist.front();
			playlist.pop_front();
			if (ipud[actual].it_Recientes != recientes.end()) {
				recientes.erase(ipud[actual].it_Recientes);
			}
			ipud[actual].it_Recientes = recientes.insert(recientes.begin(), actual);
			tiempoTotal -= ipud[actual].duracion;
			ipud[actual].it_Playlist = playlist.end();
			return actual;
		}
	}

	int totalTime() {
		if (!playlist.empty()) {
			return tiempoTotal;
		}
		else {
			return 0;
		}
	}

	list<cancion> recent(int& N) {
		list<cancion> lista;
		if (N > 0 && recientes.size() > 0) {
			if (N > recientes.size()) {
				N = recientes.size();
				return recientes;
			}
			else {
				int cont = 0;
				for (auto const& i : recientes) {
					if (cont < N) {
						lista.push_back(i);
						cont++;
					}
				}
				return lista;
			}
		}
		else {
			return lista;
		}

	}

	void deleteSong(cancion s) {
		if (ipud.count(s) > 0) {
			if (!playlist.empty() && ipud[s].it_Playlist != playlist.end()) {
				playlist.erase(ipud[s].it_Playlist);
				tiempoTotal -= ipud[s].duracion;
				ipud[s].it_Playlist = playlist.end();
			}
			if (!recientes.empty() && ipud[s].it_Recientes != recientes.end()) {
				recientes.erase(ipud[s].it_Recientes);
				ipud[s].it_Recientes = recientes.end();
			}
		}
		ipud.erase(s);
	}
};

