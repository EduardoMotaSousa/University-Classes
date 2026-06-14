#include <stdio.h>

int main() {
    int cem[100];

    for (int i = 0; i < 100; i++){
        scanf("%d", &cem[i]);
    }

    for (int i = 99; i >= 0; i--){
        printf("%d", cem[i]);
    }

    return 0;
}