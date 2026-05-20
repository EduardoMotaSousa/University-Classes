#include <iostream>
using namespace std;

int main(){
    char num[5][5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            num[i][j] = ' ';
        }
    }

    //olhos
    num[1][1] = 'O';

    num[1][3] = 'O';

    //Nariz
    num[2][2] = 'V'; 

    //boca
    num[3][1] = '_'; 
    num[3][2] = '_'; 
    num[3][3] = '_'; 

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << num[i][j];
        }
        cout << endl;
    }

    return 0;
}