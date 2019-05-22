
// Nerea jimenez Gonzalez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include "polinomio.h"

using namespace std;

bool resuelveCaso() {
	int grado, coeficiente;

	cin >> coeficiente;

	if (!std::cin)  // fin de la entrada
		return false;

	polinomio p;

	cin >> grado;
	//lectura del polinomio
	while (coeficiente != 0 || grado != 0){
		p.insert(coeficiente, grado);
		cin >> coeficiente >> grado;
	}

	//calculo de los valores que dan
	int n, valor;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> valor;
		cout << p.calcular(valor) << " ";
	}
	cout << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_4.txt");
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