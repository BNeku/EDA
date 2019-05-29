#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

int subarbol(const bintree<char> &arbol, int &desdeRaiz){

	if (arbol.empty()){
		desdeRaiz = 0;
		return 0;
	}
	else{
		int iz, dr, subHI, subHD;

		subHI = subarbol(arbol.left(), iz);

		subHD = subarbol(arbol.right(), dr);

		desdeRaiz = 1 + min(iz, dr);

		return max(desdeRaiz, max(subHI, subHD));
	}
}


void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	int altura;

	cout << subarbol(arbol, altura) << endl;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2F.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
