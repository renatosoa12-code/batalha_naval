#include <stdio.h>

int main() {

    char campo[10][10];

    // Preenche o campo com '~'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            campo[i][j] = '~';
        }
    }

    // ===== POSICIONAMENTO DOS BARCOS =====

    // Barco horizontal de tamanho 2 (linha 2, colunas B e C)
    campo[1][1] = '0';
    campo[1][2] = '0';

    // Barco vertical de tamanho 3 (coluna F, linhas 5,6,7)
    campo[4][5] = '0';
    campo[5][5] = '0';
    campo[6][5] = '0';

    // Barco diagonal tamanho 3 (diagonal principal)
    campo[2][7] = '0';
    campo[3][8] = '0';
    campo[4][9] = '0';

    // Barco diagonal tamanho 3 (diagonal invertida)
    campo[8][2] = '0';
    campo[7][3] = '0';
    campo[6][4] = '0';

    // ===== IMPRESSÃO DO TABULEIRO =====

    // Letras no topo
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Números laterais + conteúdo da matriz
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%c ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
