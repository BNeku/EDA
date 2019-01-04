//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//P={v.size()>1}
int resuelveCaso(const vector<int> &v, int ini, int fin) {
	int min;

	if (ini+1>=fin){
		if (v[ini] > v[fin]){
			min = v[fin];
		}
		else{
			min = v[ini];
		}
	}
	else{
		int m = (ini + fin) / 2;
		if (v[ini] > v[m]){
			min = resuelveCaso(v, m, fin);
		}
		else{
			min = resuelveCaso(v, ini, m);
		}
		
	}

	return min;
}
//Q={min = forall k:: 0<=k<v.size() => min < v[k] && min pertenece a v}
//T(n) = c0 si n=1
//T(n) = T(n/2)+c1 si n>1
//T(n) pertenece a O(log n) ya que a =1, b=2 por lo que a=b^k (1=b^0) y por lo tanto, n^k *log n = log n

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos17.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numElem;

	// Resolvemos
	while (cin >> numElem) {
		vector<int> v(numElem);
		for (int i = 0; i < numElem; i++){
			cin >> v[i];
		}
		cout << resuelveCaso(v, 0, v.size()-1)<<endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}