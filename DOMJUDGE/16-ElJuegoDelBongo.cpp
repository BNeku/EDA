//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//P = {v.size()>1}
int resuelveCaso(const vector<int> &v, const int &num, int ini, int fin) {
	int tachar=-1;
	int m = (ini + fin) / 2;
	
	if (ini+1==fin){
		if (m + num == v[m]){
			tachar = v[m];
		}	
	}
	else{
		tachar = resuelveCaso(v, num, ini, m);
		if (tachar == -1){
			tachar = tachar = resuelveCaso(v, num, m, fin);
		}
			
	}

	return tachar;
}
//Q = { tachar = v[u]:: 0<= u<v.size() && u + num = v[u]
//		tachar = -1 e.o.c}
//T(n) = c1 si n = 1
//T(n) = T(n/2)+c2 si n>1
//T(n) pertenece a O(log n) ya que solo hay una llamada recursiva, por lo que a = 1 y k=0, por lo que a=b^k y n^k *log n = log n

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos16.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numElem, numCantado, tachar;

	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numElem >> numCantado;
		vector<int> v(numElem);
		for (int i = 0; i < numElem; i++){
			cin >> v[i];
		}
		tachar = resuelveCaso(v, numCantado, 0, numElem);
		if (tachar == -1){
			cout << "NO"<<endl;
		}
		else{
			cout << tachar<<endl;
		}
		
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}