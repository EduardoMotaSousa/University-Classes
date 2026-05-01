#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float reajuste, sal, sal_maior = 0;
    int cont;

    cout << "Rajuste: ";
    cin >> reajuste;

    for(cont = 0; cont < 50; cont++){
        cout << "Salário atual: ";
        cin >> sal;

        sal *= 1 + (reajuste/100);
        cout << "Salario reajustado: " << sal << endl;

        if(sal > sal_maior){
            sal_maior = sal;
        }
    }
    cout << "O maior salario pós reajuste é: " << sal_maior << endl;

    return 0;
}