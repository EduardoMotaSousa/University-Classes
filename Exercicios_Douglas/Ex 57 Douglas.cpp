#include <iostream>

using namespace std;

//gerador de tabuada, capaz de gerar a tabuada de qualquer número inteiro entre 1 a 10. O usuário deve informar de qual numero ele deseja ver a tabuada. 
//A saída deve ser conforme o exemplo abaixo: Tabuada de 5: 5 X 1 = 5 5 X 2 = 10 ... 5 X 10 = 50

int main() {
    int validacao, num;

    //entra dados
    do{ 
        validacao = 0;
        cout << "Qual num gostaria de saber a tabuada de 1 a 10? ";
        cin >> num;

        //valida
        if(num < 1 || num > 10){
            cout << "DIGITE UM NUM VALIDO!!!\n";
            validacao = 1;
        }

    } while(validacao == 1);

    //exibe
    cout << "Tabuada de " << num << ": \n";

    for(int i = 1; i <= 10; i++){
        cout << num << " X " << i << " = " << num * i << endl;
    }
  
    return 0;
}