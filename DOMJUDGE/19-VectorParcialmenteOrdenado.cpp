//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct lado{
	int min;
	int max;
};

bool resuelveCaso(const vector<int> &v, int ini, int fin, lado &aux) {
	bool orden = false;
	int m = (ini + fin) / 2;
	lado dcha, izqda;
	dcha.min = 0; dcha.max = 0;
	izqda.min = 0; izqda.max = 0;
	
	if (ini == fin){
		aux.max = v[ini];
		aux.min = v[ini];
		orden = true;
	}
	else if (resuelveCaso(v, ini, m, izqda) && resuelveCaso(v, m+1, fin, dcha)){

		if (izqda.max > dcha.max) aux.max = izqda.max;
		else aux.max = dcha.max;
		        
		if(izqda.min < dcha.min) aux.min = izqda.min;
		else aux.min = dcha.min;

		if (izqda.min <= dcha.min && izqda.max <= dcha.max){
			orden = true;
		}
	}

	

	return orden;
}


int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos19.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	
	int aux;
	cin >> aux;
	// Resolvemos
	while (aux != 0){
		vector<int> v;
		lado aux1;
		aux1.max = 0; aux1.min = 0;
		v.push_back(aux);
		while (aux != 0){
			cin >> aux;
			v.push_back(aux);
		}
		v.pop_back();
		if (resuelveCaso(v, 0, v.size()-1, aux1)){
			cout << "SI" << endl;
		}else{
			cout << "NO" << endl;
		}
		cin >> aux;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}