#include <iostream>
#include <iomanip>
using namespace std;

// Faça um Programa que leia três números e mostre-os em ordem decrescente.

int main(){
    int ordem[3] = {0, 0, 0}, num;

    for(int i = 0; i < 3; i++){ 
        cout << "Escreva um numero positivo: ";
        cin >> num;
        

        if(num > ordem[0]){
            ordem[2] = ordem[1];
            ordem[1] = ordem[0];
            ordem[0] = num;
        }

        else if(num > ordem[1]){
            ordem[2] = ordem[1];
            ordem[1] = num;
        }

        else{
            ordem[2] = num;
        }
    }

    cout << "Ordem: " << ordem[0] << ordem[1] << ordem[2];

    return 0;
}