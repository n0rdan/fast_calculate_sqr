// sqr_mat.cpp : Defines the entry point for the console application.
// Программа для решения квадратных уравнений
#include <cmath>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	
	//------------------init------------------
	setlocale(LC_ALL, "Russian");
	float a, b, c, x1, x2, d;
	x2 = 0;
	x1 = 0;
	d = 0;
	bool is_x1_used, is_x2_used;
	is_x1_used = 0;
	is_x2_used = 0;
	
	if(argc>3) {
		a=atoi(argv[1]);
		b=atoi(argv[2]);
		c=atoi(argv[3]);
	} else {
	cout << "Добро пожаловать в программу для решение квадратных уравнений." << endl << "Введите первый коэфицент: ";
	cin >> a;
	cout << "Введите второй коэфицент: ";
	cin >> b;
	cout << "Введите третий коэфицент: ";
	cin >> c;
	}
	//----------------end_init----------------
	
	//---------output init. equation----------
	for(int i=0; i<80; i++) cout<<'#';
	cout << "Уравнение: ";
	if(a==1)cout<< "x\u00B2";
		else if(a==-1) cout<< "-x\u00B2";
			else cout<<a<<"x"<< "\u00B2";

	if(b>0) cout<<'+' << b;
		else cout<<b;
	cout << "x";
	if(c>0) cout<<'+' << c;
		else cout<<c;
	cout << "=0" << endl;
	//---------------end output---------------
	
	//---------main part, calculating---------
	if (!a && !b&&!c) {
		cout << "Корней бесконечно много!" << endl;	
		for(int i=0; i<80; i++) cout<<'#';
		return 0;
	}
	if (a || b ) {
		if (!a&&b) {
			x1 = -c / b;
			is_x1_used = 1;
		} else if (!b && (-c / a>0)) {
			x1 = sqrt(-c / a);
			x2 = -sqrt(-c / a);
			is_x1_used = 1;
			is_x2_used = 1;
		} else if (!c) {
			x1 = 0;
			x2 = -b / a;
			is_x1_used = 1;
			is_x2_used = 1;
		} else {
			d=b*b - 4 * a*c;
			if(d>=0){
				x1 = (-b + sqrt(d)) / 2 * a;
				x2 = (-b - sqrt(d)) / 2 * a;
				is_x1_used = 1;
				is_x2_used = 1;
			}
		}
	}
	
	//--------------output result--------------
	cout << endl << endl;
	if (is_x1_used) cout << "Результат x1: " << x1<<endl;
	if(x1!=x2 && is_x2_used) cout << "Результат x2: " << x2<<endl;
	if (!is_x1_used && !is_x2_used) cout << "Решений нет" << endl;
	for(int i=0; i<80; i++) cout<<'#';
    	
	return 0;
}
