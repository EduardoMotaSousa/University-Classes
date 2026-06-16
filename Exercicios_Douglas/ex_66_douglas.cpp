#include <iostream>
using namespace std;

//Altere o programa de cálculo dos números primos, informando, caso o número não seja primo, por quais número ele é divisível.

int main() {
    int num;
    bool primo = true;

    cout << "Escreva um num: ";
    cin >> num;

    if(num <= 1){
	primo = false;
    }

    for(int i = 2; i <= num/2; i++){
        if(num % i == 0){
            primo = false;
            cout << "É divisível por: " << i << endl;
        }
    }

    if(primo == false){
        cout <<  "Não é primo\n";
    }

    else{
        cout <<  "É primo\n";
    }

    return 0;
}