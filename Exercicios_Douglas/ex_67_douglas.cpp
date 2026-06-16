#include <iostream>
using namespace std;

//Faça um programa que mostre todos os primos entre 1 e N sendo N um número inteiro fornecido pelo usuário.
//O programa deverá mostrar também o número de divisões que ele executou para encontrar os números primos.

int main() {
    int num, numdiv{};

    cout << "Escreva um num: ";
    cin >> num;

    for(int i = 2; i <= num; i++){ 
        bool primo = true;

        for(int j = 2; j < i; j++){
            if(i % j == 0){
                primo = false;
                numdiv++;
                break;
            }
        }

        if(primo){
            cout <<  "É primo: " << i << endl
                << "Foi necessario: " << numdiv << " divisões\n";
            numdiv = 0;
        }
    }

    return 0;
}