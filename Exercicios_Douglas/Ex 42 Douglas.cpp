#include <iostream>
#include <cmath>
using namespace std;

//faça 5 perguntas para uma pessoa sobre um crime. As perguntas são: "Telefonou para a vítima?" "Esteve no local do crime?" "Mora perto da vítima?" "Devia para a vítima?" "Já trabalhou com a vítima?"

//O programa deve no final emitir uma classificação sobre a participação da pessoa no crime.

//Se a pessoa responder positivamente a 2 questões ela deve ser classificada como "Suspeita", entre 3 e 4 como "Cúmplice" e 5 como "Assassino". Caso contrário, ele será classificado como "Inocente".

int main(){
    int culpa{};
    char resp;
    std::string perguntas[5] = {"Telefonou para a vítima?", "Esteve no local do crime?", "Mora perto da vítima?", "Devia para a vítima?", "Já trabalhou com a vítima?"};

    for(int i = 0; i < 5; i++){
        cout << perguntas[i] << "\nResponda (S/N): ";
        cin >> resp;

        if(resp == 's' || resp == 'S'){
            culpa++;
        }
    }

    if(culpa == 0){
        cout << "Inocente\n";
    }

    else if(culpa <= 2){
        cout << "Suspeito\n";
    }

    else if(culpa <= 4){
        cout << "Cumplice\n";
    }
    
    else{
        cout << "Assassino\n";
    }

    return 0;
}