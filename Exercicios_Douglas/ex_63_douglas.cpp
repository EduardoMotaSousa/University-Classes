#include <iostream>

using namespace std;

//Altere o programa anterior para que ele aceite apenas números entre 0 e 1000.

int main() {
    int i{}, num, menor, maior, soma{};

    do{
        //entra dados
        cout << "Digite um número(Escreva '0' para finalizar): ";
        cin >> num;

        //valida
        if (num < 0 || num > 1000) {
            cout << "Digite um numero valido\n";
            continue;
        }

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

    //exibe na tela
    cout << "O maior num é: " << maior
        << "\nO menor num é: " << menor
        << "\nA soma de todos é: " << soma;

    return 0;
}