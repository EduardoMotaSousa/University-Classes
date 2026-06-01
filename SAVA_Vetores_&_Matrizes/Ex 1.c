#include <stdio.h>

int main() {
    int num, maior = 0;

    for (int i = 0; i<= 5; i++) {
        scanf("%d", &num);
        if(num>maior){
            maior = num;
        }
    }

    printf("O maior dos números lidos é: \n %d", maior);

    return 0;
}