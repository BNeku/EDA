#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Fecha.h"
#include <map>
using namespace std;

using paciente = string;
using medico = string;

class Consultorio{
	unordered_map<medico, map<fecha, paciente>> lista_medicos;

public:

	void nuevoMedico(medico m){

		if (lista_medicos.count(m) == 0){//si no existe
			lista_medicos.insert({ m, {} });
		}
	}

	void pideConsulta(paciente p, medico m, fecha f){

		if (lista_medicos.count(m) == 0)
			throw domain_error("Medico no existente");
	
		if (lista_medicos[m].count(f) > 0)
			throw domain_error("Fecha ocupada");
		
		lista_medicos[m].insert({ f, p });
	}

	paciente siguientePaciente(medico m){

		if (lista_medicos.count(m) == 0)
			throw domain_error("Medico no existente");

		
		auto it = lista_medicos[m].begin();

		if (it == lista_medicos[m].end())
			throw domain_error("No hay pacientes");

		return it->second;
	}

	void atiendeConsulta(medico m){
		if (lista_medicos.count(m) == 0)
			throw domain_error("Medico no existente");


		auto it = lista_medicos[m].begin();

		if (it == lista_medicos[m].end())
			throw domain_error("No hay pacientes");

		lista_medicos[m].erase(it);
	}

	vector<pair<paciente, fecha>> listaPacientes(medico m, int dia){

		if (lista_medicos.count(m) == 0)
			throw domain_error("Medico no existente");

		map<fecha,paciente> citas = lista_medicos[m];
		vector<pair<paciente,fecha>> lista_pacientes;

		for (auto const &i : citas){
			if (i.first.getDia() == dia)
				lista_pacientes.push_back({i.second, i.first});
		}
		
		return lista_pacientes;
	}
};