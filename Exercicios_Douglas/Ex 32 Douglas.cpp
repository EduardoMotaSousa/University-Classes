#include <iostream>
#include <iomanip>
using namespace std;

//Faça um programa que lê as duas notas parciais obtidas por um aluno numa disciplina 
//ao longo de um semestre, e calcule a sua média.

//A atribuição de conceitos obedece à tabela abaixo: Média de Aproveitamento 
//Conceito Entre 9.0 e 10.0 A Entre 7.5 e 9.0 B Entre 6.0 e 7.5 C Entre 4.0 e 6.0 D 
//Entre 4.0 e zero E

//O algoritmo deve mostrar na tela as notas, a média, o conceito correspondente e a 
//mensagem “APROVADO” se o conceito for A, B ou C ou “REPROVADO” se o conceito for D 
//ou E.

int main(){
    float n1, n2, media;

    cout << "Nota 1: ";
    cin >>  n1;


    cout << "Nota 2: ";
    cin >>  n2;

    media = (n1 + n2) / 2;

    if(media >= 9){
        cout << "Media: " << media << "\nNota1: " << n1 << "\nNota2: " << n2 << "\nAprovado: Conceito A";
    }

    else if(media >= 7.5){
        cout << "Media: " << media << "\nNota1: " << n1 << "\nNota2: " << n2 << "\nAprovado: Conceito B";
    }

    else if(media >= 6){
        cout << "Media: " << media << "\nNota1: " << n1 << "\nNota2: " << n2 << "\nAprovado: Conceito C";
    }

    else if(media >= 4){
        cout << "Media: " << media << "\nNota1: " << n1 << "\nNota2: " << n2 << "\nReprovado: Conceito D";
    }

    else{
        cout << "Media: " << media << "\nNota1: " << n1 << "\nNota2: " << n2 << "\nReprovado: Conceito E";
    }


    return 0;
}