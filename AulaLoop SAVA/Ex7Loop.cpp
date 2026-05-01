#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n{}, somapar{}, somaimpar{}, cont{};

    for(cont = 0; cont < 6; cont++){
        cout << "Escreva um numero: ";
        cin >> n;

        if(n%2 == 0){
            somapar += n;
        }
        else{
            somaimpar += n;
        }
    } 
    cout << "A soma dos impartes é: " << somaimpar << endl;

    cout << "A soma dos pares é: " << somapar << endl;
    
    
    return 0;
}