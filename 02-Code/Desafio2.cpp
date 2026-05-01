#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int quantidade;
    float preco;
    string nome;

    cout << "Produto: ";
    cin >> nome;

    cout << "Valor: ";
    cin >> preco;

    cout << "Quantidade: ";
    cin >> quantidade;

    cout << fixed << setprecision(2);
    cout << "Total: R$" << quantidade*preco;

    return 0;
}