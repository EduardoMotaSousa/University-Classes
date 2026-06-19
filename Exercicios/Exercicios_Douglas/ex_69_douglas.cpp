#include <iostream>
using namespace std;

//Faça um programa que peça para n pessoas a sua idade, ao final o programa deverá verificar se a média de idade da turma varia entre 0 e 25,26 e 60 e maior que 60;
//e então, dizer se a turma é jovem, adulta ou idosa, conforme a média calculada.

int main() {
    int idade{}, quantidade{};
    double media{};
    std::string faixa;
    
    do{
        idade = -1;

        cout << "Qual sua idade('-1' para sair)? ";
        cin >> idade;

        if(idade != -1){ 
            media += idade;
            quantidade++;
        }

    }while(idade != -1);

    media /= quantidade;

    cout << "\nA Idade media do grupo é: " << media;

    if(media <= 25){
        cout << "\nSendo uma turma jovem!";
    }

    else if(media <= 60){
        cout << "\nSendo uma turma adulta!";
    }

    else{
        cout << "\nSendo uma turma idosa!";
    }
    return 0;
}