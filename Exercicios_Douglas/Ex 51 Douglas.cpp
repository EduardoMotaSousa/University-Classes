#include <iostream>

using namespace std;

//programa que imprima na tela os números de 1 a 20, um abaixo do outro. Depois modifique o programa para que ele mostre os números um ao lado do outro.

int main() {
    int vet[20];

    //escreve o vetor
    for(int i = 1; i <= 20; i++){
        vet[i-1] = i;
    }

    //num um em baixo do outro
    for(int i = 0; i < 20; i++){
        cout << vet[i] <<  endl;
    }

    //num lado a lado
    for(int i = 0; i < 20; i++){
        cout << vet[i] <<  " ";
    }

    cout << endl;

    return 0;
}