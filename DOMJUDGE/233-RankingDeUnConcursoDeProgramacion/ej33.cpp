#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 _______
|equipos|
|_______|

info_equipos							info_prob
	
string | Nº prob resueltos | tiempo
_______|___________________|________   _______fallos__resuelto_
eq1    |        2          |   240    |prob22 |  2    | true   |
									  |prob1  |  0    | false  |
eq2    |        3          |   180    --otra tabla igual


*/

struct info_prob{
	int fallos;
	bool resuelto;
};

struct info_equipo{
	int num_prob_resueltos = 0;
	int tiempo = 0;
	unordered_map<string, info_prob> problemas;
};

struct resultado{
	string nombre_equipo;
	int num_prob_resueltos;
	int tiempo;
	//se pueden definir operaciones dentro de structs !!! WTF EL FUTURO ES HOY
	bool operator < (resultado r){
		if (num_prob_resueltos > r.num_prob_resueltos){
			return true;
		}
		else if (num_prob_resueltos == r.num_prob_resueltos){
			if (tiempo < r.tiempo){
				return true;
			}
			else if (tiempo == r.tiempo){
				if (nombre_equipo < r.nombre_equipo){
					return true;
				}
				else{
					return false;
				}
			}else{
				return false;
			}
			
		}else{
			return false;
		}
	}
};

bool esCorrecto(const string &veredicto){

	if (veredicto != "AC"){
		return false;
	}
	else{
		return true;
	}
}

void resuelveCaso() {
	string nombre_equipo, nom_prob, veredicto;
	int tiempoTrans;
	unordered_map<string, info_equipo> equipos;

	cin >> nombre_equipo;

	while (nombre_equipo != "FIN"){
		cin >> nom_prob >> tiempoTrans >> veredicto;

		if (equipos.count(nombre_equipo) > 0){//si ya existe el equipo

			if (equipos[nombre_equipo].problemas.count(nom_prob) > 0){//si ya existe el problema en ese equipo
				if (!equipos[nombre_equipo].problemas[nom_prob].resuelto){//si no esta ya resuelto
					if (esCorrecto(veredicto)){
						equipos[nombre_equipo].num_prob_resueltos++;
						equipos[nombre_equipo].tiempo += tiempoTrans + 20 * (equipos[nombre_equipo].problemas[nom_prob].fallos);
						equipos[nombre_equipo].problemas[nom_prob].resuelto = true;
					}
					else{
						equipos[nombre_equipo].problemas[nom_prob].fallos++;
					}
				}
			}
			else{//si no existe el problema
				equipos[nombre_equipo].problemas.insert({ nom_prob, {} });

				if (esCorrecto(veredicto)){
					equipos[nombre_equipo].num_prob_resueltos++;
					equipos[nombre_equipo].tiempo += tiempoTrans;
					equipos[nombre_equipo].problemas[nom_prob].resuelto = true;
				}
				else{
					equipos[nombre_equipo].problemas[nom_prob].fallos++;
				}
			}

		}
		else{//si no existe el equipo
			if (esCorrecto(veredicto)){
				equipos.insert({ nombre_equipo, {} });
				equipos[nombre_equipo].num_prob_resueltos = 1;
				equipos[nombre_equipo].tiempo = tiempoTrans;
				equipos[nombre_equipo].problemas.insert({ nom_prob, {} });
				equipos[nombre_equipo].problemas[nom_prob].fallos = 0;
				equipos[nombre_equipo].problemas[nom_prob].resuelto = true;
			}
			else{
				equipos.insert({ nombre_equipo, {} });
				equipos[nombre_equipo].num_prob_resueltos = 0;
				equipos[nombre_equipo].problemas.insert({ nom_prob, {} });
				equipos[nombre_equipo].problemas[nom_prob].fallos = 1;
				equipos[nombre_equipo].problemas[nom_prob].resuelto = false;
			}

		}
	
		cin >> nombre_equipo;
	}



	//para ordenar
	vector<resultado> resultados;
	
	for (auto &e : equipos){
		resultados.push_back({ e.first, e.second.num_prob_resueltos, e.second.tiempo });
	}
		
	
	//poner el include algorithm
	sort(resultados.begin(), resultados.end());
	
	for (auto &r : resultados){
		cout << r.nombre_equipo << " " << r.num_prob_resueltos << " " << r.tiempo << endl;
	}
	cout << "----" << endl;
	
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos2_33.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
