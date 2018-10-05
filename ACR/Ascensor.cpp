//NEREA JIMENEZ GONZALEZ

#include <iostream>
#include <fstream>
using namespace std;

void resuelveCaso(int posIni) {
	int nextPos, total = 0;

	cin >> nextPos;
	while (nextPos != -1){
		total += abs(nextPos - posIni);
		posIni = nextPos;
		cin >> nextPos;
	}

	cout << total << endl;
}


int main() {
	int posIni;

	cin >> posIni;
	while (posIni != -1 && posIni >=0){
		resuelveCaso(posIni);
		cin >> posIni;
	}

	//system("pause");
	return 0;
}