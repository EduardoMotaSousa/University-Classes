#include <iostream>

using namespace std;

// série de Fibonacci é formada pela seqüência 1,1,2,3,5,8,13,21,34,55,... Faça um programa capaz de gerar a série até o n−ésimo termo.

int main() {
    int fibo1 = 1, fibo2 = 1, fibo3, termo;

    cout << "Quantos termos do Fibonacci você quer? ";
    cin >> termo;

    cout << fibo1 << " ";
    
    for(int i{}; i < termo-1; i++){
        cout << fibo1 << " ";

        fibo3 = fibo2;
        fibo2 = fibo1;
        fibo1 = fibo3 + fibo2;
    }
    return 0;
}