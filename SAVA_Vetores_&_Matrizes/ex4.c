#include <stdio.h>

int main(){
    int par= 0, impar = 0, matriz[3][4];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &matriz[i][j]);
        }        
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(matriz[i][j] % 2 == 0){
                par++;
            }
            else{
                impar++;
            }
        }        
    }

    printf("Pares: %d \nImpares: %d", par, impar);

    return 0;
}