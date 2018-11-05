//NEREA JIMÉNEZ GONZÁLEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//coste lineal O(n) = O(v.size()) ya que se recorre una vez el vector v desde la posición 0 hasta v.size()
//P: v!=null
int resuelveCaso(vector<int> v) {
	int suma = 0, i = 0, max = v[0], nMax=0;
	//cota v.size()-i
	//I: 0<=i<=v.size()
	//I: max== forall w:: 0<=w<i==> max>v[w]
	//I: forall u:: 0<=u<max<i =>  && (sum(v[u]) - #max*max)
	while (i < v.size()){
		suma += v[i];
		if (v[i]>max){
			max = v[i];
			nMax = 1;
		}
		else if (v[i] == max){
			nMax++;
		}
		i++;
	}

	suma = suma - (nMax*max);

	return suma;
}
//Q: max== forall w:: 0<=u<v.size()==> max>v[w]
//Q: suma== forall u:: 0<=u<max<v.size() =>  && (sum(v[u]) - #max*max) 

int main() {
	int n;
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos06.txt");
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