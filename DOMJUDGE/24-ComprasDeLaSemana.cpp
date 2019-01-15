//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct super{
	vector<int> precioProd;
	int numProdSelec;
};


bool esValido(int &coste, int &mCoste){
	if (coste < mCoste || mCoste == -1){
		mCoste = coste;
		return true;
	}
	else{
		return false;
	}
}

void vueltaAtras(vector<super> &v, const int &numProd, int &carrito, int &coste, int &mejorCoste){

	for (int i = 0; i < v.size(); i++){

		if (v[i].numProdSelec<3){
			coste += v[i].precioProd[carrito];
			v[i].numProdSelec++;
			carrito++;

			if (carrito==numProd){
				if (coste < mejorCoste || mejorCoste==-1)
					mejorCoste = coste;
			}
			else{
				if (coste < mejorCoste || mejorCoste==-1){
					vueltaAtras(v, numProd, carrito, coste, mejorCoste);
				}
			}
			carrito--;
			v[i].numProdSelec--;
			coste -= v[i].precioProd[carrito];
			
		}
	}

}

void resuelveCaso(vector<super> v){
	int carrito = 0;
	int costeTotal = 0;
	int costeTotalMejor = -1;
	int numProd = v[0].precioProd.size();


	vueltaAtras(v, numProd, carrito, costeTotal, costeTotalMejor);
	if (costeTotalMejor != -1){
		cout << costeTotalMejor << endl;
	}
	else{
		cout << "Sin solucion factible" << endl;
	}
	

}

int main() {
	// Para la entrada por fichero.
/*#ifndef DOMJUDGE
	std::ifstream in("casos24.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/


	int numCasos;
	int prod, sup;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> sup;
		cin >> prod;
		if (sup == 0 || sup==0){
			cout << "Sin solucion factible" << endl;
		}
		else{
			vector<super> v(sup);

			for (int i = 0; i < sup; i++){
				v[i].precioProd.resize(prod);
				v[i].numProdSelec = 0;
				for (int j = 0; j < prod; j++){
					cin >> v[i].precioProd[j];
				}
			}
			resuelveCaso(v);
		}
	}

	/*
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}