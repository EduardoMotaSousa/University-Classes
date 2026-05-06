#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que leia três números e mostre o maior e o menor deles.

int main(){
    int maior, menor, n1, i{};

    cout << "Escreva um numero: ";
    cin >>  maior;

    menor = maior;

    do{
        cout << "Escreva outro numero: ";
        cin >>  n1;
        i++;

        if(n1 > maior){
            maior = n1;
        }

        if(n1 < menor){
            menor = n1;
        }

    } while (i < 2);

    cout << "O maior numero É: " << maior << endl;
    cout << "O menor numero É: " << menor << endl;

    return 0;
}