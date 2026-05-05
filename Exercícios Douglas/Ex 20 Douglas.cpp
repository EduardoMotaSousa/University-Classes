#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que peça um valor e mostre na tela se o valor é positivo ou negativo.

int main(){
    int n1;

    cout << "Escreva um número: ";
    cin >> n1;

    if(n1 < 0){
        cout << "É negativo\n";
    }
    else{
        cout << "É postivo ";
    }
    
    return 0;
}