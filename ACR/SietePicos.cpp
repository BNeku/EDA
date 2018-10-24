#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int resolverProblema(vector<int> v){
	int picos = 0;

	if (v[v.size() - 1] > v[v.size() - 2] && v[v.size() - 1] > v[0])
		picos++;
	if (v[v.size() - 1] < v[0] && v[0] > v[1])
		picos++;

	for (int i = 1; i < v.size()-1; i++){
		if (v[i - 1] < v[i] && v[i] > v[i + 1])
			picos++;
	}
	
	return picos;
}

int main(){
	int alturas;

	cin >> alturas;
	while (alturas != 0){
		vector<int> v(alturas);

		for (int i = 0; i < alturas; i++){
			cin >> v[i];
		}
		cout << resolverProblema(v)<<endl;
		cin >> alturas;
	}

	return 0;
}