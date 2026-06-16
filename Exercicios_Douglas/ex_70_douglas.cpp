#include <iostream>
using namespace std;

//Numa eleição existem três candidatos. Faça um programa que peça o número total de eleitores. Peça para cada eleitor votar e ao final mostrar o número de 
//votos de cada candidato.

int main() {
    int voto, eleitores, candidatos[4] = {0};

    do{ 
        cout << "Quantos eleitores existem? ";
        cin >> eleitores;
    }while(eleitores <= 0);


    for(int i = 1; i <= eleitores; i++){
        cout << "Eleitor N°" << i << " irá votar em qual canditado?(1, 2, 3 ou outro para nulo): ";
        cin >> voto;

        switch (voto)
        {
        case 1:
            candidatos[0]++;
            break;
        
        case 2:
            candidatos[1]++;
            break;

        case 3:
            candidatos[2]++;
            break;
        
        default:
            candidatos[3]++;
            cout << "SEU VOTO FOI NULO!\n";
            break;
        }
    }

    cout << "Candidato A: " << candidatos[0]
        << "\nCandidato B: " << candidatos[1]
        << "\nCandidato C: " << candidatos[2]
        << "\nNulos: " << candidatos[3] << endl;

    return 0;
}