#include <iostream>
#include <fstream>

using namespace std;
const long long int K = 31543;

//P: n>=0
long long int resolver(long long int x, long long int n){
	long long int rdo;
	bool impar = false;
	
	if (n == 0){
		return 1;
	}else if (n == 1){
		return x%K;
	}
	else{
		if (n % 2 ==1){
			n--;
			impar = true;
		}

		rdo=resolver(x, n / 2);
		rdo = (rdo*rdo)%K;

		if (impar)
			rdo = (rdo*(x%K))%K;
		
	}
	
	return rdo;
}
//Q: rdo= (x^n%K * (x^n-1)%K )%K
//Coste :
/*
T(n) = c0  si n = {0,1}
T(n) = T(n/2^k)+ k*c0 si n>1

Pertenece al O(log n)
*/

int main(){
	long long int x, n;

	cin >> x >> n;
	while (x != 0 || n != 0){
		cout << resolver(x,n) << endl;
		cin >> x >> n;
	}
	return 0;
}