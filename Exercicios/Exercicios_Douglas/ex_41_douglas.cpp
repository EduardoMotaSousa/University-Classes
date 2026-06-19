#include <iostream>
#include <cmath>
using namespace std;

//leia 2 números e em seguida pergunte ao usuário qual operação ele deseja realizar.
//O resultado da operação deve ser acompanhado de uma frase que diga se o número é: par ou ímpar; positivo ou negativo; inteiro ou decimal.

int main(){
    float num[2], resul;
    char operacao;
    std::string positivo, par, intei; 

    //le os dados
    cout << "Escreva um número: ";
    cin >> num[0];

    cout << "Escreva um número: ";
    cin >> num[1];
    
    cout << "Escreva a opeção(+, -, *, /): ";
    cin >> operacao;
    
    //operação
    switch (operacao){
        case '+':
            resul = num[0] + num[1];
            break;
        case '-':
            resul = num[0] - num[1];
            break;
        case '*':
            resul = num[0] * num[1];
            break;
        case '/':
            resul = num[0] / num[1];
            break;
    }

    //comparação logica
    if (fmod(resul, 2.0) == 0.0){
        par = "Par";
    }
    else{
        par = "Impar";
    }
    
    if(resul >= 0){
        positivo = "Positivo";
    }
    else{
        positivo = "Negativo";
    }

    if(round(resul) - resul == 0){
        intei = "Inteiro";
    }
    else{
        intei = "Decimal";
    }

    //escreve na tela
    cout << "\nResultado da operação: " << resul << endl
    << "Caracteristicas do resultado: \n" 
    << "Par ou impar: " << par
    << "\nPositivo ou negativo: " << positivo
    << "\nInteiro ou decimal: " << intei << endl;

    return 0;
}