//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

#include "treemap_eda.h"


using namespace std;

void leerAntiguo(map<string, int>& diccionarios){
	string clave, s;
	int valor;
	getline(cin, s);
	stringstream ss(s);
	while (ss >> clave && ss >> valor) {
		diccionarios[clave] = valor;
	}
}

void resuelveCaso() {
	map<string, int> oldDic;
	string clave, s;
	int valor;
	set<string> add, sub, mul;
	leerAntiguo(oldDic);
	//leemos el nuevo 
	getline(cin, s);
	stringstream ss(s);
	while (ss >> clave && ss >> valor){

		if (oldDic.count(clave) > 0){

			if (oldDic[clave] != valor){
				//si ha cambiado el valor
				oldDic.erase(clave);
				mul.insert(clave);
			}
			else{
				oldDic.erase(clave);
			}
		}
		else{
			//si la clave no está, ha sido añadida
			add.insert(clave);
		}
	}

	for (auto const &cv : oldDic){
		
		sub.insert(cv.clave);
		//oldDic.erase(cv.clave);
		


	}

	if (add.size() > 0 || mul.size() > 0 || sub.size() > 0){
		if (add.size() > 0){
			cout << "+ ";
			for (auto const & i: add){
				cout << i << " ";
			}
			cout << endl;
		}
		if (sub.size() > 0){
			cout << "- ";
			for (auto const & i : sub){
				cout << i << " ";
			}
			cout << endl;
		}
		if (mul.size() > 0){
			cout << "* ";
			for (auto const & i : mul){
				cout << i << " ";
			}
			cout << endl;
		}
	}else{
		cout << "SIN CAMBIOS" << endl;
	}

	cout << "----" << endl;

	

	


}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos2_30.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	cin.ignore();
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