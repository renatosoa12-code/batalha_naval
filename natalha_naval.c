#include <stdio.h>

int main() {

    int matriz[11][11] = { 0 };

    // Cabeçalho superior (1 a 10)
    for (int c = 1; c <= 10; c++) {
        matriz[0][c] = c;
    }

    // Cabeçalho lateral (A a J)
    for (int l = 1; l <= 10; l++) {
        matriz[l][0] = 'A' + (l - 1);
    }

    // ============================
    // POSICIONAMENTO DOS NAVIOS
    // ============================

    // 1) Navio VERTICAL (tamanho 2) em B3 (linhas 2 e 3, coluna 3)
    matriz[2][3] = 3;
    matriz[3][3] = 3;

    // 2) Navio HORIZONTAL (tamanho 3) em F5 (linha 6, colunas 5,6,7)
    matriz[6][5] = 3;
    matriz[6][6] = 3;
    matriz[6][7] = 3;

    // 3) Navio DIAGONAL 1 (tamanho 3) começando em H2
    // posições: H2, I3, J4
    matriz[8][2] = 3;
    matriz[9][3] = 3;
    matriz[10][4] = 3;

    // 4) Navio DIAGONAL 2 (tamanho 3) começando em C8
    // posições: C8, D9, E10
    matriz[3][8] = 3;
    matriz[4][9] = 3;
    matriz[5][10] = 3;

    // ============================
    // IMPRESSÃO DA TABELA
    // ============================

    for (int l = 0; l < 11; l++) {
        for (int c = 0; c < 11; c++) {

            if (l == 0 && c == 0)
                printf("    ");
            else if (l == 0)
                printf("%4d", matriz[l][c]);
            else if (c == 0)
                printf("%4c", matriz[l][c]);
            else
                printf("%4d", matriz[l][c]);

        }
        printf("\n");
    }

    return 0;
}
