#include <iostream>
#include <iomanip>
using namespace std;

//mostra os numeros do fibonacci

int main(){
    int a = 0, b = 1, c, temp;

    //Entra dados
    cout << "Digite: ";
    cin >> temp;

    //Calculo e exibe
    for(int i = 0; i < temp; i++){
        cout << a << endl;
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}