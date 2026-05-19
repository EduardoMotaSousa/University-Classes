#include <iostream>
using namespace std;

int main(){
    int num[3][3], max{}, quant{};

    //Escreve na matriz
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            num[i][j] = 1 + i;
        }
    }

    //Encontra o maior
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(num[i][j] > max){
                max = num[i][j];
            }
        }
    }

    //Descobre quantas vezes ele aparece
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(num[i][j] == max){
                quant++;
            }
        }
    }

    cout << "O maior número é: " << max
        << " e ele aparece " << quant
        << " Vezes.\n"; 

    return 0;
}