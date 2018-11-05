//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//coste lineal O(n)=>O(v.size()) ya que el bucle while solo recorre el vector v una vez de principio a fin
void numPicosValles(vector<int> v, int n, int&npicos, int&nvalles){
	//P: 0 < v.Length <= 10000 ^ forall k: 0 <= k < v.Length-1 ==> -50 <= v[k] <= 60
	//la precondición NO se debe de comprobar en el código
	int i = v.size()-1;
	npicos = 0;
	nvalles = 0;
	//cota: i
	while (i > 1){
		if ((v[i - 1] > v[i - 2]) && (v[i] < v[i - 1]))
			npicos++;
		if ((v[i] > v[i - 1]) && (v[i - 1] < v[i-2]))
			nvalles++;
		i--;
	}

	//Q: 
	// npicos = #z: 1 <= z < v.Length- : v[z-1] < v[z] > v[z+1]
	// nvalles = #z: 1 <= z < v.Length-1 : v[z-1] > v[z] < v[z-1]
	//invariante: 1 <= n <= v.Length-1 ^ npicos = #z: n <= z < v.Length: v[z-1] < v[z] > v[z+1] ^ nvalles = #z: 1 <= z < v.Length-1 : v[z-1] > v[z] < v[z-1]
}


void resuelveCaso() {
 //resuelve aqui tu caso
	int npicos, nvalles; //NO DEBEN ESTAR INICIALIZADOS
	int n;
    //Lee los datos
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
    //Calcula el resultado
	numPicosValles(v, n, npicos, nvalles);
    //Escribe el resultado
	cout << npicos << " " << nvalles << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos01.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}