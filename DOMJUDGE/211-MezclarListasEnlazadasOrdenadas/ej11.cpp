// NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
#include "queue_eda.h"
using namespace std;

template<class T>
class ListaMezcla : public queue<T>{
	using Nodo = typename queue<T>::Nodo;
public:

	void print(ostream &o = std::cout)const{
		if (!this->empty()) {// la lista no esta vacia
			Nodo *nodo = this->prim;
			for (int i = 0; i < this->nelems; i++) {
				cout << nodo->elem << " ";
				nodo = nodo->sig;
			}
			cout << endl;

		}
	}

	void mezcla(ListaMezcla lista2){
		Nodo *prim1 = this->prim;
		Nodo *prim2 = lista2.prim;
		Nodo *aux;

		if (prim1 == NULL){//si la lista this está vacía
			this->prim = prim2;
			this->nelems = lista2.nelems;
		}
		else if (prim1 != NULL && prim2 != NULL){// si ambas listas tienen elementos

			//se mira cual de los dos elemntos va a ser el primero de la lista
			if (prim1->elem <= prim2->elem){
				aux = prim1;
				prim1 = prim1->sig;
			}
			else{
				this->prim = prim2;
				aux = prim2;
				prim2 = prim2->sig;
			}

			//mientras ambos nodos no sean nulos
			while (prim1 != NULL && prim2 != NULL){
				if (prim1->elem <= prim2->elem){
					aux->sig = prim1;
					prim1 = prim1->sig;
					aux = aux->sig;
				}
				else{
					aux->sig = prim2;
					prim2 = prim2->sig;
					aux = aux->sig;
				}
			}

			if (prim1 == NULL){
				aux->sig = prim2;
				prim2 = prim2->sig;
			}
			else if (prim2 == NULL){
				aux->sig = prim1;
				prim1 = prim1->sig;
			}
			this->nelems += lista2.nelems;
		}
		//si ambas listas están vacias no se hace nada

		lista2.prim = NULL;
		lista2.ult = NULL;
		lista2.nelems = 0;
	}
};

void resuelveCaso() {
	ListaMezcla<int> lista1,lista2;
	int n;

	//lectura lista 1
	cin >> n;
	while (n != 0){
		lista1.push(n);
		cin >> n;
	}
	//lectura lista 2
	cin >> n;
	while (n != 0){
		lista2.push(n);
		cin >> n;
	}
	//mezclamos las listas
	lista1.mezcla(lista2);
	//imprimimos la lista resultante mezclada
	lista1.print();
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos2_11.txt");
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