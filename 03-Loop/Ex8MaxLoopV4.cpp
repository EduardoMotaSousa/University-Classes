#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    char a = '*';

    cout <<  "Digite o comprimento da linha em diagonal: ";
    cin >> num;

    for(int i = 1; i <= num; i++){
        cout << endl;
        
        
        for(int l = num; l >= i; l--){
            cout << " ";
        }

        cout << "*";
    }

    cout << endl;
    
    return 0;
}