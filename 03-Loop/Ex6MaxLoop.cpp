#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num, fat = 1;

    cout <<  "Digite um numero para ver o seu faltorial(!): ";
    cin >> num;

    for(int i = 1; i <= num; i++){
        fat *=i;
    }
    cout << fat << endl;

    return 0;
}