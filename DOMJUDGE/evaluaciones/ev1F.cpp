#include <iostream>
#include <fstream>
#include "queue_eda.h"
#include "horas.h"
using namespace std;

template<class T>
class eliminarDecrecientes : public queue<T>{
	using Nodo = typename queue<T>::Nodo;
public:

	void print(){
		if (this->nelems > 0){
			Nodo *nodo = this->prim;

			for (int i = 0; i < this->nelems; i++){
				cout << nodo->elem << " ";
				nodo = nodo->sig;
			}
			cout << endl;
		}
	}

	void eliminarDecr(){
		int n = this->nelems;

		if (n > 1){//si hay más de un elemento
			Nodo * anterior = this->prim;;
			Nodo * nodo = anterior->sig;
			Nodo * next = nodo->sig;

			for (int i = 1; i < n-1; i++){

				if (nodo->elem < anterior->elem){
					anterior->sig = next;
					nodo->sig = NULL;
					nodo = next;
					next = next->sig;
					this->nelems--;
				}
				else{
					anterior = nodo;
					nodo = next;
					next = next->sig;
				}
			}

			if (nodo->elem < anterior->elem){
				anterior->sig = next;
				nodo->sig = NULL;
				this->ult = anterior;
				this->nelems--;
			}

		}
	}
	
};

bool resuelveCaso() {
	eliminarDecrecientes<horas> lista;
	int n;

	cin >> n;

	if (!cin)
		return false;

	horas h;

	for (int i = 0; i < n; i++){
		cin >> h;
		lista.push(h);
	}

	lista.eliminarDecr();
	lista.print();

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos1F.txt");
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
