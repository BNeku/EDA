//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include "hashmap_eda.h"
using namespace std;



void resuelveCaso() {
	unordered_map<int, int> emisiones;
	int cont = 0, N, cap, aux;
	int longMax = 0, pos = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cap;
		
		if (emisiones.count(cap) > 0 && pos <= emisiones[cap]){
			pos = emisiones[cap] + 1;
		}

		emisiones[cap] = i;
		cont = (i - pos) + 1;

		if (longMax < cont){
			longMax = cont;
		}
	}


	if (cont > longMax) {
		longMax = cont;
	}

	cout << longMax << endl;
}

int main() {
		// Para la entrada por fichero.
#ifndef DOMJUDGE
		std::ifstream in("casos2_29.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


		unsigned int numCasos;
		std::cin >> numCasos;
		// Resolvemos
		for (int i = 0; i < numCasos; ++i) {
			resuelveCaso();
		}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
#endif

		return 0;
}