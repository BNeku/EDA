//NEREA JIMÉNEZ GONZÁLEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//coste lineal O(n)=> O(j) => O(i) Se recorre el vector entero empezando tanto por el principio como por el final
//P: v.size>=0
int resuelveCaso(vector<int> &v) {
	int i = 0, j=v.size()-1, pos;
	//cota j-i
	//I: 0<=i<=v.size()-1
	//I: forall u:: 0<=u<i ==> v[u]>0 ==> pos=i || v[u]< 0 ==> pos=u
	while (i <= j){
		if (v[j]>= 0 && v[i] < 0){
			swap(v[i], v[j]);
			j--;
			i++;
		}else if (v[j] >= 0 && v[i] >=0){
			i++;
		}else if (v[j] < 0 && v[i] < 0){
			j--;
		}
		else{
			i++;
			j--;
		}	
	}
	pos = 0;
	while (pos<v.size() && v[pos]>=0){
		pos++;
	}

	return pos;
}
//Q: pos == forall u:: 0<=u<v.size ==> v[u]>0 ==> pos=v.size() || v[u]< 0 ==> pos=u


int main() {
	int n;
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos07.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		cout << resuelveCaso(v)<<endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}