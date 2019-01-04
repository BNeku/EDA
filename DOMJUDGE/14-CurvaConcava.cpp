#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//P= {v.size()>0 && 0<=a<=b<v.size()}
int resolver(vector<int> &v, int a, int b){
	int min, p;

	if (b == a + 1){
		min = v[a];
	}
	else if (b == a + 2){
		if (v[a] >= v[a + 1]){
			min = v[a + 1];
		}
		else{
			min = v[a];
		}
	}else{
		p = (a + b) / 2;

		if (v[p] > v[p-1] && v[p] < v[p+1] ){
			min = resolver(v,a,p);
		}
		else if (v[p] < v[p - 1] && v[p] > v[p + 1]){
			min = resolver(v, p, b);
		}
		else{
			min = v[p];
		}
	}

	return min;

}
//Q{min = exist u: 0<=u<v.size() : (forall k: 0<=k<v.size() ==> v[k]>= v[u])}
//T(n) = c0 si n=1
//T(n) = T(n/2^k)+ k*c1   si n>1
// T(n) pertenece a O(log n) ya que
/*
2^k = n seria el último caso recursivo
*/

int main(){
	int n;
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos14.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++){
			cin >> v[j];
		}
		cout << resolver(v, 0, v.size()) << endl;

	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}