//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <string>
using namespace std;



string resuelveCaso(int fila, int col) {
	string casilla;
	string aux;

	switch (fila){
	case 1: aux = "h"; break;
	case 2: aux = "g"; break;
	case 3: aux = "f"; break;
	case 4: aux = "e"; break;
	case 5: aux = "d"; break;
	case 6: aux = "c"; break;
	case 7: aux = "b"; break;
	case 8: aux = "a"; break;
	default: break;
	}

	casilla = aux + to_string(col);

	return casilla;
}

int main() {

	int fila, col;
	cin >> fila>> col;
	// Resolvemos
	while(fila!=0 || col!=0) {
		cout << resuelveCaso(fila,col) << endl;
		cin >> fila >> col;
	}
	return 0;
}