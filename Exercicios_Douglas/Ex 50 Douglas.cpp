#include <iostream>

using namespace std;

//Altere o programa anterior permitindo ao usuário informar as populações e as taxas de crescimento iniciais. Valide a entrada e permita repetir a operação.

int main() {
    int paisa, paisb, validacao;
    char repetir;
    double taxaa, taxab;

    do{ 
        int anos = 0;

        //entrada populações
        do{  
            validacao = 1;

            cout << "População país A(Com a menor poupulação): ";
            cin >> paisa;

            cout << "População país B(Com a maior poupulação): ";
            cin >> paisb;

            if (paisa >= paisb){
                cout << "Coloque uma população valida, A população do A já é maior ou igual do que a do B!\n";
                validacao = 0;
            }

            if (paisa <= 0 || paisb <= 0){
                cout << "Coloque uma população valida, maior do que zero!\n";
                validacao = 0;
            }

        } while(validacao == 0);
        

        //entrada taxas
        do{
            validacao = 1;

            cout << "Taxa de cresciemnto país A: ";
            cin >> taxaa;

            cout << "Taxa de cresciemnto país B: ";
            cin >> taxab;

            if (taxaa <= taxab){
                cout << "Coloque uma taxa valida, se a taxa do país A for menor que o B, ele nunca vai ultrapassar!\n";
                validacao = 0;
            }

        } while (validacao == 0);

        //calculo
        while(paisa < paisb){
            paisa *= 1 + taxaa / 100;
            paisb *= 1 + taxab / 100;
            anos++;
        }
        
        cout << "O país A vai demorar " <<  anos << " anos para ultrapaçar o pais B"
            << "\nA: " << paisa << "\nB: " << paisb << endl
            << "\n\nGostaria de repetir?(S/N)";
        
        cin >> repetir;
    
    } while(repetir == 'S' || repetir == 's');

    return 0;
}