#include <iostream>

using namespace std;

//programa que receba dois números inteiros e gere os números inteiros que estão no intervalo compreendido por eles.

int main() {
    int num1, num2, maior, menor;

    //escreve
    cout << "Escreva um num inteiro: ";
    cin >> num1;

    cout << "Escreva outro num inteiro: ";
    cin >> num2;

    //determina o maior
    if(num1 > num2){
        maior = num1;
        menor = num2;
    }
    
    else { 
        menor = num1;
        maior = num2;
    }

    //exibe o pedido
    while(menor < (maior-1)){
        cout << ++menor << " ";
    }
    
    return 0;
}