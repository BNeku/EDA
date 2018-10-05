//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;
const int NUMBERS = 99999;


void resuelveCaso() {
	//resuelve aqui tu caso
	int total = 0;
	//Lee los datos
	int nDec;
	cin >> nDec;
	int listaD[NUMBERS];
	for (int i = 0; i < nDec; i++){
		cin >> listaD[i];
	}
	//Calcula el resultado
	for (int i = 0; i < nDec; i++){
		if (listaD[i] % 2 == 0){
			total++;
		}
	}
	//Escribe el resultado
	cout << total << endl;
}

int main() {
	// Para la entrada por fichero.
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}