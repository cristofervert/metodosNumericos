#include <iostream>
#include <vector>

std::vector<std::vector<double>> diferenciasDivididas(
    const std::vector<double>& x,
    const std::vector<double>& y){
        int n = x.size();
        std::vector<std::vector<double>> coef(n, std::vector<double>(n));
        
        for(int i=0; i < n; i++){
            coef[i][0] = y[i];
        }

        for(int j=1; j < n; j++){
            for(int i=0; i< n - j; i++){
                coef[i][j] = (coef[i+1][j-1] - coef[i][j-1])/(x[i+j] - x[i]);
            }
        }
        return coef;
    }

double interpolacionNewton(
    const std::vector<std::vector<double>>& coef,
    const std::vector<double>& x, 
    double punto){
    
    int n = x.size();
    double resultado= coef[0][0]; // corresponde a y0
    double factor = 1.0;

    for(int i=1; i<n; i++){
        factor *= (punto - x[i-1]); // PI -> producto
        resultado += coef[0][i]*factor;
    }
    return resultado;
    }

int main(){
    std::vector<double> x = {1.0,2.0,3.0,4.0};
    std::vector<double> y = {1.0,4.0,9.0,16.0};
    std::vector<std::vector<double>> coef = diferenciasDivididas(x,y);

    double punto = interpolacionNewton(coef,x,1.5);
    std::cout << punto << "\n";


    return 0;
}