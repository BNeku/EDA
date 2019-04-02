// Nerea jimenez Gonzalez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "queue_eda.h"

using namespace std;

template <class T>
class ListaInvierte : public queue<T>{
	using Nodo = typename queue<T>::Nodo;
public:
	void print(ostream &o = std::cout)const{
		if (!this->empty()) {// la lista no esta vacia
			Nodo *nodo = this->prim;
			for (int i = 0; i < this->nelems; i++) {
				cout << nodo->elem << " ";
				nodo = nodo->sig;
			}

		}
	}

	//Invertir los nodos de una lista
	void invierte(){
		int n = this->nelems;
		Nodo * nodo = this->prim;
		Nodo * sig;

		for (int i = 0; i < n; i++){
			for (int j = i; j < n-1; j++){
				sig = nodo->sig;
				this->prim = sig;
				nodo->sig = nodo; 
				nodo = sig;
			}
		}

	}
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaInvierte<T> const& a) {
	a.print(o);
	return o;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	ListaInvierte<int> cola;
	int aux;

	cin >> aux;

	if (!std::cin)  // fin de la entrada
		return false;

	while (aux != 0){
		cola.push(aux);
		cin >> aux;
	}
	
	cola.invierte();
	cout << cola << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_09.txt");
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
