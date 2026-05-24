#include <iostream>
using namespace std;

//Faça um Programa para um caixa eletrônico.

//O programa deverá perguntar ao usuário a valor do saque e depois informar quantas 
//notas de cada valor serão fornecidas.

//As notas disponíveis serão as de 1, 5, 10, 50 e 100 reais. O valor mínimo é de 10 
//reais e o máximo de 600 reais.

//O programa não deve se preocupar com a quantidade de notas existentes na máquina.

int main(){
    int notas[5] = {1, 5, 10, 50, 100}, notas_usadas[5] = {0, 0, 0, 0, 0}, saque;

    cout << "Quanto quer sacar? ";
    cin >> saque;

    if(saque >= 10 && saque <= 600){
        for(int i = 4; saque > 0; i--){
            while(saque >= notas[i]){
                saque -= notas[i];
                notas_usadas[i]++;
            }
            cout << notas_usadas[i] << " notas de: " << notas[i] << endl;
        }
    }

    else{
        cout << "Valor invalido.";
    }

    return 0;
}