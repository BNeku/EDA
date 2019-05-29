
#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

void jerarquia(const bintree<int> &arbol, int &j, int &min){

	if (arbol.empty()){
		j = 0;
	}else if (!arbol.left().empty() && !arbol.right().empty()){
		if (arbol.root() > arbol.left().root() && arbol.root() > arbol.right().root() && arbol.left().root() >= arbol.right().root()){

			if (arbol.root() < min)
				min = arbol.root();
			

			jerarquia(arbol.left(), j, min);
			if (j != -1){
				jerarquia(arbol.right(), j, min);
			}

			j = arbol.root() - min;
		}
		else{
			j = -1;
		}

	}else if (arbol.left().empty() && arbol.right().empty()){
		if(arbol.root() < min)
			min = arbol.root();
		j = arbol.root() - min;
	}
	else if (!arbol.left().empty()){

		if (arbol.root() > arbol.left().root()){
			if (arbol.root() < min)
				min = arbol.root();

			jerarquia(arbol.left(), j, min);
			j = arbol.root() - min;
		}

	}else{
		j = -1;
	}
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int j = -1, min=arbol.root();

	jerarquia(arbol, j, min);

	if (j == -1){
		cout << "NO" << endl;
	}
	else{
		cout << "SI " << j << endl;
	}
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2C.txt");
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