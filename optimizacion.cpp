#include <iostream>
#include <cmath>
#define ITERACIONES 50

double f(double x){
	return x*x + 2*x + 1;
}

double f_prima(double x){
	double h=1e-6, resultado=0;
	resultado = ( f(x+h) - f(x) )/ h;
	return resultado;
}

double f_biprima(double x){
	double h=1e-6, resultado= 0;
	resultado = ( f(x+h) - 2*f(x) + f(x-h) )/h*h;
	return resultado;
}

double relacion(double x){ // forma provisional
	double h = 1e-6, resultado=0;
	resultado = ((f(x+h) - f(x))*h)/(f(x+h) - 2*f(x) + f(x-h));
	return resultado;
}

double optimizacion(double x=0, double tolerancia=1e-6){
	double x_n=0, x_tmp=x;
	int i = 0;
	while(i < ITERACIONES || fabs( x_n - x) > tolerancia){
		x = x_tmp;
		x_n = x - f_prima(x)/f_biprima(x);
		x_tmp = x_n;
		std::cout << i << "\t" << x << "\t" << x_n << "\t" << fabs( x_n - x) << "\n";
		i++;
	}
	return x_n;
}

int main(){
	std::cout << "Optimizacion con Newton Raphson\n";
	optimizacion(-2);
	return 0;
}









