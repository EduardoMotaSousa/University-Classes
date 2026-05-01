#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n, maior;

    cout << "Escreva um número: ";
    cin >> maior;

    for(int i = 1; i < 5; i++){
        cout << "Escreva um número: ";
        cin >> n;

        if(n > maior){
            maior = n;
        }
    }
    cout << "O maior N° foi: " << maior << endl;

    return 0;
}