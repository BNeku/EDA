//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;



int resuelveCaso(int uvas, int A, int B) {
	int total=0,resto,coc;

	coc = uvas / A;
	resto = uvas - (coc*A);
	if (resto > 0){
		if (resto < B){
			total += resto;
		}
		else{
			total += B;
		}
	}
		
	total += coc*B;


	return total;
}

int main() {
	int numUvasCompradas, uvasNoSanas, uvasA;
	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		cin >> numUvasCompradas >> uvasA >> uvasNoSanas;
		cout << resuelveCaso(numUvasCompradas, uvasNoSanas, uvasA) << endl;
	}
	return 0;
}