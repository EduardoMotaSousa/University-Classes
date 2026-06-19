#include <iostream>

using namespace std;

//que leia 5 números e informe o maior número.

int main() {
    int vet[5], maior{};

    //entreda de dados
    for(int i = 0; i < 5; i++){ 
        cout << "Escreva um num inteiro: ";
        cin >> vet[i];

        if(i == 0){
            maior = vet[i];
        }
    
        //verifica o maior
        if(maior < vet[i]){
            maior = vet[i];
        }
    }

    //mostra para o usuario 
    cout << "Dos números: ";

    for (int i = 0; i < 5; i++)
    {
        cout << vet[i] << " ";    
    }

    cout << "O maior é " << maior;

    return 0;
}