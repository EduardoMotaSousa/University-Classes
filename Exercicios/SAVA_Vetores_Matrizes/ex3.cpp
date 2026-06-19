#include <iostream>
using namespace std;

int main(){
    int vogal[5] = {0, 0, 0, 0, 0};
    char letra;

    do{
        cin >> letra;
        if(letra == 'a'){
            vogal[0]++;
        }
        else if(letra == 'e'){
            vogal[1]++;
        }
        else if(letra == 'i'){
            vogal[2]++;
        }
        else if(letra == 'o'){
            vogal[3]++;
        }
        else if(letra == 'u'){
            vogal[4]++;
        }
    } while(letra != 'z');

    cout << "A sequência de letras tem:" << endl
        << "a:" << vogal[0] << endl
        << "e:" << vogal[1] << endl
        << "i:" << vogal[2] << endl
        << "o:" << vogal[3] << endl
        << "u:" << vogal[4] << endl;

    return 0;
}