//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX = 100;

void resuelveCaso() {
	string nombreReal;
	string nombres[MAX];
	int nNombres;

	//Lee los datos
	cin >> nombreReal;
	cin >> nNombres;
	
	for (int i = 0; i < nNombres; i++){
		cin >> nombres[i];
	}
	//Escribe el resultado
	if (resultado(nNombres, nombreReal, nombres)){
		cout << "VERDADERA" << endl;
	}
	else{ cout << "FALSA" << endl; }
}

bool resultado(int nNombres, string nombreReal, string nombres[MAX]){
	/*
	P: 0 < nNombres <= 100 ^ 0 < len(nombreReal) < 10  ^  0 < len(nombres) <= 100
	*/
	bool ok = false, salir = false;
	int i = 0;

	if (nNombres != 1){
		while (i < nNombres){
			if (nombres[i] == nombreReal){
				if (i == nNombres - 1 && !salir){
					ok = true;
				}
				else{
					salir = true;
				}
			}
			i++;
		}
	}
	/*
	Q:	ok=1 ==> exists i:: i = nNombres-1 ==> nombre[i]=nombreReal ^ forall i:: 1 < i < nNombres-1 ==> nombre[i] != nombreReal
		ok=0 ==> e.o.c.
	*/
	return ok;
}

int main() {
	// Para la entrada por fichero.
	/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	*/

	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	/*
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	
	#endif
	*/
	//system("PAUSE");
	return 0;
}