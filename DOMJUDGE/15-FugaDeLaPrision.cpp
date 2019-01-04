//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//P: v.size()>1
char resolver(const vector<char> &v, int ini, int fin){
	char fuga = 0;

	if (ini + 2 == fin){
		fuga = v[ini]+1;
	}
	else{
		int m = (ini + fin) / 2;
		
		if (v[m] - v[0] == m){
			fuga = resolver(v, m, fin);
		}
		else{
			fuga = resolver(v, ini, m + 1);
		}

	}

	return fuga;
}
//T(n) = c1 si n=2
//T(n) = T(n/2) + c2 si n>2
// T(n) pertenece a O(n) ya que n=1, es decir, el numero de llamadas recursivas es 1, y por lo tanto sigue el esquema de O(n^k* log n) donde k es 0 y b 2, por lo que a = b^k
//por lo que queda O(n^0*log n), dando lugar a O(log n)

//P: v.size() > 0
char resuelveCaso(const vector<char> &v, const int &ini, const int &fin) {
	char fuga;

	//si el que se escapa es el primero
	if (v[0] != ini){
		fuga = ini;
	}//si el que escapa es el ultimo
	else if (v[v.size() - 1] != fin){
		fuga = fin;
	}//otro
	else{
		fuga = resolver(v, 0, v.size());
	}

	return fuga;
}
//Q: fuga = (forall k:: 0<= k < v.size() : v[k] < v[k+1]) && exist j: (j no pertenece a v && exist a, b :: 0<=a<b<v.size() && v[a] < j < v[b])

int main() {
	char ini, fin,aux;
	int m = 0;
	
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos15.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
		vector<char> v;
		cin >> ini >> fin;
		for (int i = 0; i < (fin - ini); i++) {
			cin >> aux;
			v.push_back(aux);
		}

		cout << resuelveCaso(v, ini, fin)<<endl;
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}