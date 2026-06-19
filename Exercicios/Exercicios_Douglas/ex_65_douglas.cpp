#include <iostream>
using namespace std;

//peça um número inteiro e determine se ele é ou não um número primo. Um número primo é aquele que é divisível somente por ele mesmo e por 1.

int main() {
    int num;
    bool primo = true;

    cout << "Escreva um num:";
    cin >> num;

    if(num <= 1){
	primo = false;
    }

    for(int i = 2; i <= num/2; i++){
        if(num % i == 0){
            primo = false;
	    break;
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