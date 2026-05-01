#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num, soma{};

    cout << "Escreva um num: ";
    cin >> num;

    for(int i = 1; i <= num; i++){
        soma = soma + i;
    }
    cout << "Soma de todos os num de 1 a " << num << " é "<< soma;

    return 0;
}