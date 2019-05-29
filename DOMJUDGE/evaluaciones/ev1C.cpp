#include <iostream>
#include <fstream>
#include "queue_eda.h"
#include "horas.h"
using namespace std;

template<class T>
class eliminarPares : public queue<T>{
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

	void eliminarPosPares(){
		int n = this->nelems; 

		if (n > 1){//si más de 1 elemento
			Nodo * anterior = NULL;
			Nodo * nodo = this->prim;
			Nodo * next = nodo->sig;

			for (int i = 0; i < n - 1; i++){
				if (i % 2 != 0){
					nodo->sig = NULL;
					anterior->sig = next;
					this->nelems--;
					nodo = next;
					next = nodo->sig;
				}
				else{
					anterior = nodo;
					nodo = next;
					next = nodo->sig;
				}
			}

			if (n % 2 == 0){
				anterior->sig = next;
				nodo->sig = NULL;
				this->ult = anterior; 
				this->nelems--;
			}
		}
	}
};

bool resuelveCaso() {
	eliminarPares<horas> lista;
	int n;

	cin >> n;

	if (!cin)
		return false;

	horas h;

	for (int i = 0; i < n; i++){
		cin >> h;
		lista.push(h);
	}

	lista.eliminarPosPares();
	lista.print();

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos1C.txt");
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
