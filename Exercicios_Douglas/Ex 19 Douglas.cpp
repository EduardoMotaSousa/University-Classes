#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que peça dois números e imprima o maior deles.

int main(){
    int n1, n2;

    cout << "Escreva um número: ";
    cin >> n1;

    cout << "Escreva um número: ";
    cin >> n2;

    if(n1 < n2){
        cout << "O maior é: " << n2;
    }
    else{
        cout << "O maior é: " << n1;
    }
    
    return 0;
}