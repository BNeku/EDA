#include <iostream>
#include <fstream>

using namespace std;

const int BASE = 6;

void resolver(int n){

	if (n>= BASE){
		resolver(n/BASE);
	}

	cout << n % BASE;

}

int main(){
	int numCasos,n;

	cin >> numCasos;

	while (numCasos > 0){
		cin >> n;
		resolver(n);
		cout<< endl;;
		numCasos--;
	}
	return 0;
}