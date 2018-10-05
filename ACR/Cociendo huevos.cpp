//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;



bool resuelveCaso() {
	//resuelve aqui tu caso
	int numH, capacidad, rdo;
	bool end = true;
	//Lee los datos
	cin >> numH >> capacidad;
	while (numH != 0 && capacidad != 0){
		rdo = numH / capacidad;
		if (numH % capacidad > 0)
			rdo++;
		rdo= rdo * 10;
		cout << rdo << endl;
		cin >> numH >> capacidad;
	}
	end = false;

	return end;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

	while (resuelveCaso());

	// restablecimiento de cin
/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif*/
	//system("pause");
	return 0;
}