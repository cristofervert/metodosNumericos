#include <iostream>
#include <cmath>

double f(double x){
    return x*x + 2.5*x - 3;
}
bool verifIntervRaiz(double a, double b){
    return f(a)*f(b) < 0;
}

double biseccion(double a, double b, double tolerancia){
    unsigned int i=0; // no habia inicializado la variable -> se estaba referenciando un valor previamente guardado
    double c_old=0;
    double c = (a+b)/2;
    std::cout << "i\t\tx_n\t\tx_n+1\t\tError\n"; 
    while( fabs(c-c_old) > tolerancia )
    { // se define el error relativo como condicion de ruptura
        verifIntervRaiz(a,c)? b=c : a=c;
        c_old = c;
        c = (a+b)/2;
        std::cout << i <<"\t\t"<< c_old << "\t\t" << c << "\t\t" << fabs(c-c_old) << "\n"; 
        i++;
    }
    return c;
}

int main(){
    std::cout << "Programa de metodo de intervalos\n";
    long a,b,tolerancia=1e-6; 
    std::cout << "Ingrese el primer numero: ";
    std::cin >> a;
    std::cout << "Ingrese el segundo numero: ";
    std::cin >> b;
    biseccion(a,b,tolerancia);
    return 0;
}