// NEREA JIMÉNEZ GONZÁLEZ

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
//coste lineal O(n)=>O(v.size()) ya que solo se recorre una vez el vector
//P: v!=null
void resuelveCaso(vector<int> v, int &maxR, int &nRacha, int &j) {
	maxR = 0, nRacha = 0, j = 0;
	int auxR = 0,auxJ=0, i = 0;
	//cota v.size()-i
	//I: 0<=i<=v.size()
	//I: #u::forall u :: 1<=u<i ==> v[u]>0 && v[u-1]>0::#u && #w::forall w:: u<=w<i ==> v[w]!=v[u]::#w
	while (i < v.size()){
		if (v[i]>0){
			auxR++;
			if (auxR > maxR){
				maxR = auxR;
				nRacha = 1;
				auxJ = i+1;
			}
			else if (auxR == maxR){
				nRacha++;
				auxJ = i + 1;
			}
		}
		else{
			auxR = 0;
		}
		i++;
	}
	j = v.size() - auxJ;
}
//Q: maxR== #u::forall u :: 1<=u<v.size() ==> v[u]>0 && v[u-1]>0::#u
//nRacha== #maxR
//j == #w::forall w:: u<=w<v.size() ==> v[w]!=v[u]::#w


int main() {
	int n, maxS, nS, j;
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos10.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (cin>>n){
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		resuelveCaso(v, maxS, nS, j);
		cout << maxS << " " << nS << " " << j << endl;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}