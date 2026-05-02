#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num = 1;

    for(int i = 0; i <= 10; i++){
        cout << num << "*" << i << "=" << i * num << endl;

        if(i == 10){
            num++;
            i = 0;
            cout << endl;
        }
        if(num == 10){
            return 0;
        }
    }

    return 0;
}