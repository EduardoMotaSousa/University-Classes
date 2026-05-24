#include <iostream>
using namespace std;

//Faça um Programa que leia um número e exiba o dia correspondente da semana. 
// (1-Domingo, 2- Segunda, etc.), se digitar outro valor deve aparecer valor inválido.

int main(){
    std::string semana[7] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
    int dia;

    cout << "Digite um numero de 1 a 7: ";
    cin >> dia;

    cout << semana[dia-1];

    return 0;
}