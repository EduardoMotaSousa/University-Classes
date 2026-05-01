#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    // Retorna todos os numeros impares até o numero
    cout <<  "Digite um numero: ";
    cin >> num;

    for(int i = 1; i <= num; i+=2){
        cout << i << endl;
    }

    return 0;
}