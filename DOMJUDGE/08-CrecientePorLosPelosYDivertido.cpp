//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//coste lineal O(n)=> O(v.size()-1) Ya que recorre el vector de principio a fin, o incluso no llega al final
//P: v!=null
bool resuelveCaso(int rep, vector<int> v) {
	bool cumple = false, diver=true, crec=true;
	int i = 0, repet=1, aux=v[0];
	//cota v.size()-i
	//I: 0<= i <=v.size()-1
	//I: crec == forall u:: 0<=u<i ==> v[u]>v[+1] && v[u+1]-v[u] == 1
	//I: diver== #v[u] : forall u:: 0<=u<i ==> #v[u] < rep
	while (i < v.size()-1 && (diver || crec)){
		//creciente y sin diferencia mayor a 1
		if (aux == v[i + 1]){
			repet++;
		}
		else if (aux >= v[i + 1] || (v[i + 1] - aux > 1)){
			crec = false;
		}
		else{
			aux = v[i + 1];
			repet = 1;
		}


		//que no se repita ningun numero mas de rep veces
		if (repet > rep)
			diver = false;
		
		i++;
	}
	
	if (diver && crec)
		cumple = true;

	return cumple;
}
//Q: cumple == diver && crec
//crec == forall u:: 0<=u<v.size()-1 ==> v[u]>v[+1] && v[u+1]-v[u] == 1
//diver== #v[u] : forall u:: 0<=u<v.size()-1 ==> #v[u] < rep

int main() {
	int maxR, n;
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos08.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> maxR;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		if (resuelveCaso(maxR, v)){
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