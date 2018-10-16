//NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
using namespace std;
const int MAX_SILLAS = 1000;


// P={personas:ent}
// bool resuelveCaso(personas:ent, string sillas) dev todos
bool resuelveCaso(int personas, string sillas) {
	bool todos = true, izq=false, dcha=false;

	for (int i = 0; i < personas; i++){
		if (sillas[i] == 'D')
			dcha = true;
		else if (sillas[i] == 'I')
			izq = true;
	}

	if (dcha && izq)
		todos = false;

	return todos;

}
// Q={todos=(Exist j, k: 0 <= j < k < n: (V[j] == I && V[k] == D) || (V[k]== I && V[j] == D))}
// I={todos=(Forall i Exist j, k: i <= j < k <= n: (V[j] == I && V[k] == D) || (V[k]== I && V[j] == D))}
// Cota (n+1)
// O(n) -> O(personas)

int main(){
	int nPersonas;
	string sillas;

	cin >> nPersonas;
	cin.ignore();
	while (nPersonas != 0){
		cin >> sillas;
		if (resuelveCaso(nPersonas, sillas)){
			cout << "TODOS COMEN" << endl;
		}
		else{
			cout << "ALGUNO NO COME" << endl;
		}
		cin >> nPersonas;
		cin.ignore();
	}

	//system("pause");
	return 0;
}