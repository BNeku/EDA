//NEREA JIMÉNEZ GONZÁLEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Coste lineal O(n)=> O(v.size) ya que recorre un bucle while al vector v desde la posición 0 hasta v.size()
//P: v!= null && 0<=p<v.Length
bool resuelveCaso(vector<int> v, int p) {
	int i = 0;
	unsigned int max = 0, min = 0;
	min--;
	if (p < v.size() - 1){
		min=v[p+1];
	}

	if (v.size() > 0)
		max = v[0];

	//cota v.size()-i
	//I: b== forall u,w:: 0 <= u <=  p < w < i ==> v[u] < v[w]
	//I: 0<=i<=v.size()
	//I: max== forall x:: 0<=x<i<=p ==> max=maximo(v[x])
	//I: min== forall z:: p<z<=i<v.size() ==> min=minimo(v[z])

	while (i < v.size()){
		if (i <= p){
			if (max < v[i])
				max = v[i];
		}
		else{
			if (min > v[i])
				min = v[i];
		}
		i++;
	}

	return max<min;
}
//Q: b== forall u,w:: 0 <= u <=  p < w < v.Length ==> v[u] < v[w]

int main() {
	int n,p;
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos03.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> n;
		cin >> p;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		if (resuelveCaso(v,p)){
			cout << "SI" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}