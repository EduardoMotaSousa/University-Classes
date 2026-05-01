#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    char a = '*';

    cout <<  "Digite quantidade de *: ";
    cin >> num;

    for(int i = 1; i <= num; i++){
        cout << endl;

        for(int l = 1; l <= i; l++){
            cout << "*";
        }
    }

    return 0;
}