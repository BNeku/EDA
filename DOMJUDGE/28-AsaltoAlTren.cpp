//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//P: { v.size() > 0 && n <= v.size() }
int resuelveCaso(const vector<int> &v, const int &n, int &pos) {
	int suma=0,max=-1, p;

	//cota: v.size() - i
	//I = 0<=k<i && max(sum j: 0<=j<n : v[j])
	for (int i = 0; i < v.size(); i++){
		p = i;
		for (int j = 0; j < n && p<v.size(); j++){
			suma += v[p];
			p++;
		}
		if (suma >= max){ 
			pos = i;
			max = suma; 
		}
		suma = 0;
	}

	return max;
}
//Q: { max =  max(0<=k<v.size() && sum j: 0<=j<n : v[j]) }
//Coste O(n)

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos28.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	cin >> numCasos;
	int numVagones, numAsaltar, pos=0, valor;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numVagones;
		cin >> numAsaltar;
		vector<int> v(numVagones);
		for (int i = 0; i < numVagones; i++){
			cin >> v[i];
		}
		 valor=resuelveCaso(v, numAsaltar, pos);

		 cout << pos << " " << valor << endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}