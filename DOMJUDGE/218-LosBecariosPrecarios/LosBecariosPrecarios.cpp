//Nerea Jimenez Gonzalez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

int resolver(int jefes, int nRama, int nivel) {
	int becariosP = 0;

	for(int i = 0; i < nRama; i++){
		int rama; 
		cin >> rama;

		if (rama != 0) {
			becariosP += resolver(jefes, rama, nivel + 1);
		}
		else if (nivel >= jefes) {
			becariosP++;
		}
	}

	return becariosP;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int jefes, raiz;

	cin >> jefes >> raiz;

	if (!std::cin)  // fin de la entrada
		return false;

	if (raiz == 0) {
		cout << "0" << endl;
	}
	else {
		cout << resolver(jefes, raiz, 1) <<endl;
	}

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
