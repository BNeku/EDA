//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

void busqueda(bintree<int> arbol, int &perdidos, int &grupos){
	int grupoR=0, grupoL=0, perdidoR=0, perdidoL=0;

	if (arbol.left().empty() && arbol.right().empty()){
		//si ambas ramas estan vacía solo hay un nodo
		//si este nodo es 0, no hay excursionistas perdidos
		//por lo que no se envia ningún grupo
		//en caso de que la raiz sea otro número, 
		//habría que enviar un grupo
		if (arbol.root()>0){
			grupos += 1;
		}
		
		//en cualquier caso, el número de gente perdida 
		//es el número del nodo
		perdidos = arbol.root();
	}//si esta la rama dcha vacia, solo miramos la izda
	else if (arbol.right().empty()){
		
		busqueda(arbol.left(), perdidos, grupos);

		//si el número de grupos es 0, miramos el nodo raíz
		if (grupos == 0){
			//miramos si el numero de la raiz es diferente de 0
			//si es asi, se envia un grupo
			if (arbol.root() >0){
				grupos += 1;
			}
			else{
				grupos += 0;
			}
		}
		//en cualquier caso, el numero de perdidos es
		//lo devuelto en perdidos mas el numero de la raiz
		perdidos += arbol.root();

	}//miramos lo mismo pero en caso de que sea la rama izqda la vacia
	else if (arbol.left().empty()){
		busqueda(arbol.right(), perdidos, grupos);
		if (grupos == 0){
			if (arbol.root() > 0){
				grupos += 1;
			}
			else{
				grupos += 0;
			}
		}
		perdidos += arbol.root();
	}//en el caso de que ambas ramas tengan hijos
	else{
		busqueda(arbol.left(), perdidoL,grupoL);
		busqueda(arbol.right(), perdidoR, grupoR);

		if (perdidoL == 0 && perdidoR == 0){
			if (arbol.root() > 0){
				grupos += 1;
			}
		}
		grupos += grupoL + grupoR;

		perdidos = max(perdidoL ,perdidoR) + arbol.root();
	}
}


void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int p = 0, g = 0;

	busqueda(arbol, p, g);

	cout << g << " " << p << endl;


}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos2_23.txt");
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