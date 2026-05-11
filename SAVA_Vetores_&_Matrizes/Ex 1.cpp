#include <iostream>
using namespace std;

int main(){
    int n[10];

    for(int i = 0; i < 10; i++){
        cin >> n[i];
    }

    for(int i = 9; i > 0; i--){
        cout << n[i] << endl;
    }

    return 0;
}