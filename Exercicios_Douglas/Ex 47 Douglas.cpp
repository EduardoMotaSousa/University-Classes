#include <iostream>

using namespace std;

//leia um nome de usuário e a sua senha e não aceite a senha igual 
//ao nome do usuário, mostrando uma mensagem de erro e voltando a 
//pedir as informações.

int main() {
    std::string senha, nome;

    do{     
        cout << "Nome: ";
        cin >> nome;

        cout << "Senha: ";
        cin >> senha;

    }while(senha == nome);

    return 0;
}