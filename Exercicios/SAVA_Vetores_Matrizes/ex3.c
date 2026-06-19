#include <stdio.h>

int main () {
    int notas[20], media = 0;

    //le as notas da turma
    for (int i = 0; i < 20; i++){
        scanf("%d", &notas[i]);
        media += notas[i];
    }

    media /= 20;

    //verifica os iguais ou menor que a media

    printf("Notas maiores ou iguais a média: ");
    
    for(int i = 0; i < 20; i++){
        if(notas[i] >= media){
            printf(" %d", notas[i]);
        }
    }
}