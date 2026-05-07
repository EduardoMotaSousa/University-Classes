#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que peça os 3 lados de um triângulo. O programa deverá informar se os 
//valores podem ser um triângulo. Indique, caso os lados formem um triângulo, se o mesmo 
//é: equilátero, isósceles ou escaleno.

int main(){
    float lados[3];

    for(int i = 0; i < 3; i++){
        cout << "Tamanho do lado do Triângulo: ";
        cin >> lados[i];
    }

    if(lados[0] >= lados[1] + lados[2] || lados[2] >= lados[1] + lados[0] || lados[2] >= lados[0] + lados [1]){
        cout << "Trinagulo invalido";
    }

    else if(lados[0] == lados[1] || lados[0] == lados[2]){
        if(lados[1] == lados[2]){
            cout << "Triângulo Equilátero\n";
        }
        else{
            cout << "Triângulo Isósceles\n";
        }
    }
    else{
        cout << "Triângulo Escaleno\n";
    }

    return 0;
}