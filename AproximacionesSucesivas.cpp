#include <iostream>
#include <cmath>
#define ITERACIONES 50 // 

double f(double x){
    return pow(x,3) + 3*x + 2; // función converge
    //return 3*x*x + x - 1; // función diverge
}

double g(double x){ // x = g(x)
    return (pow(x,3) + 2)/-3; 
    //return -3*x*x + 1;
}

long double aproximacionesSucesivas(long double x_n=0){
    int i=0;
    long double tolerancia = 1e-4, x_tmp = x_n, x_nf=0;
    do{
        x_n = x_tmp;
        x_nf = g(x_n);
        x_tmp = x_nf;
        std::cout << i << "\t" <<x_nf << "\n";
        i++;
    }while(fabs(x_nf-x_n) > tolerancia || i < ITERACIONES);
    return x_nf;
}

int main(){
    double val;
    std::cout << "Valor: ";
    std::cin >> val;
    aproximacionesSucesivas(val);
    return 0;
}