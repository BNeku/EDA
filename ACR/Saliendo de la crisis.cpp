//NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
using namespace std;

bool resuelveCaso() {
	int nMuestras;
	int dato1, dato2;
	bool ok = true;

	cin >> nMuestras;
	if (nMuestras == 0)
		return false;
	//Leer caso de prueba
	cin >> dato1;
	for (int i = 1; i < nMuestras; i++){
		cin >> dato2;
		if (dato1 >= dato2)
			ok = false;
		dato1 = dato2;
	}
	
	//Escribir resultado
	if (ok){
		cout << "SI" << endl;
	}
	else cout << "NO" << endl;

	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/

	while (resuelveCaso());

/*	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	
#endif
	*/
	//system("pause");
	return 0;
}