#include <iostream>

using namespace std;

//leia e valide as seguintes informações: Nome: maior que 3 
//caracteres; Idade: entre 0 e 150; Salário: maior que zero; 
//Sexo: 'f' ou 'm'; Estado Civil: 's', 'c', 'v', 'd';

int main() {
    std::string nome;
    int idade, validacao;
    double salario;
    char sexo, estadocivil;

    //Nome
    do{
        validacao = 0;
        cout << "Qual seu nome? ";
        cin >> nome;
        
        for(int i = 0; i <= 3; i++){
            if(nome[i] == '\0'){
                cout << "O nome precisa ter mais que 3 caracteres!\n";
                validacao = 1;
            }
        }
    }while (validacao == 1);
    
    //idade
    do{ 
        validacao = 0;
        cout << "Qual sua idade? ";
        cin >> idade;

        if(idade < 0 || idade > 150){
                cout << "Digite uma idade valida\n";
                validacao = 1;
        }
    }while(validacao == 1);

    //salario
    do{ 
        validacao = 0;
        cout << "Qual seu salario? ";
        cin >> salario;

        if(salario <= 0){
            cout << "Digite um salario valida! \n";
            validacao = 1;
        }
    }while(validacao == 1);

    //Sexo
    do{ 
        validacao = 0;
        cout << "Qual seu Sexo: 'f' ou 'm'?";
        cin >> sexo;

        switch(sexo){
            case 'f':
            case 'm':
            break;
            
            default:
                cout << "Digite um sexo valido!\n ";
                validacao = 1;
        }
    }while(validacao == 1);

    do{ 
        validacao = 0;
        cout << "Qual seu Estado Civil: 's', 'c', 'v', 'd'? \n";
        cin >> estadocivil;

        switch(estadocivil){
            case 's':
            case 'c':
            case 'v':
            case 'd':
            break;
            
            default:
                cout << "Digite um estado civil valido! \n";
                validacao = 1;
        }
    }while(validacao == 1);

    cout << "Tudo certo!\n";
    
    return 0;
}