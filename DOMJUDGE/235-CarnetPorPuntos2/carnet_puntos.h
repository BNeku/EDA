#ifndef CARNET_PUNTOS

#include <list>
#include <string>
#include "hashmap_eda.h"

using namespace std;

using DNI = string;

class carnet_puntos{

private:
	typedef struct{
		int puntos;
		list<DNI> ::iterator itLista;
	} infoConductor;

	unordered_map<DNI, infoConductor> conductores;
	unordered_map<int, list<DNI>> por_puntos;

public:
	void nuevo(DNI c){

		if (conductores.count(c) > 0)
			throw domain_error("Conductor duplicado");

		por_puntos[15].push_front(c);
		conductores[c].puntos = 15;
		conductores[c].itLista = por_puntos[15].begin();
	}

	void quitar(DNI c, int p){

		if (conductores.count(c) == 0)
			throw domain_error("Conductor inexistente");

		infoConductor &par = conductores[c];
		int nuevosPtos = conductores[c].puntos - p;

		if (nuevosPtos < 0){
			nuevosPtos = 0;
		}

		if (nuevosPtos != par.puntos){

			por_puntos[par.puntos].erase(par.itLista);
			por_puntos[nuevosPtos].push_front(c);
			conductores[c].puntos = nuevosPtos;
			conductores[c].itLista = por_puntos[nuevosPtos].begin();
		}
	}

	void recuperar(DNI c, int p){

		if (conductores.count(c) == 0)
			throw domain_error("Conductor inexistente");

		int total = conductores[c].puntos + p;
		total = min(total, 15);

		if (total != conductores[c].puntos){

			por_puntos[conductores[c].puntos].erase(conductores[c].itLista);
			por_puntos[total].push_front(c);
			conductores[c].puntos = total;
			conductores[c].itLista = por_puntos[total].begin();
		}
	}

	int consultar(DNI c){
		if (conductores.count(c) == 0)
			throw domain_error("Conductor inexistente");

		return conductores[c].puntos;
	}

	int cuantos_con_puntos(int p){
		if (p > 15)
			throw domain_error("Puntos no validos");


		return por_puntos[p].size();
	}

	list<DNI> lista_por_puntos(int p){
		if (p > 15)
			throw domain_error("Puntos no validos");

		return por_puntos[p];
	}
};

#endif