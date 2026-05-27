#include <iostream>
using namespace std;

//peça um número inteiro e determine se ele é par ou impar. Dica: utilize o operador módulo (resto da divisão).

int main(){
    int num;

    cout << "Escreva um número: ";
    cin >> num;

    if(num %2 == 0){
        cout << "É par\n";
    }
    else{
        cout << "É impar\n";
    }

    return 0;
}