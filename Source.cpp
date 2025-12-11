#include <iostream>
using namespace std;
#include "Fraction2.h"

/*Створіть клас Дріб (або використовуйте вже раніше створений вами). 
Використовуючи перевантаження операторів реалізуйте для нього арифметичні операції для роботи з дробами (операції +, -, *, /).*/

int main()
{
	
	Fraction f1{ 2,8 };

	Fraction f2{ 9,3 };


	cout << "f1 = "; 
	f1.print();
	cout << " f2 = "; 
	f2.print(); 
	cout << '\n';
	
	cout << "f1 + f2 = ";
	(f1 + f2).print();
	cout << '\n';
	
	cout << "f1 - f2 = "; 
	display_operation(f1, f2,'-');
	cout << '\n';
	
	cout << "f1 * f2 = "; 
	display_operation(f1, f2, '*');
	cout<< '\n';
	
	cout << "f1 / f2 = "; 
	(f1 / f2).print();
	cout<< '\n';
	

	return 0;
}
