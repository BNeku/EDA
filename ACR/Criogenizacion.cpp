//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	long long int dato1;
	long long int max=0, nMax=0, min=0, nMin=0;
	//resuelve aqui tu caso
	//Lee los datos
	cin >> dato1;
	max = dato1;
	min = dato1;
	while (dato1 != 0){
		if (dato1 > max){
			nMax = 0;
			max = dato1;
			nMax++;
		}
		else if (dato1 == max){
			nMax++;
		}

		if (dato1 < min){
			nMin = 0;
			min = dato1;
			nMin++;
		}
		else if (dato1 == min){
			nMin++;
		}
		cin >> dato1;
	}
	//Calcula el resultado
	//Escribe el resultado
	cout << min << " " << nMin << " " << max << " " << nMax << endl;
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
	system("PAUSE");
#endif
*/
	return 0;
}