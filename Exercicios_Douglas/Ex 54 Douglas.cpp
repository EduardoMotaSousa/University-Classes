#include <iostream>

using namespace std;

//que imprima na tela apenas os números ímpares entre 1 e 50.

int main() {
    int vet[50];

    //escreve no vetor
    for(int i = 0; i < 50; i++){
        vet[i] = i + 1;
    }

    //exibe o pedido
    for (int i = 0; i < 50; i++){
        if(vet[i] % 2 != 0){
            cout << vet[i] << " ";
        }
    }
    
    return 0;
}