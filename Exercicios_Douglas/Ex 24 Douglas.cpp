#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que leia três números e mostre o maior deles.

int main(){
    int n1, n2, i{};

    cout << "Escreva um numero: ";
    cin >>  n1;

    do{
        cout << "Escreva outro numero: ";
        cin >>  n2;
        i++;

        if(n2 > n1){
            n1 = n2;
        }

    } while (i < 2);

    cout << n1 << endl;

    return 0;
}