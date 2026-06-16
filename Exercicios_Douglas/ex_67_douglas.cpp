#include <iostream>
using namespace std;

//Faça um programa que mostre todos os primos entre 1 e N sendo N um número inteiro fornecido pelo usuário.

int main() {
    int num;

    cout << "Escreva um num: ";
    cin >> num;

    for(int i = 2; i <= num; i++){ 
        bool primo = true;

        for(int j = 2; j < i; j++){
            if(i % j == 0){
                primo = false;
                break;
            }
        }

        if(primo){
            cout <<  "É primo: " << i << endl;
        }
    }

    return 0;
}