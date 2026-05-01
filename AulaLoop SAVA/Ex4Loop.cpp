#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float sal_maior, sal, sal_soma;
    int cont;

    for(cont = 0; cont < 4; cont++){
        cout << "Escreva o salario do funcionario: ";
        cin >> sal;

        sal_soma += sal;
        
        if(sal_maior < sal){
            sal_maior = sal;
        }
    }
    cout << "Media salarial da empresa: " << sal_soma / cont << endl;
    cout << "Maior salario da empresa: " << sal_maior << endl;

    return 0;
}