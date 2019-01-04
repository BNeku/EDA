#include <iostream>
#include <fstream>

using namespace std;

//P: {n>=0}
void resolver(long long int n){

	if (n > 0){
		cout << (n % 10);
		resolver(n / 10);
	}
}
//Q: {sum{0..[log n]+1} (n%10^k)*10^(n+1-k) }
//T(m) = 0 si n<= 0
//T(m) = T(m)
int main(){
	long long int n;

	while (cin >> n){

		if (n != 0){
			while (n % 10 == 0){
				n = n / 10;
			}
			resolver(n);
			cout << endl;
		}
		else{
			cout << "0" << endl;
		}
	}

	return 0;
}