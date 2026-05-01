#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    float l_a, l_b, l_c;


    cout << "Escreva três lados de um triangulo: ";
    cin >> l_a >> l_b >> l_c;


    if(l_a >= l_b + l_c || l_b >= l_a + l_c || l_c >= l_a + l_b){
        cout << "Não forma um triângulo valido\n";
        return 0;
    }


    else{
        cout << "Triangulo valido - ";
    }


    if(l_a == l_b && l_a == l_c && l_b == l_c){
        cout << "Equilatero\n";
    }
   
    else{
        if(l_a == l_b || l_a == l_c || l_b == l_c){
            cout << "Isosceles\n";
        }
       
        else{
            cout << "Escaleno\n";
        }
    }
    return 0;
}
