
// NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
#include "queue_eda.h"
using namespace std;

template <class T>
class insertaLista : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	void print(ostream & o = cout) const {

		if (this->nelems >= 1) {
			Nodo * nodeAux = this->prim;
			o << nodeAux->elem;
			nodeAux = this->prim->sig;

			for (int i = 0; i < this->nelems - 1; i++) {
				o << ' ' << nodeAux->elem;
				nodeAux = nodeAux->sig;
			}
		}

		o << '\n';
	}

	void insertar(int p, insertaLista<T> &list) {
		if (p == 0) {
			Nodo * nodo = this->prim;
			this->prim = list.prim;
			list.ult->sig = nodo;
		}
		else {
			Nodo * nodo = this->prim;
			for (int i = 0; i < p - 1; i++) {
				nodo = nodo->sig;
			}
			Nodo * next = nodo->sig;
			nodo->sig = list.prim;
			list.ult->sig = next;
		}

		for (int i = 0; i < list.nelems; i++) {
			this->nelems++;
		}
		list.prim = NULL;
		list.ult = NULL;
	}
};
bool resuelveCaso() {
	int n;

	cin >> n;

	if (!std::cin)
		return false;

	insertaLista<int> lista, insertar;
	int aux, m, p;

	for (int i = 0; i < n; i++) {
		cin >> aux;
		lista.push(aux);
	}
	cin >> m >> p;

	for (int i = 0; i < m; i++){
		cin >> aux;
		insertar.push(aux);
	}
	lista.insertar(p, insertar);
	lista.print();

	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}