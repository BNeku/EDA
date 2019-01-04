//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso(vector<char> v) {
	int contN=0, contG=0;

	for (int i = 0; i < v.size(); i++){
		if (v[i] == 'N'){
			contN++;
		}
		else{
			contG++;
		}
	}
	//si son pares
	if (v.size() % 2 == 0){
		
		if (contN % 2 == 0 && contN % 2 == 0){
			cout << "EMPAREJADOS" << endl;
		}
		else{
			cout << "PAREJA MIXTA" << endl;
		}
	}//si son impares
	else{
		if (contN % 2 == 1){
			cout << "NEGRO SOLITARIO" << endl;
		}
		else{
			cout << "GRIS SOLITARIO" << endl;
		}
	}

}

int main() {
	char calcetin;
	cin >> calcetin;
	// Resolvemos
	while (calcetin != '.'){
		vector<char> v;
		v.push_back(calcetin);
		while (calcetin != '.'){
			cin >> calcetin;
			v.push_back(calcetin);
		}
		v.pop_back();
		resuelveCaso(v);
		cin >> calcetin;
	}
	
	return 0;
}