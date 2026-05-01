#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a = 0, b = 1, c, temp;


    cout << "Digite: ";
    cin >> temp;

    for(int i = 0; i < temp; i++){
        cout << a << endl;
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}