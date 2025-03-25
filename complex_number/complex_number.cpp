#include <iostream>
#include <fstream>
#include "complex_number.hpp"



int main() {
	double a = 3.5;
	double b = -17.12;
	double c = 4.0;
	double d = 13.1;
	complex_number<double> x(a,b);
	std::cout << "x è uguale a " <<x << std::endl;
	complex_number<double> y(c,d);
	std::cout << "y = " << y << std::endl;
	std::cout <<"x+=y : " << (x+=y) << std::endl;
	std::cout <<"x+y = " << x+y << std::endl;
	complex_number<double> z = x.coniugato();
	std::cout <<"x coniugato :" << z << std::endl;
	std::cout << "x*=y : " << (x*=y) << std::endl;
	std::cout << "x*y= " << x*y << std::endl;
	return 0;
}