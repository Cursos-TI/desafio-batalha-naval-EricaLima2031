#include <stdio.h>
#include <stdlib.h>

#define TABULEIRO 10
#define NAVIO 3
#define HABILIDADE 5

int main() {

    char colunas [10] = {'A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int linhas [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro [TABULEIRO][TABULEIRO] = {0};
   

    // Posicionando os navio 
    int linha_h =3, coluna_h = 2;
    for (int i = 0; i < 3; i++){
        tabuleiro[linha_h][coluna_h + i] = NAVIO;
    }
    // Posicionando o navio na vertical
    int linha_v = 5, coluna_v = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_v + i][coluna_v] = NAVIO;
    }
    // Posicionando os navios na Diagonalmente
    int linha_d1 = 2, coluna_d1 = 2;
    for(int i = 0; i < 3; i++) {
        if (linha_d1 + i < TABULEIRO && coluna_d1 + i < TABULEIRO) {
    tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;
       }     
    }
    int linha_d2 = 6, coluna_d2 = 8;
    for(int i = 0; i < 3; i++) {
        if (linha_d2 - i >= 0 && coluna_d2 - i >= 0) {
    tabuleiro[linha_d2 - i][coluna_d2 - i] = NAVIO;
        }
    }
    // Habilidade Cruz
    int origem_cruz_linha = 2, origem_cruz_coluna = 5;
    for (int i = -2; i <= 2; i ++) {
        if (origem_cruz_linha + i >= 0 && origem_cruz_linha + i < TABULEIRO) {
            tabuleiro[origem_cruz_linha][origem_cruz_coluna] = HABILIDADE;
        }
        if (origem_cruz_coluna + i >= 0 && origem_cruz_coluna + i < TABULEIRO) {
            tabuleiro[origem_cruz_linha][origem_cruz_coluna + i] = HABILIDADE;
        }
    }
     // Habilidade Cone
    int origem_cone_linha = 7, origem_cone_coluna = 5;
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (origem_cone_linha + i < TABULEIRO && origem_cone_coluna + j >= 0 && origem_cone_coluna + j < TABULEIRO) {
                tabuleiro[origem_cone_linha + i][origem_cone_coluna + j] = HABILIDADE;
            }
        }
    }
    // Habilidade Octaedro
    int origem_octaedro_linha = 5, origem_octaedro_coluna = 2;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2 + abs(i); j <= 2 - abs(i); j++) {
            if (origem_octaedro_linha + i >= 0 && origem_octaedro_linha + i < TABULEIRO &&
                origem_octaedro_coluna + j >= 0 && origem_octaedro_coluna + j < TABULEIRO) {
                tabuleiro[origem_octaedro_linha + i][origem_octaedro_coluna + j] = HABILIDADE;
            }
        }
    }
    // Exibindo o tabuleiro
       printf ("*** Tabuleiro Batalha Naval ***\n\n");
       printf ("  ");       
       for (int j = 0; j < TABULEIRO; j++) {
              printf(" %c", colunas[j]);
       }
       printf("\n");
       
       for (int i = 0; i < TABULEIRO; i++) {
              printf("%2d", linhas[i]);
              for (int j = 0; j < TABULEIRO; j++) {
                printf (" %d", tabuleiro[i][j]);
                    
            }
        printf("\n");
    }

    return 0;
}