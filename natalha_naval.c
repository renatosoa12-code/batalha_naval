#include <stdio.h>

int matriz[10][10] = { 0 };

int main() {

    matriz[4][1] = 3;
    matriz[3][1] = 3;
    matriz[4][6] = 3;
    matriz[4][7] = 3;
    matriz[4][8] = 3;
    
    for (int linha = 0; linha < 10; linha++) {

        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", matriz[linha][coluna]);
        }

        printf("\n");
    }

	return 0;
}