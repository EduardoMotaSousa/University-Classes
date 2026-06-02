#include <iostream>

using namespace std;

//Faça um programa que peça uma nota, entre zero e dez. 
//Mostre uma mensagem caso o valor seja inválido e continue 
//pedindo até que o usuário informe um valor válido.

int main() {
    int num;

    do{
        cout << "Escreva um numero entre 0 e 10: ";
        cin >> num;
    } while(num > 0 && num < 10);

    cout << "Valor invalido\n";

    return 0;
}