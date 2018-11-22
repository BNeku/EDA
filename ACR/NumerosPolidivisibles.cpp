#include <iostream>
#include <fstream>

using namespace std;

bool resolver(long long int n, int &cont){
	bool poli = true;

	//CB:solo queda una cifra
	if (n < 10){
		if (n % cont != 0)
			return false;
		return true;
	}else if (n >= 10){
		poli = resolver(n/10, cont);
		cont++;
		if (n%cont != 0 || !poli)
			poli = false;
	}

	return poli;
}

int main(){
	long long int n;
	int cont=1;

	while (cin >> n){
		if (resolver(n,cont)){
			cout << "POLIDIVISIBLE" << endl;
		}
		else{
			cout << "NO POLIDIVISIBLE" << endl;
		}
		cont = 1;
	}
	return 0;
}