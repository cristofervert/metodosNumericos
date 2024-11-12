#include <iostream>
#include <cmath> 
#define ITERACIONES 100

double raiz(double x){
    int i=0;
    double x_n, x_tmp=x, tolerancia = 1e-6;
    while(fabs(x_n-x) > tolerancia){
        x = x_tmp;
        x_n = 0.5*(x + 2/x); // 
        x_tmp = x_n;
        std::cout << i << "\t" << x << "\t" << x_n << "\t" << fabs(x_n-x) << "\n";
        i++;
    }
    return x_n;
}

int main(){
    long valor;
    std::cout << "Ingrese un valor: ";
    std::cin >> valor;
    raiz(valor);
    return 0;
}