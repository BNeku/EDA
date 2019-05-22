#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class polinomio{
private:
	vector<int> p;
public:

	//la posicion del vector indicará el grado y el número en esa posicion el coeficiente
	

	polinomio(){
		
		for (int i = 0; i < 9; i++){
			p.push_back(0);
		}
	}

	void insert(int c, int g){

		if (c != 0 || g != 0)
			p[g] += c;
		
	}

	int calcular(int valor){
		int total = p[0];

		for (int i = 1; i < p.size(); i++){
			total += p[i] * pow(valor,i);
		}

		return total;
	}
};


#endif //POLINOMIO_H