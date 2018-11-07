#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int resolver(int a, vector<int> v){
	int k = 1, r = 1, s = 0;
	
	while (k < v.size()){
		if (v[k] - v[s] < a) r = fmax(r, k - s + 1);
		else while (v[k] - v[s] >= a)++s;
		++k;
	}

	return r;
}

int main(){
	int N, A;

	cin >> N;
	cin >> A;
	while (N != 0 && A != 0){
		vector<int> v(N);

		for (int i = 0; i < v.size(); i++){
			cin >> v[i];
		}
		cout << resolver(A, v)<<endl;
		cin >> N;
		cin >> A;
	}
	return 0;
}