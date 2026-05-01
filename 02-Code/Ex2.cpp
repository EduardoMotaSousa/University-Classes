#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main(){

    string nome;
    double nota;

    cout << "Nome e nota do alunoem sequência: ";
    cin >> nome >> nota;

    cout << "Aluno: " << nome << "\nNota: " << nota;

    return 0;
}