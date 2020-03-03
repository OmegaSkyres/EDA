#ifndef complejo_h
#define complejo_h

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class complejo {

private:
	T parteReal, parteImaginaria;

public:
	complejo(T r, T i);
	~complejo();
	complejo operator+(const complejo& other);
	complejo operator*(const complejo& other);
	T mod();

};


    template <class T>
	complejo<T>::complejo(T r, T i)
	{
		parteReal = r;
		parteImaginaria = i;

	}

	template <class T>
	complejo<T>::~complejo() {};


	template <class T>
	complejo<T> complejo<T>::operator+(const complejo &c) {

		parteReal += c.parteReal;
		parteImaginaria += c.parteImaginaria;
		return complejo(parteReal, parteImaginaria);
	}

	template <class T>
	complejo<T> complejo<T>::operator*(const complejo& c) {
		T newparteReal, newparteImaginaria;
		newparteReal = parteReal * c.parteReal;
		newparteImaginaria = parteImaginaria * c.parteImaginaria;
		return complejo(newparteReal, newparteImaginaria);

	}

	template <class T>
	T complejo<T>::mod() {
		T sol = sqrt((parteReal * parteReal) + (parteImaginaria * parteImaginaria));
		return sol;
	}


#endif
