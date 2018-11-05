#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//coste lineal O(n)=> O(v.size()-1) Solo realiza el bucle while una pasada al vector v desde la posición 0 hasta v.size()-1
//P: forall i,j:: 0<=i<j<v.size() ==> v[i]>0 && v[i]!=v[j]
int resuelveCaso(vector<int> v){
	int gente = 0;
	int i = 0;

	if (v.size() != 0){
		int max = v[v.size() - 1];
		//cota: v.size()-1-i
		while (i< v.size()-1){
			if (v[i]> max){
				gente++;
			}
			else if (v[i]>v[i+1]){
				gente++;
			}
			i++;
		}
	}

	return gente;
}
/*
I: 0<=i<=v.size() && #v[j]: forall j:: 0<=j<i ==> v[j] > v[j+1] && v[j]>max
Q: gente = #v[j]: forall j:: 0<=j<v.size()-1 ==> v[j] > v[j+1] && v[j]>max
*/

int main(){
	int n;
	// Para la entrada por fichero.

#ifndef DOMJUDGE
	std::ifstream in("casos02.txt");
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
		cout << resuelveCaso(v) << endl;
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}