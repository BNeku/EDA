#include <iostream>
#include <fstream>
using namespace std;
#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
	using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
	void print(std::ostream & o = std::cout) const {
		if (!this->empty()) {// la lista no est� vac�a
			Nodo *nodo = this->prim;
			for (int i = 0; i < this->nelems; i++) {
				cout << nodo->elem <<" ";
				nodo = nodo->sig;
			}

		}
	}

	// Duplicar los nodos de una lista
	void duplica() {
		Nodo * nodo = this->prim;
		int n = this->nelems;

		for (int i = 0; i < n; i++) {
			Nodo * sig = nodo->sig;
			nodo->sig= new Nodo(nodo->elem, sig);
			nodo = sig;
			this->nelems++;
		}

	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> const& a) {
	a.print(o);
	return o;
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!cin) return false;
	ListaDuplica<int> lista;
	// creamos la lista
	while (n != 0) {
		lista.push(n);
		std::cin >> n;
	}
	// la duplicamos
	lista.duplica();
	// y la mostramos
	std::cout << lista << '\n';
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