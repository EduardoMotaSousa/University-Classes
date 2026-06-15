#include <iostream>

using namespace std;

//Altere o programa de cálculo do fatorial, permitindo ao usuário calcular o fatorial várias vezes e limitando o fatorial a números inteiros positivos e menores que 16.

int main() {
    int num, resultado = 1;
    char seguir;

    do{ 
        //entrada de dados
        cout << "Qual numero inteiro quer fatorar?\n";
        cin >> num;

        //valida
        if(num < 0 || num >= 16){
            cout << "Numero invalido!\n";
            continue;
        }
        else if(num == 0){
            //exibe se for 0
            cout << "O resultado é: " <<  1 << endl;
            continue;;
        }

        //calcula
        for(int i = num; i >= 1; i--){
            resultado *= i;
        }

        //exibe
        cout << "O resultado é: " <<  resultado << endl;
        resultado = 1;

        cout << "\nDeseja calcular outro?(N para cancelar): ";
        cin  >> seguir;

    }while(seguir != 'N');

    return 0;
}