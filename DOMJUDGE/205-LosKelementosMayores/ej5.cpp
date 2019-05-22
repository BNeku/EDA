
// Nerea jimenez Gonzalez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "set_eda.h"

using namespace std;


template<class T>
class setMayores{
	set<T> serie;
public:
	void insertar(T elemento){
		//si el elemento no existe ya
		if (serie.count(elemento) == 0){
			serie.insert(elemento);
		}
	}

	void kmayores(int k){
		set<T> mayores;
		int count=serie.size();

		for (auto i : serie){
			if (count > k){
				count--;
			}
			else{
				mayores.insert(i);
			}
		}
		for (auto j : mayores){
			cout << j << " ";
		}
		cout << endl;
	}

};

bool resuelveCaso() {
	char letra;
	//leemos si es P o N
	cin >> letra;

	if (!std::cin)  // fin de la entrada
		return false;
	
	if (letra == 'P'){
		setMayores<string> serie;
		int k;
		string palabra;
		//leemos el k
		cin >> k;
		cin >> palabra;
		while (palabra != "FIN"){
			serie.insertar(palabra);
			cin >> palabra;
		}
		serie.kmayores(k);
	}
	else if (letra == 'N'){
		setMayores<int> serie;
		int k, n;
		
		//leemos el k
		cin >> k;
		cin >> n;
		while (n != -1){
			serie.insertar(n);
			cin >> n;
		}
		serie.kmayores(k);
	}

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_5.txt");
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
