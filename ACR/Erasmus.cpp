//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;
const int N = 100000;

bool resuelveCaso() {
	//resuelve aqui tu caso
	int casos;
	long long int nPersonas, nParejas;
	//Lee los datos
	cin >> casos;
	while (casos != 0){
		nParejas = 0;
		nPersonas = 0;
		int pais[N];

		for (int i = 0; i < casos;i++){
			cin >> pais[i];
			nPersonas += pais[i];
		}

		for (int i = 0; i < casos; i++){
			nPersonas = nPersonas - pais[i];
			nParejas += pais[i] * nPersonas;
		}
		cout << nParejas << endl;
		cin >> casos;
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