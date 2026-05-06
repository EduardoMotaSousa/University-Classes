#include <iostream>
#include <iomanip>
using namespace std;

// Faça um Programa que pergunte em que turno você estuda. 
// Peça para digitar M-matutino ou V-Vespertino ou N- Noturno.
// Imprima a mensagem "Bom Dia!", "Boa Tarde!" ou "Boa Noite!" ou "Valor Inválido!", 
// conforme o caso.

int main(){
    char turno;

    cout << "Qual seu turno (M-matutino ou V-Vespertino ou N- Noturno)? ";
    cin >> turno;

    if(turno == 'M'){
        cout << "Bom Dia!";
    }

    else if(turno == 'V'){
        cout << "Boa Tarde!";
    }
    
    else{
        cout << "Boa Noite!";
    }

    return 0;
}