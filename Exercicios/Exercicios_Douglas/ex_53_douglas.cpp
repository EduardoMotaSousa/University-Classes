#include <iostream>

using namespace std;

//ue leia 5 números e informe a soma e a média dos números.

int main() {
    double vet[5], soma{};

    //insere os dados
    for(int i = 0; i < 5; i++){
        cout << "Escreva um numero: ";
        cin >> vet[i];
    }

    //soma
    for (int i = 0; i < 5; i++)
    {
        soma += vet[i];
    }

    //escerve na tela
    cout << "Soma dos nuns: " << soma
        << "\nMedia dos nuns: " << soma/5 << endl;

    return 0;
}