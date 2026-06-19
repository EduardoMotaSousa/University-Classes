#include <iostream>
using namespace std;

int main(){
    int num[4][4];

    //Escreve na matriz
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            num[i][j] = 1;
        }
    }

    //Compara se é iqual 
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                num[i][j] = 0;
            }
            //Exibe na tela
            cout << num[i][j];
        }
        cout << endl;
    }

    return 0;
}