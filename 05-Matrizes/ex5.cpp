#include <iostream>
using namespace std;

int main(){
    int num[5][5];

    //Escreve na matriz
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            num[i][j] = i * 5 + j + 1;
        }
    }

    cout << "Matriz: \n";

    //Escreve na matriz
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}