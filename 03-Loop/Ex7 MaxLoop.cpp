#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num;
    float soma{}, nota{};

    cout <<  "Digite quantidade de nota: ";
    cin >> num;

    for(int i = 1; i <= num; i++){
        cout << i << "° Nota: ";
        cin >> nota;

        soma = soma + nota;
    }
    cout << "Media: " << soma / num;

    return 0;
}