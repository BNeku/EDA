//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Coste lineal O(n)=>O(v.size()) ya que recorre una vez el vector desde 0 hasta v.size() con el bucle while
//P: v.size()> 0 && h>0
void resuelveCaso(vector<int> v, int h, int &ini, int &fin){
	int i = 0, contMax=0, cont = 0;
	ini = 0, fin = 0;

	while (i < v.size()){
		//cota v.size()-i
		//I: 0<=i<=v.size() 
		//I: cont== #u :: forall 0<=u<=i ==> v[u]>h
		//I: contMax == maximo(cont)
		if (v[i]>h){
			cont++;
		}
		else{
			cont = 0;
		}

		if (cont > contMax){
			contMax = cont;
			ini = i - cont + 1;
			fin = i;
		}
		
		i++;
	}
}
//Q: #u :: forall 0<=u<.size() ==> v[u]>h

int main() {
	int n, t, prin, fin;
	// Para la entrada por fichero.

#ifndef DOMJUDGE
	std::ifstream in("casos04.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> n;
		vector <int> v(n);
		cin >> t;
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		resuelveCaso(v,t, prin, fin);
		cout << prin << " " << fin << endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}