//NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "horas.h"


bool resuelveCaso() {
	int nH=0, nC=0;
	horas h;

	cin >> nH >> nC;

	if (nH == 0 && nC==0){
		return false;
	}

	vector<horas> horario(nH);

	for (int i = 0; i < nH;i++){
		cin >> horario[i];
	}

	for (int j = 0; j < nC;j++){
		try{
			cin >> h;
			//iterador automatico
			auto p = lower_bound(horario.begin(), horario.end(), h);

			if (p == horario.end()){
				cout << "NO\n";
			}
			else{
				//*p = objeto que está apuntando ese iterador
				cout << *p << "\n";
			}
		}
		catch (invalid_argument const &e){
			cout << e.what() << "\n";
		}
	}

	cout << "---" << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos2_01.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}