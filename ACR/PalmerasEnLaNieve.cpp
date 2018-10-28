#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int EN_PIE = 5;

int resolver(int nieve,vector<int> v){
	int pie=0, franja=0;
	int j=0, i=0;
	


	for (int n = v.size() - 1; n >= 0; n--){
		if (v[i] >= nieve){
			pie++;
			if (pie > EN_PIE){
				while ( pie > EN_PIE){
					if (v[j] >= nieve)
						pie--;
					j++;
				}
			}
		}

		if (franja < (i - j + 1))
			franja = i - j + 1;
		i++;


	}

	return franja;
}

int main(){
	int casos, nieve, npal;
	cin >> casos;

	for (int i = 0; i < casos; i++){
		cin >> nieve;
		cin >> npal;
		vector<int> pal(npal);

		for (int i = 0; i < npal; i++){
			cin >> pal[i];
		}
		cout << resolver(nieve,pal) << endl;
	}
	//system("PAUSE");

	return 0;
}