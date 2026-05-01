#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int leia;

    cout << "Escreva um número: ";
    cin >> leia;

    for(int i = 1; i < 21; i++){
        cout << leia << endl;
    }

    return 0;
}