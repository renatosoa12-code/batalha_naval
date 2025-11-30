#include <stdio.h>

// substitui abs() para evitar stdlib.h
int meuAbs(int x) {
    return (x < 0) ? -x : x;
}

#define TAM 10
#define HAB 5

int main() {
    char campo[TAM][TAM];

    // Preenche o campo com água '~'
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            campo[i][j] = '~';
        }
    }

    // ===== POSICIONAMENTO DOS BARCOS =====
    // Barco horizontal tamanho 2 (linha 2, colunas B e C)
    campo[1][1] = '0';
    campo[1][2] = '0';

    // Barco vertical tamanho 3 (coluna F, linhas 5,6,7)
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

    // ===================================================
    // MATRIZES DE HABILIDADE (0 = fora, 1 = dentro)
    // ===================================================
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // ----- CONE (apontando para baixo) -----
    // formato (5x5), topo no i=0 col central j=2
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == 0 && j == 2) {
                cone[i][j] = 1;
            }
            else if (i == 1 && j >= 1 && j <= 3) {
                cone[i][j] = 1;
            }
            else if (i == 2) {
                cone[i][j] = 1;
            }
            else {
                cone[i][j] = 0;
            }
        }
    }

    // ----- CRUZ -----
    // cruz com origem no centro (linha 2, coluna 2 de 0..4)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
            else {
                cruz[i][j] = 0;
            }
        }
    }

    // ----- OCTAEDRO (losango) -----
    // usa distância manhattan a partir do centro (2,2)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (meuAbs(i - 2) + meuAbs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
            else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ===================================================
    // SOBREPOR AS HABILIDADES NO TABULEIRO
    // ===================================================
    // ORIGENS escolhidas (linhas/colunas em 0..9)
    int origem_cone_l = 3, origem_cone_c = 5; // cone: centro superior
    int origem_cruz_l = 5, origem_cruz_c = 5; // cruz: centro
    int origem_octa_l = 7, origem_octa_c = 4; // octaedro: centro inferior

    // percorre cada matriz de habilidade e aplica
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            // CONE
            if (cone[i][j] == 1) {
                int L = origem_cone_l + (i - 2);
                int C = origem_cone_c + (j - 2);
                if (L >= 0 && L < TAM && C >= 0 && C < TAM) {
                    // preserva navio '0' se houver; caso contrário marca '5'
                    if (campo[L][C] != '0') {
                        campo[L][C] = '5';
                    }
                }
            }

            // CRUZ
            if (cruz[i][j] == 1) {
                int L = origem_cruz_l + (i - 2);
                int C = origem_cruz_c + (j - 2);
                if (L >= 0 && L < TAM && C >= 0 && C < TAM) {
                    if (campo[L][C] != '0') {
                        campo[L][C] = '5';
                    }
                }
            }

            // OCTAEDRO
            if (octaedro[i][j] == 1) {
                int L = origem_octa_l + (i - 2);
                int C = origem_octa_c + (j - 2);
                if (L >= 0 && L < TAM && C >= 0 && C < TAM) {
                    if (campo[L][C] != '0') {
                        campo[L][C] = '5';
                    }
                }
            }
        }
    }

    // ===================================================
    // IMPRESSÃO DO TABULEIRO
    // ===================================================
    // Letras no topo
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Números laterais + conteúdo
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}
