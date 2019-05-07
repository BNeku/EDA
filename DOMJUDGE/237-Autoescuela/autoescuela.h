#ifndef AUTOESCUELA_H

#include <iostream>
#include <stdexcept>
#include <string>

#include "hashmap_eda.h"
#include "set_eda.h"

using namespace std;

using alumno = string;
using profesor = string;

class autoescuela {
private:
	unordered_map<alumno, pair<profesor, int>> alumnos;
	unordered_map<profesor, set<alumno>> profesores; //el set<alumno> es ordenado
public:

	autoescuela(){}

	void alta(const alumno &a, const profesor &p){
		auto itA = alumnos.find(a);
		
		//se podria hacer alumnos.count(a) == 0
		if (itA == alumnos.end()) {//si no existe el alumno

			alumnos.insert({ a,{p,0} });//lo inserto
			//los corchetes te devuelven la segunda parte si existe, y si no existe lo crea y te devuelve la segunda parte vacia
			//el insert del set lo inserta ordenadamente
			profesores[p].insert(a);
		}
		else {//si existe el alumno, hay que cambiarle de profesor

			/*si lo hacemos con count, no tenemos el itA asi que se accederia asi
				profesores[alumnos[a].first].erase(a);
				alumnos[a].first = p;
				profesores[p].insert(a);
			*/
			

			//borramos el alumno en el anterior profesor
			profesores[itA->valor.first].erase(a);
			itA->valor.first = p;
			profesores[p].insert(a);
		}
		
	}

	vector<alumno> examen(const profesor &p, int n) {
		vector<alumno> v;

		auto itP = profesores.find(p);

		if (itP != profesores.end()) {
			for (alumno const &a : itP->valor) {
				if (alumnos.at(a).second >= n) {
					v.push_back(a);
				}
			}
		}

		return v;
	}

	bool es_alumno(const alumno &a, const profesor &p){

		if (alumnos[a].first == p){
			return true;
		}
		else{
			return false;
		}
	}

	int puntuacion(const alumno &a){

		if (alumnos.count(a) > 0){//si el alumno existe
			return alumnos[a].second;
		}
		else{
			throw domain_error("ERROR");
		}
	}

	void actualizar(const alumno &a, int n){

		if (alumnos.count(a) > 0){//si existe

			alumnos[a].second += n;
		}
		else{
			throw domain_error("ERROR");
		}
	}

	void aprobar(const alumno &a){

		if (alumnos.count(a) > 0){//si existe

			profesor p = alumnos[a].first;

			//lo borramos de la lista de la tabla de los profesores
			profesores[p].erase(a);
			//lo borramos de la tabla de alumnos
			alumnos.erase(a);

		}
		else{
			throw domain_error("ERROR");
		}
	}
};

#endif // !AUTOESCUELA_H
#pragma once
