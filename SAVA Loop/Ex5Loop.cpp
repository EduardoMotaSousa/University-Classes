#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float n1, n2, n3;
    int cont;

    for(cont = 0; cont < 40; cont++){
        cout << "N1:";
        cin >> n1;

        cout << "N2:";
        cin >> n2;

        cout << "N3:";
        cin >> n3;

        if(((n1+n2+n3) / 3) >= 7){
            cout << "Este aluno está aprovado!\n";
        }
        else{
            cout << "REPROVADO\n";
        }
    }

    return 0;
}