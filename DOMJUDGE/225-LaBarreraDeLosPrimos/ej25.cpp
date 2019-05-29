#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

//devuelve true si el número N es primo
bool esPrimo(int N){
	int i = 1;
	int divisores = 0;

	while (i <= N){
		if (N%i == 0)
			divisores++;
		i++;
	}

	if (divisores == 2){
		return true;
	}
	else{
		return false;
	}
}

int encuentraNodo(const bintree<int> &arbol, int profundidad, int &profMin, int &nodo){

	if (arbol.empty() || esPrimo(arbol.root())){//si la raiz es primo, el nodo no es accesible
		return -1;
	}//si la raiz no es prima 
	else if (arbol.root() % 7 == 0){//miramos si la raiz es multiplo de 7 y que no este mas lejos del que se tiene
		
		if (profMin == 0){
			profMin = profundidad;
			nodo = arbol.root();
		}
		else if (profundidad < profMin){
			profMin = profundidad;
			nodo = arbol.root();
		}
		return 1;
	}
	else {
		int nodoIzq=0, nodoDch=0;

			nodoIzq = encuentraNodo(arbol.left(), profundidad+1, profMin, nodo);

			nodoDch = encuentraNodo(arbol.right(), profundidad + 1, profMin, nodo);

		if (nodo != -1)
			return 1;
		return -1;
	}
	
	
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int n = -1, p = 0, b;

	
	if (arbol.empty() || esPrimo(arbol.root()) || encuentraNodo(arbol, 0,p, n)== -1){
		cout << "NO HAY" << endl;
	}
	else{	
		cout << n << " " << p+1 << endl;;
	}
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_25.txt");
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
