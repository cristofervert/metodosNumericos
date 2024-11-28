#include <iostream>
#include <cmath>

// x -> x^2 / 2 -> F(b) - F(a) 
double f(double x){
    // x^3 -> x^4 / 4 
    // x^n -> x^(n+1) / (n+1)
    double resultado = pow(x,3) + 2*x*x;
    return resultado;
}

double sumaRiemann(double a, double b, double n=10){
    double suma = 0, x = a;
    double deltax = (b-a)/n; // para saber el tamaño de la base
    
    for(int i=0; i<n; i++){
        x = a + i*deltax; // 1 + 1*0.1
        suma += f(x)*deltax ; // altura*base -> para cada rectangulo
    }
    return suma;
}

double reglaDelTrapecio(double a, double b, double n=10){
    double suma = 0, x = a;
    double resultado = 0.0;
    double deltax = (b-a)/n; // para saber el tamaño de la base    
    for(int i=0; i<n; i++){
        x = a + i*deltax;
        (i==0 || i==n) ? suma += f(x): suma += 2*f(x); // se suman puras alturas
    }
    resultado = (suma*deltax)*0.5;
    return resultado;
}

double reglaDeSimpson(double a, double b, double n=10){
    int test = (int) n;
    double suma = 0, x = a;
    double resultado = 0.0;
    double deltax = (b-a)/n; // para saber el tamaño de la base  
    
    //std::cout << test <<  "\t" << test%2 << "\n";
    for(int i=0; i<n; i++){
        x = a + i*deltax;
        if( i==0 || i==n ){
            suma += f(x);
        }
        else if(i%2){
            suma += 4*f(x);
        }
        else{
            suma += 2*f(x);
        }
    }
    resultado = (suma*deltax)*(1/3);
    return resultado;
}

int main(){
    double a=0, b=1.6;
    std::cout << "Integracion numerica\n";
    std::cout << "RDT -> 100 partes: " << reglaDelTrapecio(a,b,10) << "\n";
    std::cout << "SR -> 100 partes: " << sumaRiemann(a,b, 10) << "\n";
    std::cout << "RS -> 100 partes: " << reglaDeSimpson(a,b,10) << "\n";
    return 0;
}