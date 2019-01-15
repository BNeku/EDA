//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const int NUMERO = 4;

bool comprobarSol(const vector<int> &v){

	if (v[2] > (v[1] + v[3])){
		if (v[1] > v[3] || (v[1]==v[3])){
			return true;
		}
		else{
			return false;
		}
			
	}
	else{
		return false;
	}
}

bool comprobarVerde(const vector<int> &v){
	if (v[3] > v[1]){
		return false;
	}
	else{
		return true;
	}
}

void vueltaAtras(const vector<int> &v, vector<int> &sol, vector<string> &mSol, bool &solOk){
	bool ok = false;
	//si ha llegado a la altura
	if (sol[0] == v[0]){
		ok = comprobarSol(sol);
		if (ok){
			solOk = true;
			int num = mSol.size();
			for (int i = 0; i < num; i++){
				cout << mSol[i] << " ";
			}
			
			cout << endl;
		}
	}
	else{
		//rama azul
		//hay piezas azules?
		if (sol[1] < v[1]){
			//pongo una pieza azul
			sol[1]++;
			mSol[sol[0]] = "azul";
			//aumento altura
			sol[0]++;
			vueltaAtras(v, sol, mSol, solOk);
			sol[1]--;
			sol[0]--;
		

		}
		//rama rojo
		//hay piezas rojas?
		if (sol[2] < v[2]){
			//pongo una pieza roja
			sol[2]++;
			mSol[sol[0]] = "rojo";
			//aumento altura
			sol[0]++;
			vueltaAtras(v, sol, mSol, solOk);
			sol[2]--;
			sol[0]--;
			
				
		}
		//rama verde
		//si la anterior pieza no era verde
		if (mSol[sol[0] - 1] != "verde"){
			//hay piezas verdes?
			if (sol[3] < v[3]){
				//pongo una pieza roja
				sol[3]++;
				mSol[sol[0]] = "verde";
				//aumento altura
				sol[0]++;
				ok = comprobarVerde(sol);
				if (ok){
					vueltaAtras(v, sol, mSol, solOk);
				}
				sol[3]--;
				sol[0]--;
				
			}
		}
		
	
	}

}

//P: v[0] >1
void resuelveCaso(const vector<int> &v) {
	bool solOk = false;
	//si la altura es mayor que los bloques disponibles
	//si no tenemos bloques rojos
	if (v[0] > (v[1] + v[2] + v[3]) || v[2] == 0){
		cout << "SIN SOLUCION" << endl;
	}
	else{
		vector<int> sol(NUMERO);
		vector<string> mSol(v[0]);
		mSol[0] = "rojo";
		sol[2]++;
		sol[0]++;

		vueltaAtras(v, sol, mSol, solOk);

		if (!solOk){
			cout << "SIN SOLUCION" << endl;
		}
		cout << endl;
	}
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos23.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	vector<int> v(NUMERO);
	// Resolvemos
	for (int i = 0; i < NUMERO; ++i) {
		cin >> v[i];
	}
	//altura azul rojo verde
	while (v[0] != 0 || v[1] != 0 || v[2] != 0 || v[3] != 0){
		resuelveCaso(v);

		for (int i = 0; i < NUMERO; ++i) {
			cin >> v[i];
		}
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}