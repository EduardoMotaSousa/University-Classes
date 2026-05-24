#include <iostream>
using namespace std;

int main(){
    int num[20], valorun{};


    for(int i = 0; i < 20; i++){

        //entra os numeros
        num[i] = i;

        //num[0] = 0; teste com estes também funciona
        //num[1] = 0;

        for(int t = 0; i > t; t++){
            //verifica se é iqual aos outros
            if(num[i] == num[t]){
                cout << "Valor '" << num[i]
                     << "' repetido na posicao: " << i
                     << "\nQuantidade de valores unicos: " << valorun << endl;
                     return 0;
            }
        }
        //se não for, anota 
        valorun++;
    }

    //Se não tiver repetido, exibe na tela a quantidade de valores 
    cout << "Quantidade de valores unicos: " << valorun << endl;

    return 0;
}