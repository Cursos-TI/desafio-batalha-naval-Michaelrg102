#include <stdio.h>

#define TAM 10
#define H 5

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int campo[TAM][TAM], int habilidade[H][H], int origemLinha, int origemColuna) {

    int meio = H / 2;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            if (habilidade[i][j] == 1) {

                int linhaTab = origemLinha + (i - meio);
                int colunaTab = origemColuna + (j - meio);

                // Verifica limites do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM &&
                    colunaTab >= 0 && colunaTab < TAM) {

                    // Marca apenas se for água
                    if (campo[linhaTab][colunaTab] == 0) {
                        campo[linhaTab][colunaTab] = 5;
                    }
                }
            }
        }
    }
}

int main () {

    int campo[TAM][TAM];

    // ===== Inicializar tabuleiro com água =====
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            campo[i][j] = 0;
        }
    }

    // ===== Navios =====
    // Horizontais
    for (int j = 2; j < 5; j++) campo[1][j] = 3;
    for (int j = 5; j < 8; j++) campo[6][j] = 3;

    // Diagonais
    for (int i = 0; i < 3; i++) campo[3 + i][3 + i] = 3;
    for (int i = 0; i < 3; i++) campo[8 - i][1 + i] = 3;

    // ===== CONE =====
    int cone[H][H];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            if (j >= (H/2 - i) && j <= (H/2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // ===== CRUZ =====
    int cruz[H][H];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            if (i == H/2 || j == H/2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // ===== OCTAEDRO =====
    int octaedro[H][H];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {

            int di = i - H/2;
            int dj = j - H/2;

            if (di < 0) di = -di;
            if (dj < 0) dj = -dj;

            if (di + dj <= H/2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ===== Aplicar habilidades =====
    aplicarHabilidade(campo, cone, 2, 2);
    aplicarHabilidade(campo, cruz, 5, 5);
    aplicarHabilidade(campo, octaedro, 7, 7);

    // ===== Exibir tabuleiro =====
    printf("=== TABULEIRO FINAL ===\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}