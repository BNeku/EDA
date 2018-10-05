//NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
using namespace std;


int main() {
	long int nToros;
	long int speedT;
	long int max=0;

	cin >> nToros;
	while (cin){
		
		for (int i = 0; i < nToros; i++){
			cin >> speedT;
			if (max < speedT)
				max = speedT;
		}
		
		//Escribir resultado
		cout << max << endl;
		max = 0;
		cin >> nToros;
	}

	//system("pause");
	return 0;
}