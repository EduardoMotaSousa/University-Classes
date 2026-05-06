#include <iostream>
#include <iomanip>
using namespace std;

//Faça um programa para a leitura de duas notas parciais de um aluno. 
//O programa deve calcular a média alcançada por aluno e apresentar: 
//A mensagem "Aprovado", se a média alcançada for maior ou igual a sete; 
//A mensagem "Reprovado", se a média for menor do que sete; A mensagem "Aprovado 
//com Distinção", se a média for igual a dez.

int main(){
    float nota1, nota2, media;

    cout << "Escreva a primeira nota do aluno: ";
    cin >>  nota1;

    cout << "Escreva a segunda nota do aluno: ";
    cin >>  nota2;

    media = (nota1 + nota2)/2;

    if(media == 10){
        cout << "Aprovado com Distinção\n";
    }

    else if(media >= 7){
        cout << "Aprovado\n";
    }

    else{
        cout << "Reprovado\n";
    }

    return 0;
}