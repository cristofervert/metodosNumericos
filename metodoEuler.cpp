#include <iostream>
#include <cmath>

double f(double x, double y){
    double resultado = 3*x*x*y;
    return resultado;
}

double metodoEuler(double x0, double xf, double y0, double h=0.2){
    double resultado;
    double x = x0, y = y0;
    int n = (int) (xf - x0)/h;
    
    for(int i = 0; i<n ; i++){
        resultado = y + h*f(x,y);
        x += h;
        y = resultado;
        std::cout << x << "\t\t" << y << "\n"; // visual
    }

    
    return resultado;
}

int main(){
    double x0 = 0.0, y0 = 3.0, xf = 1.0;
    metodoEuler(x0, xf, y0);
    return 0;
}