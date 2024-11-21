#include <iostream>
#include <vector>
#include <cmath>
#define ITERACIONES 1000

std::vector<double> metodoJacobi(
    const std::vector<std::vector<double>>& A,
    const std::vector<double>& b,
    std::vector<double> x0, 
    double tolerancia = 1e-6){
    
    int iter = 0, n= x0.size(), m= A.size();
    double errorMax = 0.1, suma=0;
    std::vector<double> x(n, 0.0); // {0.0, 0.0, 0.0}
    while(iter < ITERACIONES){

        for(int i=0; i<m; i++){
            suma = 0;
            for(int j=0; j<m; j++){
                if(i != j){
                    suma += A[i][j]*x0[j]; // Equivocación anterior: x0[i]
                }
            }
            x[i] = (b[i] - suma)/A[i][i]; 
            std::cout << x[i] << "\t\t"; 
        }
        std::cout << "\n";

        for(int i=0; i<n; i++){
            if( errorMax < fabs(x[i]-x0[i]) ){
                errorMax = fabs(x[i]-x0[i]);
            }
        }
        if(errorMax < tolerancia){
            break;
        }
        x0 = x;
        iter++;
    }
    return x0;
}

int main(){
    std::vector<std::vector<double>> A = {
        {4,1,1},
        {1,3,2},
        {3,2,6}
    };
    std::vector<double> b = {9,8,7};
    std::vector<double> x0(b.size(), 0.0);
    std::vector<double> x = metodoJacobi(A,b,x0);
    return 0;
}