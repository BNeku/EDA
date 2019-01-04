#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int divisionEntera(int x, int d) {
	int r = 0, c;
	c = x / d;
	r = x - (d*c);

	if (r > 0) {
		c++;
	}
	return c;
}

int totalP(const vector<int> &v, const int &p) {
	int total = 0, c;

	for (int i = 0; i < v.size(); i++) {

		c=divisionEntera(v[i], p);
		total += c;

	}

	return total;
}



int encontrarMax(vector<int> v) {
	int max = v[0];

	for (int i = 0; i < v.size(); i++) {
		if (max < v[i])
			max = v[i];
	}

	return max;
}


int resolver(int partituras, const vector<int> &v, int min, int max){
	int maxG=0, m;

	m = (min + max) / 2;

	if (min == max){
		maxG = max;

	}else if (totalP(v, m) <= partituras) {

		maxG = resolver(partituras, v, min, m);
	}
	else if(totalP(v,m) > partituras){

		maxG = resolver(partituras, v, m+1, max);
	}
		
	return maxG;
}

int main(){
	int n, m,cont, grupo;

	while (cin>>n){
		cin >> m;
		cont = 0;
		vector<int> v(m);
		for (int i = 0; i < m; i++){
			cin >> v[i];
		}
		grupo = v[0];
		cout << resolver(n, v, 1, encontrarMax(v))<<endl;
	}
	return 0;
}