//NEREA JIMENEZ GONZALEZ


#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void resuelveCaso(string num) {
	int contador = num.size(), i = 0, j = num.size() - 1;;
	bool encontrado = false, seguir = true;
	
	//parte entera
	while(i < contador && num[i] != '.') {
		if (num[i] != '0') 
			encontrado = true;
		if (encontrado){
			cout << num[i];
		}else if (num[i] == '0' && num[i + 1] == '.') {
			encontrado = true;
			cout << "0";
		}
		i++;
	}

	if (!encontrado)
		cout << "0";
	//parte decimal
	if (num[i] == '.') {
		while ( (num[j] == '.' || num[j] == '0') && seguir){
			if (num[j] == '0' || num[j] == '.') 
				contador--;
			if (num[j] == '.') 
				seguir = false;
			j--;
		}
		for (int k = i; k < contador; k++) {
			cout << num[k];
		}
	}

	cout << endl;
}


int main() {
	string tiempo;

	while (cin >> tiempo){
		resuelveCaso(tiempo);
	}

	return 0;
}