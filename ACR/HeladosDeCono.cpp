#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void resolver(vector<int> v, string aux, bool &primer){
	//chocolate vainilla

	if (v[0]==0 && v[1]==0){
		if (primer){
			cout << aux;
			primer = false;
		}
		else{
			cout << " " << aux;
		}
		
	}
	else{
		if (v[0] > 0){
			aux += "C";
			v[0]--;
			resolver(v, aux, primer);
			v[0]++;
			aux.pop_back();
		}
		if (v[1] > 0){
			aux += "V";
			v[1]--;
			resolver(v, aux, primer);
			v[1]++;
			aux.pop_back();
		}
	}


}

int main(){
	int numCasos,n,cont=2;
	vector<int> v;
	bool prim = true;
	string aux="";
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++){
		while (cont>0){
			cin >> n;
			v.push_back(n);
			cont--;
		}
		if (v.size() > 0){
			resolver(v, aux, prim);
			cout << endl;
		}
		cont = 2;
		aux = "";
		prim = true;
		v.clear();
	}

	return 0;
}