#include <iostream>
using namespace std;

int main(){
    char palavra[21];
    int t{};

    cin >> palavra;

    //determina tamanho do vetor
    while(palavra[t] != '\0'){
        t += 1;
    }


    //compara se é Palindromo
    for(int i = 0; i <= t; i++){
        if(palavra[i] != palavra[t-1]){
            cout << "Não é palindromo";
            return 0;
        }
        t--;
    }

    cout << "É palindromo";

    return 0;
}