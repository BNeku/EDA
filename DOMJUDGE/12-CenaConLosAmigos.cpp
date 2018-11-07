//NEREA JIMÉNEZ GONZÁLEZ
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//P:
void resuelveCaso(int num) {
	int max = 0, sum = 0, cont = 0, ini = 0, auxM = 0;
	bool ok = true;

	//lectura
	vector<int> v(num);
	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}
	sum = 0;

	//resolver
	//cota: num-i
	for (int i = 0; i < num; i++) {
		sum += v[i];

		if (sum <= 0) {
			if (v[i] <= 0) 
				sum = 0;
			else 
				sum = v[i];
			
			cont = 0;
		}

		if (sum > 0) {
			cont++;
			if (sum > max) {
				max = sum;
				auxM = cont;
				ini = i - cont + 1;
			}
			else if (sum == max) {
				if (cont < auxM) {
					auxM = cont;
					ini = i - cont + 1;
				}
			}
		}


	}
	//salida
	cout << max << " " << ini << " " << auxM << endl;
}
//Q:

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos12.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num = 0;
	// Resolvemos
	while (std::cin >> num) {
		resuelveCaso(num);
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}