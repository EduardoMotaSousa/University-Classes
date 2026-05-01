#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float horas, salario;

    cout << "Insira suas horas trabalhadas por mês e seu salário por hora: ";
    cin >> horas >> salario;

    cout << "Você ganha por mês:" << horas*salario;

    return 0;
}
