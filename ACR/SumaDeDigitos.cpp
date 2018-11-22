#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int resolver(int n){
	int suma = 0;

	if (n < 10){
		cout << n;
		return n;
	}
	else{
		suma = resolver(n / 10) + n%10;
		cout << " + " << n%10; 
		return suma;
	}

}

int main(){
	int n;
	cin >> n;
	while (n>=0){
		cout << " = " << resolver(n) << endl;
		cin >> n;
	}

	return 0;
}