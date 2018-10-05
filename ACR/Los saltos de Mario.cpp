//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {
	/*P: 0 > nSaltos > 1 000 000 000 */
	int nSaltos, salto1, salto2;
	int arriba = 0, abajo = 0;
	//Lee los datos
	cin >> nSaltos;
	cin >> salto1;
	for (int i = 1; i < nSaltos; i++){
		cin >> salto2;

		if (salto1 < salto2){
			arriba++;
		}
		else if (salto1 > salto2){
			abajo++;
		}

		salto1 = salto2;
	}
	/*Q: forall #u, #w :: 0 < u <= w < nSaltos :: u > w || u < w ==> u w*/
	//Escribe el resultado
	cout << arriba << " " << abajo << endl;
}

int main() {
	int numCasos;
	cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	//system("PAUSE");
	return 0;
}