//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	int aux = 0, rdo=1;

	cin >> aux;
	
	if (aux == 0){
		rdo = 1;
	}
	else if (aux == 1){
		rdo = 1;
	}
	else if (aux == 2){
		rdo = 2;
	}
	else if (aux == 3){
		rdo = 6;
	}
	else if (aux == 4){
		rdo = 4;
	}
	else{
		rdo = 0;
	}

	cout << rdo <<endl;
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

	#endif*/
	//system("PAUSE");
	return 0;
}