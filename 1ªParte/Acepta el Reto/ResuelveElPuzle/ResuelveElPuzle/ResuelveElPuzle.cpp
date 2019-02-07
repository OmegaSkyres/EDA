
// Roberto Torres Prensa

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;




int main() {
	int numero, a;
	cin >> numero;
	while (numero != 0) {
		a = sqrt(numero);
		while (numero % a > 0)
		{
			a = a - 3;
		}
		cout << numero / a << endl;
		cin >> numero;
	}
	return 0;
}