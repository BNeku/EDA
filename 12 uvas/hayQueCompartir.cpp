//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


typedef struct fraccion{
	int a;
	int b;
};

int minimoComun(vector<fraccion> v){
	int mcm = 1;

	for (int i = 0; i < v.size()-1; i++){
		for (int j = i+1; j < v.size(); j++){
			if (v[i].b == v[j].b){
				v[j].b = 1;
			}
			else{
				if (v[i].b%v[j].b == 0 || v[j].b%v[i].b == 0){
					if (v[i].b > v[j].b){
						v[j].b = 1;
					}
					else{
						v[i].b = 1;
					}
				}
			}
		}
	}

	for (int k = 0; k < v.size(); k++){
		mcm = mcm*v[k].b;
	}

	return mcm;
}

void resuelveCaso(const vector<fraccion> &v) {
	int mcm = minimoComun(v);
	int suma = 0, aux;

	for (int i = 0; i < v.size(); i++){
		aux = mcm / v[i].b;
		suma += v[i].a*aux;
	}
	cout << mcm - suma << endl;
}

int main() {
	int num;
	double aux, aux1;
	char trash;
	cin >> num;
	// Resolvemos
	while (num!=0) {
		vector<fraccion> v(num);
		for (int i = 0; i < num; i++){
			cin >> v[i].a;
			cin.get(trash);
			cin >> v[i].b;
		}
		resuelveCaso(v);
		cin >> num;
	}

	return 0;
}