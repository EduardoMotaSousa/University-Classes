#include <iostream>
#include <cmath>
using namespace std;

//peça um número e informe se o número é inteiro ou decimal. Dica: utilize uma função de arredondamento.
int main(){
    float num;

    cout << "Escreva um número int ou float: ";
    cin >> num;

    if(round(num) - num == 0){
        cout << "É inteiro\n";
    }
    else{
        cout << "É decimal\n";
    }

    return 0;
}