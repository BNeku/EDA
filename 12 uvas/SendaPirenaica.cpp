//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<int> v) {
	int suma = 0;

	for (int i = 0; i < v.size(); i++){
		suma += v[i];
	}

	cout << suma;
	for (int i = 0; i < v.size()-1; i++){
		cout << " " << suma - v[i];
		suma -= v[i];
	}
	cout << endl;
}

int main() {
	int etapas;
	cin >> etapas;
	// Resolvemos
	while (etapas!=0) {
		vector<int> distancias(etapas);
		for (int i = 0; i < etapas; i++){
			cin >> distancias[i];
		}
		resuelveCaso(distancias);
		cin >> etapas;
	}
	return 0;
}