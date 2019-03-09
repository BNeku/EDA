// NEREA JIMENEZ GONZALEZ

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "stack_eda.h"
#include <vector>

using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	stack<char> pila;
	char c, aux;
	string trash;
	bool bien = true;

	cin.get(c);


	if (!std::cin)  // fin de la entrada
		return false;

	while (c != '\n' && c!= '\r' && bien) {
		if (c == '(' || c == '[' || c == '{') {
			pila.push(c);
		}
		else if (c == ')' || c == ']' || c == '}' ){
			if (pila.size() == 0) {
				bien = false;
			}
			else {
				aux = pila.top();
				if (c == ')' && aux == '(') {
					pila.pop();
				}
				else if (c == ']' && aux == '[') {
					pila.pop();
				}
				else if (c == '}' && aux == '{') {
					pila.pop();
				}
				else {
					bien = false;
				}
			}
			
		}
		
		cin.get(c);
	}
	//cout << c;
	if (c != '\n' && c != '\r') {
		while (c != '\n' && c != '\r') {
			cin.get(c);
		}
	}
	if (pila.size() > 0) {
		bien = false;
	}

	if (bien) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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
