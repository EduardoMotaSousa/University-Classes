#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que peça um número correspondente a um determinado ano e em 
//seguida informe se este ano é ou não bissexto.

int main(){
    int ano;

    cout << "Ano: ";
    cin >> ano;

    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0){
        cout << "É bissexto";
    }

    else{ 
        cout << "Não é bissexto";
    }
    
    return 0;
}