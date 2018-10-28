#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool resolver(int &pos, vector<int> v){
	bool bocadillo = false;
	int tapa=v[0], suma=0;
	//posicion i mayor o igual que la suma de todos los de su dcha

	for (int i =1; i < v.size(); i++){
		suma += v[i];
	}
	for (int i = 0; i < v.size()-1; i++){

		if (v[i] == suma && !bocadillo){
			bocadillo = true;
			pos = i+1;
			tapa = v[i];
		}
		if (bocadillo && v[i] == suma){
			if (v[i] > tapa){
				tapa = v[i];
				pos = i+1;
			}
		}

		suma -= v[i+1];
	}

	return bocadillo;
}

int main(){
	int cortezas;
	int pos;

	cin >> cortezas;

	while (cortezas != 0){
		vector<int> vCor(cortezas);
		for (int i = 0; i < cortezas; i++){
			cin >> vCor[i];
		}
		if (resolver(pos, vCor)){
			cout << "SI" << " " << pos << endl;
		}
		else{
			cout << "NO" << endl;
		}
		cin >> cortezas;
	}
	return 0;
}