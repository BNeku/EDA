#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> v, int &min, int &max, int &maxlong){
	min = 0, max = 0, maxlong = 0;
	int auxMax, auxMin = 0;

	for (auxMax = 0; auxMax < v.size(); auxMax++){
		if (v[auxMax] == 0){
			if (auxMax - auxMin > maxlong){
				min = auxMin;
				max = auxMax-1;
				maxlong = (max - min) + 1;
			}
			auxMin = auxMax + 1;
		}
	}

	if (auxMax - auxMin > maxlong){
		min = auxMin;
		max = auxMax-1;
		maxlong = (max - min) + 1;
	}
}

int main(){
	int casos, numeros;
	int min, max, longt;
	cin >> casos;

	for (int i = 0; i < casos; i++){
		//lectura
		cin >> numeros;
		vector<int> vNum(numeros);
		for (int i = 0; i < numeros; i++){
			cin >> vNum[i];
		}
		//llamada y resultado
		resolver(vNum, min, max, longt);
		if (longt > 0){
			cout << longt << " -> [" << min << "," << max<< "]" << endl;
		}
		else{
			cout << "SIGUE BUSCANDO" << endl;
		}
	}
	//system("PAUSE");

	return 0;
}