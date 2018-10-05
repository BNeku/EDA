//NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
using namespace std;

bool resuelveCaso() {
	long long int nPersonas = 0, altura1, altura2;
	bool ok = false, salir = false, crec = false, decre = false;
	/*P: nPersonas > 2 */

	cin >> nPersonas;
	if (nPersonas == 0){
		return false;
	}
	else if (nPersonas == 1){
		salir = true;
	}

	cin >> altura1;
	for (int i = 1; i < nPersonas; i++){
		cin >> altura2;
		if (!salir){
			if (altura1 < altura2 && i == 1){
				crec = true;
			}
			else if (altura1 > altura2 && i == 1){
				decre = true;
			}
			if ((altura1 >= altura2 && crec) || (altura1 <= altura2 && decre) || (!decre && !crec)){
				salir = true;
			}
		}
		altura1 = altura2;
	}
	if (!salir)
		ok = true;
	
	/*Q: ok=true ==> forall u:: 0 <= u < n-1 ==> (a[u] < a[u+1]) || (a[u] > a[u+1])
		ok=true == forall u ==> u < u+1 || u > u+1
		 ok=false ==> e.o.c*/
	if (ok){
		cout << "DALTON" << endl;
	}
	else{ cout << "DESCONOCIDOS" << endl; }
	return true;
}


int main() {


	while (resuelveCaso());

	
	return 0;
}