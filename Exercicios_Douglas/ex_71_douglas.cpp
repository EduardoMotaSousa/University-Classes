#include <iostream>
using namespace std;

//Faça um programa que calcule o número médio de alunos. Para isto, peça a quantidade de turmas e a quantidade de alunos para cada turma. 
//As turmas não podem ter mais de 40 alunos.

int main() {
    int turma, alunos, media{};

    do{
	cout << "Quantas turmas tem? ";
	cin >> turma;
    }while(turma < 1);

    for(int i = 1; i <= turma; i++){ 
	cout << "Quantos alunos tem na turma " << i << "?\n";
	cin >> alunos;

	if(alunos < 0){
	     cout << "Coloque um numero valido!\n";
	     i--;
	}
     
	else if(alunos <= 40){
	    media += alunos;
	}
	
	else{
	     cout << "As tumas não podem ter mais de 40 alunos!\n";
	     i--;
	}
    }

    cout << "O numero medio de alunos é: " << (double)media / turma << endl;    

    return 0;
}