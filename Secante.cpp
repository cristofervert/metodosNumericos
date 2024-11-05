#include <iostream>
#include <cmath>

double f(double x){
    //return x*x - 5;
    return pow(x,3) + 3*x + 2;
}
double mSecante(double x_i, double x_f){
    return x_f - f(x_f)*((x_f - x_i)/( f(x_f)- f(x_i)));
}
void iteracion(double x_i=1, double x_f=2){
    int i=0;
    double tolerancia = 1e-5, x_n;
    while(fabs(x_n-x_i) >= tolerancia){
        x_n = mSecante(x_i, x_f); // x2 = x0, x1
        x_i = x_f; // x0 -> x1
        x_f = x_n; // x1 -> x2
        std::cout << i << "\t" << x_i << "\t" << x_f << "\t" << x_n <<"\n";
        i++;
    }
}

/*long double mNewtonRaphson(double x=1, double a=1){
    return x - (x*x - a)/(2*x);
}
*/

int main(){
    iteracion(1,2);
    return 0;
}