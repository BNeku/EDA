//NEREA JIMÉNEZ GONZÁLEZ


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "hashmap_eda.h"
using namespace std;

class carnet_puntos{
private:
	unordered_map<string, int> conductores;
	vector<int> por_puntos;
public:
	//constructor
	carnet_puntos() : por_puntos(16){
		//inicializar vector, por defecto suele estar inicializado
	};

	void nuevo(string dni){
		//pregunto cuantas veces está el dni que me pasan, de forma que si es mayor que 0 lanzamos excepcion
		if (conductores.count(dni) > 0)
			throw domain_error("Conductor duplicado");
		
		//cuando insertamos siempre tienen los 15 puntos
		conductores.insert({ dni, 15 });
		por_puntos[15]++;
		
	}

	void quitar(string dni, int puntos){

		//si no existe el conductor se lanza excepcion
		if (conductores.count(dni) == 0)
			throw domain_error("Conductor inexistente");
		
		por_puntos[conductores[dni]]--;

		conductores[dni] = conductores[dni] - puntos;


		if (conductores[dni] < 0){
			conductores[dni] = 0;
		}

		por_puntos[conductores[dni]]++;
	}

	int consultar(string dni){

		if (conductores.count(dni) == 0)
			throw domain_error("Conductor inexistente");

		return conductores[dni];

	}

	int con_cuantos_puntos(int puntos){

		if (puntos < 0 || puntos > 15)
			throw domain_error("Puntos no validos");

		return por_puntos[puntos];

	}

};

bool resuelveCaso() {
	string aux;
	int puntos;
	carnet_puntos carnets;

	cin >> aux;

	if (!cin)
		return false;

	while (aux != "FIN"){
		if (aux == "nuevo"){
			cin >> aux;
			try{
				carnets.nuevo(aux);
			}
			catch (domain_error e){
				cout << "ERROR: " << e.what() <<endl;
			}
		}
		else if (aux == "cuantos_con_puntos"){
			cin >> puntos;
			try{
				cout << "Con " << puntos << " puntos hay " << carnets.con_cuantos_puntos(puntos) << endl;
			}
			catch (domain_error e){
				cout << "ERROR: " << e.what() << endl;
			}
		}
		else if (aux == "quitar"){
			cin >> aux >> puntos;
			try{
				carnets.quitar(aux, puntos);
			}
			catch (domain_error e){
				cout << "ERROR: " << e.what() << endl;
			}
		}
		else if (aux == "consultar"){
			cin >> aux;
			try{
				cout << "Puntos de " << aux << ": " << carnets.consultar(aux) << endl;
			}
			catch (domain_error e){
				cout << "ERROR: " << e.what() << endl;
			}
		}

		cin >> aux;
	}

	cout << "---" << endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos2_34.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif



	// Resolvemos
	while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}