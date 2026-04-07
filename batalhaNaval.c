#include <stdio.h>

int main (){

    const int linhas = 10;
    const int colunas = 10;

    int campo[linhas][colunas];

    // Preencher com 0
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            campo[i][j] = 0;
        }
    }

    // ===== Barcos horizontais (tamanho 3) =====
    // Barco 1
    for (int j = 2; j < 5; j++){ // 3 posições
        campo[1][j] = 3;
    }

    // Barco 2
    for (int j = 5; j < 8; j++){
        campo[6][j] = 3;
    }

    // ===== Barcos diagonais (tamanho 3) =====
    for (int i = 0; i < 3; i++){
        campo[3 + i][3 + i] = 3;
    }

    for (int i = 0; i < 3; i++){
        campo[8 - i][1 + i] = 3;
    }

    // Mostrar o campo
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }

    return 0;
}