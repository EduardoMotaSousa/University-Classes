#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num[10];

    for(int i = 0; i < 10; i++){
        num[i] = i;
        cout << num[i] << endl;
    }    

    return 0;
}