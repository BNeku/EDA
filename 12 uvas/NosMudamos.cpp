//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



bool resuelveCaso(vector<int> g, vector<int> a) {
	bool caben = true;



	return caben;
}

int main() {
	int numGrupos, numAulas;
	// Resolvemos
	while (cin >> numGrupos) {
		cin >> numAulas;
		if (numGrupos > numAulas){
			cout << "NO" << endl;
		}
		else{
			vector<int> tamGrupo(numGrupos);
			vector<int> tamAula(numAulas);
			for (int i = 0; i < numGrupos; i++){
				cin >> tamGrupo[i];
			}
			for (int i = 0; i < tamAula.size(); i++){
				cin >> tamAula[i];
			}
			if (resuelveCaso(tamGrupo, tamAula)){
				cout << "SI" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		
		cin >> numGrupos;
	}

	return 0;
}