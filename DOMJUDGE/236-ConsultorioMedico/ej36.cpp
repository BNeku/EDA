// Nerea jimenez Gonzalez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Consultorio.h"

using namespace std;

bool resuelveCaso() {
	int n;

	cin >> n;

	if (!std::cin)  // fin de la entrada
		return false;

	string operacion, medi, paci;
	Consultorio lista;
	int dia, hora, min;
	fecha f;

	for (int i = 0; i < n; i++){
		cin >> operacion;

		try{
			if (operacion == "nuevoMedico"){
				cin >> medi;
				lista.nuevoMedico(medi);
			}
			else if (operacion == "pideConsulta"){
				cin >> paci >> medi >> dia >> hora >> min;
				f = fecha(dia, hora, min);
				lista.pideConsulta(paci, medi, f);
			}
			else if (operacion == "siguientePaciente"){
				cin >> medi;
				paciente p = lista.siguientePaciente(medi);
				cout << "Siguiente paciente doctor " << medi << "\n" << p << endl;
				cout << "---" << endl;

			}
			else if (operacion == "atiendeConsulta"){
				cin >> medi;
				lista.atiendeConsulta(medi);
			}
			else if (operacion == "listaPacientes"){
				cin >> medi >> dia;
				auto lista_pac = lista.listaPacientes(medi, dia);

				cout << "Doctor " << medi << " dia " << dia << endl;
				for (const auto &i : lista_pac){
					cout << i.first << " ";
					i.second.printHora();
					cout << endl;
				}
				cout << "---" << endl;
			}
		}
		catch (domain_error e){
			cout << e.what() << endl;
			cout << "---" << endl;
		}
	}
	cout << "------" << endl;
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_36.txt");
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
