//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//coste lineal O(n)=>O(v.size()) ya que recorre el vector v desde 0 hasta v.size() una vez con el bucle while
//P:v!=null
int resolver(vector<int> v){
	int p = -1;
	int cero = 0, uno = 0;
	int i = 0;

	//cota v.Length-i;
	while (i < v.size()){
		if (v[i] == 0)
			cero++;			
		if (v[i] == 1)		
			uno++;
		if (cero == uno)
			p = i;			
		i++;				 
	}


	return p;
	//Q:
	//cero = #k:: 0 <= k < i : v[k]=0
	//uno = #k:: 0>= k < i : v[k] =1
	//numCero(v,o, p+1) = numUno(v,0,p+1)
	//forall z:: p < z < i ==> numCero(v,0,z) != numUno(v,0,z)
}


void resuelveCaso() {
 //resuelve aqui tu caso
	int values;
	int p;
    //Lee los datos
	cin >> values;
	vector<int> v(values);
	for (int i = 0; i < values; i++){
		cin >> v[i];
	}
    //Calcula el resultado
	p = resolver(v);
    //Escribe el resultado
	cout << p << endl;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos05.txt");
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