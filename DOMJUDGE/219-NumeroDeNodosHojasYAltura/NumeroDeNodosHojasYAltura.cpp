// Altura de un �rbol

// Construye un �rbol binario a partir de la entrada y despu�s
// calcula de forma recursiva su altura
// O(N)

// versi�n con funci�n externa a la clase bintree del TAD dado en clase (Alberto Verdejo)

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


// dado un �rbol binario, calcula su altura
// lineal en el n�mero N de nodos del �rbol, O(N)
int altura(bintree<char> const& arbol) {
	if (arbol.empty())
		return 0;
	else {
		return 1 + max(altura(arbol.left()), altura(arbol.right()));
	}
}

int nHojas(bintree<char> const& arbol) {
	if (arbol.empty())
		return 0;
	else if (arbol.right().empty() && arbol.left().empty()){
		return 1;
	}else {
		return nHojas(arbol.left()) + nHojas(arbol.right());
	}
}

int nNodos(bintree<char> const& arbol) {
	if (arbol.empty())
		return 0;
	else {
		return 1 + nNodos(arbol.right()) + nNodos(arbol.left());
	}
}


void resuelveCaso() {

	bintree<char> arbol = leerArbol('.');
	int h = altura(arbol);
	int hojas = nHojas(arbol);
	int nodos = nNodos(arbol);
	
	cout << nodos << " " << hojas << " " << h << endl;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos2_19.txt");
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
