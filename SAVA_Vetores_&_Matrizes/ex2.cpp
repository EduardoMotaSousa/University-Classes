#include <iostream>
using namespace std;

int main(){
    float media, notas[10];

    for(int i = 0; i < 10; i++){ 
        cin >> notas[i];
        media += notas[i];
    }

    media /= 10;

    for(int i = 0; i < 10; i++){ 
        if(notas[i] >= media){
            cout << notas[i] << endl;
        }
    }

    return 0;
}