#include <iostream>
#include <cmath>

double f(double x){
    double resultado = pow(x,3) + 2*x*x; 
    return resultado;
}
// derivada  = 3x^2 + 4x
// x = 1 -> 7

double f_prima_E(double x){ // hacia enfrente
    double h = 0.1;
    double derivada = (f(x + h) - f(x))/h;
    return derivada; 
}

double f_prima_A(double x){ // hacia atrás
    double h = 0.1;
    double derivada = (f(x) - f(x - h))/h;
    return derivada; 
}

double f_prima_C(double x){ // centrada
    double h = 0.1;
    double derivada = (f(x + h) - f( x - h ))/(2*h);
    return derivada; 
}

int main(){
    double f1,f2,f3,r=7; // r es el resultado analítico
    f1 = f_prima_A(1);
    f2 = f_prima_E(1);
    f3 = f_prima_C(1);
    // se puede usar el error absoluto porque se tiene resultado analitico
    std::cout << "Atras: " << f1 << "\t" << fabs((r-f1)/r) << "\n";
    std::cout << "Enfrente: " << f2 << "\t" << fabs((r-f2)/r) << "\n";
    std::cout << "Centrada: " << f3 << "\t" << fabs((r-f3)/r) << "\n";

    return 0;
}