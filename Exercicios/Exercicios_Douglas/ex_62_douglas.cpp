#include <iostream>

using namespace std;

//dado um conjunto de N números, determine o menor valor, o maior valor e a soma dos valores.

int main() {
    int i{}, num, menor, maior, soma{};

    do{
        cout << "Digite um número(Escreva '0' para finalizar): ";
        cin >> num;

        if(i == 0){ 
            maior = num;
            menor = num;
        }

        if(num > maior){
            maior = num;
        }

        if(num < menor && num != 0){
            menor = num;
        }

        soma += num;
        i++;

    }while(num != 0);

    cout << "O maior num é: " << maior
        << "\nO menor num é: " << menor
        << "\nA soma de todos é: " << soma;

    return 0;
}