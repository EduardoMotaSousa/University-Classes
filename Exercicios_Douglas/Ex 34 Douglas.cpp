#include <iostream>
#include <iomanip>
using namespace std;

//Calcule as raízes de uma equação do segundo grau, na forma ax² + bx + c.

//Deverá pedir os valores de a, b e c e fazer as consistências, informando ao usuário 
//nas seguintes situações:

//Se o usuário informar o valor de A igual a zero, a equação não é do segundo grau e o 
//programa não deve fazer pedir os demais valores, sendo encerrado; Se o delta calculado 
//for negativo, a equação não possui raízes reais. Informe ao usuário e encerre o 
//programa; Se o delta calculado for igual a zero a equação possui apenas uma raiz real; 
//informe-a ao usuário; Se o delta for positivo, a equação possui duas raiz reais; 
//informe-as ao usuário; 

int main(){
    float a, b, c, delta;

    cout << "Valor de A: ";
    cin >> a;

    if(a == 0){
        cout << "A equação não é de segundo grau";
        return 0;
    }

    cout << "Valor de B: ";
    cin >> b;

    cout << "Valor de C: ";
    cin >> c;

    delta = (b * b) - (4 * a * c);

    if(delta < 0){
        cout << "A equação não possui raízes reais";
    }

    else if(delta == 0){
        cout << "A equação possui apenas uma raíz real";
    }

    else{
        cout << "A equação possui duas raízes reais";
    }
    
    return 0;
}