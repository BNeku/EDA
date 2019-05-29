// Nerea jimenez Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;


/*
4 2 1 3 6 5 8 7
i |___| |_____| j
	HI    HD
*/

template <class T>
bintree<T> crearArbolBB(const vector<T> &v, int i, int j){
	if (i == j){
		return {};
	}
	else{
		int raiz = v[i];
		int aux = i + 1;

		while (aux < j && v[aux] < v[i]){
			aux++;
		}

		auto iz = crearArbolBB(v, i + 1, aux);
		auto dr = crearArbolBB(v, aux, j);

		return { iz, raiz, dr };
			
	}
}

bool resuelveCaso() {
	string nodos;
	int n;
	vector<int> numeros_nodos;
	vector<int> postorden;

	getline(cin, nodos);

	if (!std::cin)  // fin de la entrada
		return false;
	//lectura de los nodos para guardar en el vector
	stringstream ss(nodos);
	while (ss >> n){
		numeros_nodos.push_back(n);
	}

	auto arbol = crearArbolBB(numeros_nodos, 0, numeros_nodos.size());

	postorden = arbol.postorder();

	for (int i = 0; i < postorden.size(); i++){
		cout << postorden[i] << " ";
	}
	cout << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_27.txt");
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
