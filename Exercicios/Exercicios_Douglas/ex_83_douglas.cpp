#include <iostream>
using namespace std;

// Faça um programa que leia uma quantidade indeterminada de números positivos e conte quantos deles estão nos seguintes intervalos: [0-25], [26-50], [51-75] e [76-100].

// A entrada de dados deverá terminar quando for lido um número negativo.

int main() {
    int numeros, local[4] = {0};
    
    for(int i = 0; i < 100; i++){
        cout << "Escreva um número entre -1 e 101(Numero negativo para sair): ";
        cin >> numeros;

        if(numeros > 100){
            cout << "Numero invalido!\n";
            continue;
        }

        if(numeros < 0){
            break;
        }

        if(numeros <= 25){
            local[0]++;
        }

        else if(numeros <= 50){
            local[1]++;
        }

        else if(numeros <= 75){
            local[2]++;
        }

        else{
            local[3]++;
        }
    }

    cout << "[0-25]: " << local[0]
        << "\n[26-50]: " << local[1] 
        << "\n[51-75]: " << local[2]
        << "\n[76-100]: " << local[3];
        
    return 0;
}