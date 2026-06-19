#include <iostream>
using namespace std;

int main(){
    int num[3][4], par{};

    //Escreve na matriz
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            num[i][j] = i - j;
        }
    }

    //Compara se é par
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(num[i][j] % 2 == 0){
                par++;
            }
        }
    }
    
    //Exibe na tela
    cout << "Quantidade de numeros pares: " << par << endl;

    return 0;
}