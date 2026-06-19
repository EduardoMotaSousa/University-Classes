#include <iostream>

using namespace std;

//Faça um programa que calcule o fatorial de um número inteiro fornecido pelo usuário. Ex.: 5!=5.4.3.2.1=120

int main() {
    int num, resultado = 1;

    //entrada de dados
    cout << "Qual numero inteiro quer fatorar?\n";
    cin >> num;

    //valida
    if(num < 0){
        cout << "Numero invalido!\n";
        return 0;
    }
    else if(num == 0){
        //exibe se for 0
        cout << "O resultado é: " <<  1 << endl;
        return 0;
    }

    //calcula
    for(int i = num; i >= 1; i--){
        resultado *= i;
    }

    //exibe
    cout << "O resultado é: " <<  resultado << endl;

    return 0;
}