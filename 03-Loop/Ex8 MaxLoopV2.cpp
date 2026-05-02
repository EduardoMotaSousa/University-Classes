#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    char a = '*';

    cout <<  "Digite quantidade de linhas da piramide: ";
    cin >> num;

    for(int i = 1; i <= num; i++){
        cout << endl;
        
        
        for(int l = num; l >= i; l--){
            cout << " ";
        }

        for(int l = 1; l <= i; l++){
            cout << "**";
        }
    }

    return 0;
}