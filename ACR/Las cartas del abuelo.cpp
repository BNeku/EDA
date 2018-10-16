#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
//const int MAX_CARACTER = 1000000;
/*

void resolver(string cad, int inter){
	int min, max;

	for (int i = 0; i < inter; i++){
		cin >> min;
		cin.ignore();
		cin >> max;
		cin.ignore();

		if (min > max)
			swap(min, max);

		bool ok = true;
		int j = min;

		while ( j < max-1 && ok){
			if (cad[j] != ' ' )
					if (toupper(cad[j]) != toupper(cad[j + 1]))
						ok = false;
			j++;
		}

		if (ok){
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	cout << endl;

}

int main(){
	string cad;
	int intervalos;

	do{
		getline(cin, cad);
		cin >> intervalos;
		cin.ignore();
		if (intervalos!=0)
			resolver(cad, intervalos);
	} while (intervalos != 0);

	return 0;
	
}
*/

int AuxLinea[1000001];
int main()
{
	string Linea;
	while (getline(cin, Linea, '\n'))
	{
		int LonLinea = (int)Linea.size();
		AuxLinea[0] = 0;
		for (int i = 1; i<LonLinea; ++i) AuxLinea[i] = Linea[i] == Linea[i - 1] ? AuxLinea[i - 1] : i;

		int NumTest;
		scanf("%d", &NumTest);

		if (NumTest == 0) return 0;

		while (NumTest--)
		{
			int Inicio, Final;
			scanf("%d%d\n", &Inicio, &Final);

			if (Inicio>Final) swap(Inicio, Final);
			printf((AuxLinea[Final] <= Inicio ? "SI\n" : "NO\n"));
		}
		printf("\n");
	}
}