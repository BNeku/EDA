//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//P={v.size()>0}
int resuelveCaso(const vector<int> &v, int ini, int fin) {
	int impar;
	
	if (ini - fin == 1){
		impar = v[ini];
	}else if (ini + 1 == fin){
		if (v[ini] % 2 == 1){
			impar = v[ini];
		}
		else{
			impar = v[fin];
		}
	}
	else{
		int m = (ini + fin) / 2;

		if (v[m] % 2 == 1){
			impar = v[m];
		}
		else{
			impar = resuelveCaso(v, m, fin);
			if (impar % 2 == 0){
				impar = resuelveCaso(v, ini, m);
			}
		}

	}

	return impar;
}
//Q= { impar = u:: 0<=u<v.size() && v[u]%2==1}
//T(n) = c0 si n <= 2
//T(n) = 2T(n/2) + c1 si n >2
//T(n) pertenece a O(n) ya que a = 2 y k=0, donde a>b^k(2> 1) por lo que n ^ 1 = n (log en base 2 de 2  = 1)

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos18.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numElem;
	cin >> numElem;
	// Resolvemos
	while (numElem !=0){
		vector<int> v(numElem);
		for (int i = 0; i < numElem; i++){
			cin >> v[i];
		}
		cout << resuelveCaso(v, 0, numElem-1) << endl;
		cin >> numElem;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}