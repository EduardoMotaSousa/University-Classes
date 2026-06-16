#include <iostream>
using namespace std;

//Faça um programa que calcule o mostre a média aritmética de N notas.

int main() {
    int quantidade{};
    double nota, media{};
    
    do{
        nota = -1;

        cout << "Qual sua nota('-1' para sair)? ";
        cin >> nota;

        if(nota != -1){ 
            media += nota;
            quantidade++;
        }

    }while(nota != -1);

    cout << "\nSua Media: " << media / quantidade;

    return 0;
}