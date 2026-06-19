#include <iostream>
using namespace std;

int main(){
    float notas[40];
    int faixa[4] = {0,0,0,0};

    //Entra 40 notas no vetor
    for(int i = 0; i < 40; i++){
        notas[i] = i/4;
    }

    //Calcula a quantidade de cada tipo de nota
    for(int i = 0; i < 40; i++){
        if(notas[i] < 5){
            faixa[0]++;
        }
        else if(notas[i] < 7){
            faixa[1]++;
        }
        else if(notas[i] < 9){
            faixa[2]++;
        }
        else{ 
            faixa[3]++;
        }
    }

    //Exibe na tela as faixas 
    cout << "Insuficiente: " << faixa[0] << endl
         << "Regular: " << faixa[1] << endl
         << "Bom: " << faixa[2] << endl
         << "Excelente: " << faixa[3] << endl;

    return 0;
}