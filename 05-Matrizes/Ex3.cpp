#include <iostream>
using namespace std;

int main(){
    int num[4][4], mat[4][4];

    cout << "Tabela:\n";

    //Escreve na matriz
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            num[i][j] = 1 + i;

            //Exibe o valor da matriz
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Tabela Invertida:\n";

    //Passa o valor da linha para a coluna
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){ 
            mat[i][j] = num[j][i];

            //Exibe na tela
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}