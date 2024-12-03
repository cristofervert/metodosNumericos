#include <iostream>
#include <vector>

std::vector<double> regresionLineal(
    const std::vector<double>& x, 
    const std::vector<double>& y){
    
    int n = x.size();
    std::vector<double> coef = {0.0, 0.0};
    double x_avrg = 0.0, y_avrg = 0.0;
    double numerador = 0.0, denominador = 0.0;
    double b0 = 0.0, b1 = 0.0;

    for(int i=0; i<n ; i++){
        x_avrg += x[i];
        y_avrg += y[i];
    }
    x_avrg = x_avrg/n;
    y_avrg = y_avrg/n;
    
    for(int i=0; i<n; i++){
        numerador += (x[i] - x_avrg)*(y[i]-y_avrg); 
        denominador += (x[i] - x_avrg)*(x[i] - x_avrg); // desviacion estandar
    }

    b1 = numerador/denominador; 
    b0 = y_avrg - b1*x_avrg; // Error: lo estaba sumando b0 =  y_avrg + b1*x_avrg
    coef[0] = b0;
    coef[1] = b1;
    return coef;
}


// y = 2x + 1 
int main(){
    std::vector<double> x = {0.0, 1.0, 1.5, 2.0};
    std::vector<double> y = {1.0, 3.0, 3.5, 5.0};
    std::vector<double> coef = regresionLineal(x,y);
    std::cout << coef[0] << " + " << coef[1] << "x\n"; // arreglo estético 
    return 0;
}