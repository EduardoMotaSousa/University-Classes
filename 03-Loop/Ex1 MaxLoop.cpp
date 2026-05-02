#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;

    cout << "Escreva um numero para ver sua tabuada: ";
    cin >> num;

    for(int i = 1; i <= 10; i++){
        cout << num << "*" << i << "=" << i * num << endl;
    }

    return 0;
}