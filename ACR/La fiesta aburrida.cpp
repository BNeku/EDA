//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void resuelveCaso() {
 //resuelve aqui tu caso
	string nombre, aux;
	

	//Lee los datos
	cin >> aux;
	cin >> nombre;
	
    //Calcula el resultado

    //Escribe el resultado
	cout << "Hola, " << nombre << "."<< endl;
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