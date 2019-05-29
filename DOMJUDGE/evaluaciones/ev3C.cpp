
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <set>
#include "treemap_eda.h"

using namespace std;

void to_minus(string &palabra){
	for (int i = 0; i < palabra.size(); i++){
		palabra[i] = tolower(palabra[i]);
	}

}

void resuelveCaso() {
	string palabra;
	int i = 1, max = 0, candidato;
	map <string, pair<int, set<int>>> lista_palabras;

	cin >> palabra;
	to_minus(palabra);

	while (palabra != "fin"){

		if (lista_palabras.count(palabra) > 0){
			//si ya existe, aumentamos el contador y añadimos la posicion
			lista_palabras[palabra].first++;
			candidato = lista_palabras[palabra].first;
			if (candidato > max){
				max = candidato;
			}
			lista_palabras[palabra].second.insert(i);
		}
		else{
			//si no existe, lo insertamos
			lista_palabras.insert({ palabra });
			lista_palabras[palabra].first = 1;
			lista_palabras[palabra].second.insert(i);
		}

		cin >> palabra;
		to_minus(palabra);
		i++;
	}

	for (auto const a:lista_palabras){
		if (a.valor.first == max){
			cout << a.clave << " " << a.valor.first << " - ";
			for (auto i : a.valor.second){
				cout << i << " ";
			}
			cout << endl;
		}
	}
	cout << "---" << endl;

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos3C.txt");
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
