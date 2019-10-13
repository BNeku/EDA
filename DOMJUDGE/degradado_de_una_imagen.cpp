/*
	requisitos de implementacion:
	-Indicar la recurrencia utilizada para el calculo del coste y el coste de la solucion obtenida
	-La solucion obtenida deber emplear la tecnica de divide y venceras. ok
	-La funcion que resuelve el problema debe recibir los datos de una fila en un vector y comprobar si es un degradado, se pueden utilizar parametros auxiliares para tratar la recursion. ok

	Recursion (para cada fila individualmente):
	caso base: si solo estoy tratando dos numeros , devuelo si el primero es menor que el segundo.
	si no:
			parto el vector en dos
			devuelvo suma1 < suma2
			y ejecuto solve sobre cada una de las partes, hasta llegar al caso base.

	el coste de esta funcion recursiva es lineal.

*/
#include <iostream>
#include <vector>

struct tSol{
	bool cumple;
	int suma;
};

tSol solve(std::vector<int> &v, int i, int j){

	//debug to know with what elements i am dealing and visualize the recursion:
	/*
	std::cout << "Debug[v]{" ;
	for(int x = i; x < j; x++){
		std::cout << v[x] << " ";
	}
	std::cout << "}" << std::endl;
	*/
	if(j-i == 1){
		return {1, 0};
	}

	if(j-i == 2){
		tSol s;
		s.suma = v[i] + v[j-1];
		s.cumple = v[i] < v[j-1];
		return s;
	}
	else{
		//calculate the middle index
		int middle = (i+j) / 2;
		//recursive calls:
		tSol a = solve(v, i, middle);
		tSol b = solve(v, middle, j);

		tSol s;
		s.suma = a.suma + b.suma;
		s.cumple = a.cumple && b.cumple && a.suma < b.suma;
		//std::cout << "DEBUG[s1][s2] " << a.suma << " " << b.suma << std::endl;
		return s;
	}

}

int main(){
	//custom template
	int a, b;
	while(std::cin >> a >> b){
		std::vector<std::vector<int>> v;
		for(int i = 0; i < a; i++){
			std::vector<int> w;
			for(int j = 0; j < b; j++){
				int aux;
				std::cin >> aux;
				w.push_back(aux);
			}
			v.push_back(w);
		}
		/*
		for(int i = 0; i < v.size(); i++){
			for(int j = 0; j < v[i].size(); j++){
				std::cout << v[i][j] << " ";
			}
			std::cout << std::endl;
		}*/
		tSol s = {true, 0};
		for(int i = 0; i < a && s.cumple; i++){
			//std::cout << "ola" << std::endl;
			s = solve(v[i], 0, v[i].size());
		}
		if(s.cumple) std::cout << "SI" << std::endl;
		else std::cout << "NO" << std::endl;

	}
	return 0;
}
