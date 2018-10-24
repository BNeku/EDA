#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool resolver(int D, vector<int> v){
	bool apto = true;
	int aux = v[0], cota;

	for (int i = 0; i < v.size()-1 && apto; i++){
		if (v[i] > v[i + 1]){
			if ((v[i] - aux) > D)
				apto = false;
			aux = v[i + 1];
		}
		else if (v[i] == v[i + 1]){
			if ((v[i + 1] - aux) > D)
				apto = false;
			aux = v[i + 1];
		}
		else{
			if ((v[i + 1] - aux) > D)
				apto = false;
		}

	}

	return apto;
}

int main(){
	int D, N;


	while (cin >> D){
		cin >> N;
		vector<int> cotas(N);

		for (int i = 0; i < N; i++){
			cin >> cotas[i];
		}

		if (resolver(D, cotas)){
			cout << "APTA" << endl;
		}
		else{
			cout << "NO APTA" << endl;
		}
	}

	return 0;
}