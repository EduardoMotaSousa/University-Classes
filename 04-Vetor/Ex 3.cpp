#include <iostream>
using namespace std;

int main(){
    float notas[40];
    int faixa[4] = {0,0,0,0};

    for(int i = 0; i < 40; i++){
        notas[i] = i;
    }

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

    cout << "insuficiente " << faixa[0] << endl
         << "regular " << faixa[1] << endl
         << "bom " <<faixa[2] << endl
         << "excelente " << faixa[3] << endl;

    return 0;
}