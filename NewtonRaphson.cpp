#include <iostream>
#include <cmath>

double f(double x){
    //return x*x - 5;
    return pow(x,3) + 3*x + 2;
}
double f_prima(double x){ // derivacion numerica -> caso base
    double h=1e-6;
    return ( f(x + h) - f(x) )/h; // se busca emular la definición de derivada con limite
}
double mNewtonRaphson(double x){
    return x - f(x)/f_prima(x);
}
void iteracion(double x=1){
    int i =0;
    double tolerancia = 1e-5, x_n, x_tmp=x;
    while(fabs(x-x_n) >= tolerancia){
        x = x_tmp;
        x_n = mNewtonRaphson(x);
        x_tmp = x_n;
        std::cout << i << "\t" << x << "\t" << x_n << "\n";
        i++;
    }
}


/*long double mNewtonRaphson(double x=1, double a=1){
    return x - (x*x - a)/(2*x);
}
*/

int main(){
    iteracion(1);
    return 0;
}