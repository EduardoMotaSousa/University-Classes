#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//leia um número inteiro maior que 0 e menor que 1000 e imprima a quantidade 
//de centenas, dezenas e unidades do mesmo.

int main(){
    int num;

    cout << "Write a number between 0 and 1000: ";
    cin >> num;

    if (num < 0 || num > 1000){
        cout << "Invalid number";
        return 0;
    }

    cout << "\nHundreds: " << floor(num / 100)
         << "\nTens: " << floor(num / 10)
         << "\nUnits: " << num << endl;
    
    return 0;
}