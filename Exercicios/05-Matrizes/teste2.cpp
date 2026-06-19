#include <iostream>
using namespace std;

int main(){
    int num[7][7];

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            num[i][j] = i + j;
        }
    }

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            cout << num[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}