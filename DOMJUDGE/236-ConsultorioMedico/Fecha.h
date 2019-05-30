#include <iostream>
#include <fstream>
using namespace std;

class fecha{
private:
	int _dia, _hora,_minuto;
public:
	fecha(){}

	fecha(int d, int h, int m){
		_dia = d;
		_hora = h;
		_minuto = m;
	}

	int getDia()const{
		return _dia;
	}
	int getHora()const{
		return _hora;
	}
	int getMinuto()const{
		return _minuto;
	}

	bool operator < (const fecha &f)const{
		if (_dia < f._dia){
			return true;
		}else if(_dia == f._dia){
			if (_hora < f._hora){
				return true;
			}
			else if (_hora == f._hora){
				if (_minuto < f._minuto){
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	bool operator == (const fecha &f)const{

		if (_dia == f._dia && _hora == f._hora && _minuto == f._minuto)
			return true;
		return false;
	}

	void printHora()const{
		if (_hora == 0){
			cout << "00";
		}
		else if (_hora < 10){
			cout << "0" << _hora;
		}else{
			cout << _hora;
		}

		cout << ":";

		if (_minuto == 0){
			cout << "00";
		}
		else if (_minuto < 10){
			cout << "0" << _minuto;
		}else{
			cout << _minuto;
		}
	}
};