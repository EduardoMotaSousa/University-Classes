#include <iostream>
using namespace std;

int main(){
    char num[3];

    char v[] = "aaaaaa";

    cin >> num;

    for(int i = 0; i < 6; i++){
        cout << num[i] << endl;
        cout << v[i];
    }

    return 0;
}