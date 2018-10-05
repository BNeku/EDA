//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;

const int M = 100000;

bool resuelveCaso() {
	//resuelve aqui tu caso
	int numM, aux = 0, max = 0;
	int mountain[M];
	int abadia = 1;

	//Lee los datos
	while (cin >> numM && numM != 0){
		aux = 0;
		abadia = 1;

		while (aux < numM){
			cin >> mountain[aux];
			aux++;
		}
		max = mountain[aux-1];
		for (int i = aux - 1; i >= 0; i--){
			if (mountain[i]>max){
				max = mountain[i];
				abadia++;
			}

		}
		cout << abadia <<endl;
	}
	return false;
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