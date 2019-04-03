#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;

template<class T>
void minElem(bintree<T> arbol, T &min) {

	if (!arbol.empty()) {
		
		if (arbol.root() < min) {
			min = arbol.root();
		}
		minElem(arbol.right(), min);
		minElem(arbol.left(), min);
	}
}

bool resuelveCaso() {
	string letra;
	cin >> letra;

	if (!cin)
		return false;
	
	if (letra == "P") {
		string vacio = "#";
		bintree<string> arbol=leerArbol(vacio);
		string min = arbol.root();
		minElem(arbol, min);
		cout << min <<endl;
	}
	else if (letra == "N") {
		bintree<int> arbol = leerArbol(-1);
		int min = arbol.root();
		minElem(arbol,min);
		cout << min <<endl;
	}

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos2_21.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}