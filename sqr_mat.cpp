// sqr_mat.cpp : Defines the entry point for the console application.
// Программа для решения квадратных уравнений
#include <cmath>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	
	//------------------init------------------
	setlocale(LC_ALL, "Russian");
	float a, b, c, x1, x2, d, z, y, k;
	x2 = 0;
	x1 = 0;
	d = 0;
	bool is_x1_used, is_x2_used, is_convert_possible, is_z_sqr;
	is_x1_used = 0;
	is_x2_used = 0;
	is_convert_possible=0;
	is_z_sqr = 0;
	if(argc>3) {
		a=atoi(argv[1]);
		b=atoi(argv[2]);
		c=atoi(argv[3]);
	} else {
	cout << "Добро пожаловать в программу для решения квадратных уравнений." << endl;
	cout<< "Введите первый коэффициент: ";
	cin >> a;
	cout << "Введите второй коэффициент: ";
	cin >> b;
	cout << "Введите третий коэффициент: ";
	cin >> c;
	}
	//----------------end_init----------------
	
	//---------main part, calculating---------
	if (a || b ) {
		if (!a && b) {
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
			if(d == 0){
				x1 = (-b + sqrt(d)) / 2 * a;
				is_x1_used = 1;
			} else if(d > 0){
				x1 = (-b + sqrt(d)) / 2 * a;
				x2 = (-b - sqrt(d)) / 2 * a;
				is_x1_used = 1;
				is_x2_used = 1;
			}
		}
	}
	if(a>0 && c>0 && b/2>=sqrt(a)) {
		is_convert_possible=1;
		z=sqrt(a);
		if((int)z!=z) {
			is_z_sqr = 1;
			z=a;
		}
		y=b*b/(4*c);
		k=c-y;
	}
	
	//---------output init. equation----------
	for(int i=0; i<80; i++) cout<<'#';
	cout << "Уравнение: ";
	if(a!=0) 
		if(a==1) cout<< "x\u00B2";
			else if(a==-1) cout<< "-x\u00B2";
				else cout<<a<<"x"<< "\u00B2";
	if(b!=0) {
		if(b==-1) cout<<'-';
		if(a!=0) 
			if(b>0) cout<<'+';
		if(b!=1&&b!=-1)
			if(b>0&&a!=0) cout<< b;
				else cout<<b;
		cout << "x";
	}
	if(c!=0)
		if((a!=0||b!=0)&&c>0) cout<<'+' << c;
			else cout<<c;
		else if(a==0&&b==0) cout<<c;

	cout << "=0" << endl;
	
	//--------------output result--------------
	if(is_convert_possible) {
		cout<<"Выражение можно преобразовать в: (";
		if(z!=1) {
			if(is_z_sqr) cout<<"\u221A";
			cout<<z;
		}
		cout<<'x';
		if(y!=0) 
			if(y>0) cout<<'+'<<y;
				else cout<<y;
		cout<<")\u00B2";
		if(k!=0)
			if(k>0) cout<<'+'<<k;
				else cout<<k;
		cout<<endl;
	}
	cout<<endl;
	if (!a && !b&&!c) cout << endl << "Корней бесконечно много!" << endl;
		else {
			if (is_x1_used) cout << "Результат x1: " << x1<<endl;
			if(x1!=x2 && is_x2_used) cout << "Результат x2: " << x2<<endl;
			if (!is_x1_used && !is_x2_used) cout << "Решений нет" << endl;
		}
	for(int i=0; i<80; i++) cout<<'#';
	return 0;
}
