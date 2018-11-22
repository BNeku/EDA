#include <iostream>
#include <fstream>

using namespace std;

int resolver(int n){
	int suma = 0;
	if (n == 1){
		return 4;
	}
	else{
		suma =resolver(n/2);
		suma = suma * 4;
		suma += 4 * n;
	}

	return suma;
}

int main(){
	int n, suma=0;

	while (cin >> n){
		cout << resolver(n) << endl;
		suma = 0;
	}

	return 0;
}