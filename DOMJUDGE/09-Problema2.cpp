//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//coste lineal O(n)=>O(v.size) es lineal ya que solo recorre el vector una vez desde el principio hasta el final
//P: v!=null && forall u: 0<=u<v.size()-1 ==> v[i]>v[i+1] 
void resuelveCaso(vector<int> &v){
	int i = 0, par=0;
	//cota v.size()-i
	//I: 0<=i<=v.size() && forall u: 0<=u<i ==> v[u]%2==0
	while (i < v.size()){
		if (v[i]%2==0){
			swap(v[par], v[i]);
			par++;
		}
		i++;
	}
	v.resize(par);
}
//Q: v== forall u: 0<=u<v.size() ==> v[u]%2==0

int main() {
	int n;
	// Para la entrada por fichero./*
#ifndef DOMJUDGE
	std::ifstream in("casos09.txt");
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
		resuelveCaso(v);
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}