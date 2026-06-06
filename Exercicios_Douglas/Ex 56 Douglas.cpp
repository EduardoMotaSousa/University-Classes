#include <iostream>

using namespace std;

//Altere o programa anterior para mostrar no final a soma dos números.

int main() {
    int num1, num2, maior, menor, soma{};

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
        soma += menor;
    }

    cout << "\nA soma de todos esse números é: " << soma << endl;
    
    return 0;
}