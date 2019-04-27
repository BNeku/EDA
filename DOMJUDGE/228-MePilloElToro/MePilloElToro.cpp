// Nerea jimenez gonzalez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>

#include "treemap_eda.h"  // propios o los de las estructuras de datos de clase

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	string alumno, resultado, nota, trash;
	map<string, int> clase;
	// leer los datos de la entrada
	cin >> N;
	if (N==0)
		return false;
	
	getline(cin, trash);

	for (int i = 0; i < N; i++){
		getline(cin, alumno);

		//devuelve false si ya existe
		clase.insert({ alumno, 0 });
		getline(cin, nota);
		
		if (nota == "CORRECTO"){
			++clase[alumno];
		}else{
			--clase[alumno];
		}
		
	}

	for (auto const &cv: clase){
		if (cv.valor != 0){
		cout << cv.clave  << ", " << cv.valor << endl;
		}
	}

	cout << "---" << endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_28.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
