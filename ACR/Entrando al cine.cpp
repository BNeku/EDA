//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;
const int VECINOS = 10000;


void resuelveCaso() {
	//resuelve aqui tu caso
	bool abrirPuerta = true;
	int nGentePuerta = 0;
	int j = 0;
	//Lee los datos
	int nVecinos;
	cin >> nVecinos;
	int butacas[VECINOS];
	for (int i = 0; i < nVecinos; i++){
		cin >> butacas[i];
	}
	//Calcula el resultado
	while(j<nVecinos){
		if (butacas[j] % 2 != 0 ){
			if (butacas[j + 1] % 2 == 0 && j < nVecinos-1){
				abrirPuerta = false;
				nGentePuerta++;
			}
			
		}
		else{
			nGentePuerta++;
		}
		j++;
	}

	//Escribe el resultado
	if (abrirPuerta){
		cout << "SI " << nGentePuerta << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main() {
	// Para la entrada por fichero.
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);

#endif
*/
	//system("PAUSE");
	return 0;
}