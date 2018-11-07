// NEREA JIMÉNEZ GONZÁLEZ

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//P:p > 1 && v!=null
vector<int> resuelveCaso(vector<int> v, int p) {
	vector<int> sol;
	int i = v.size() - 2;
	int aux = 1,auxMax=0, cad=v[v.size()-1];

	//cota i
	while (i >= 0){
		if (v[i] > cad){
			if (aux >= p){
				sol.push_back(i + aux);
				if (aux > auxMax)
					auxMax = aux;

			}
			aux = 1;
			cad = v[i];

		}
		else if (v[i] == cad){
			aux++;
		}
		else{
			if (aux >= p){
				sol.push_back(i + aux);
				if (aux > auxMax)
					auxMax = aux;
			}
			aux = 0;

		}
		i--;
	}

	if (aux != 0){
		if (aux >= p){
			sol.push_back(i + aux);
			if (aux > auxMax)
				auxMax = aux;
		}
	}

	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v.size()-1; j++){
			if (v[j] < v[j + 1])
				swap(v[j], v[j + 1]);
		}

	}
	cout << auxMax << " " << sol.size();
	return sol;
}
//Q: 

int main() {
	int n,p;
	vector<int> sol;
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos11.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (cin >> n){
		cin >> p;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		sol =resuelveCaso(v,p);
		for (int i = 0; i < sol.size(); i++){
			cout << " " << sol[i];
		}
		cout << endl;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}