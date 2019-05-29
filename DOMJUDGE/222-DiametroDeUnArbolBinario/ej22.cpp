#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

int diametro(const bintree<char> & arbol,int &maximo) {

	if (arbol.empty()){
		maximo = 0;
		return 0;
	}
	else{

		int alturaIzq = 0, alturaDcha = 0, diamIzq = 0, diamDcha = 0;

		diamIzq= diametro(arbol.left(), alturaIzq);
		diamDcha = diametro(arbol.right(), alturaDcha);
	
		maximo = max(alturaIzq, alturaDcha) + 1;

		int diam = max(diamIzq, diamDcha);

		return max(alturaDcha + alturaIzq + 1, diam);
	}

}




void resuelveCaso() {
	bintree<char> arbol = leerArbol('.');
	int d = 0, m=0;

	d=diametro(arbol, m);

	cout << d << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos2_22.txt");
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