#include <stdio.h>

#define tamanhotabuleiro 10
#define habaltura 3
#define hablargura 5
#define tamanhonavio 3

void iniciatabuleiro(int tabuleiro[tamanhotabuleiro][tamanhotabuleiro]) {
    for (int i = 0; i < tamanhotabuleiro; i++) {
        for (int j = 0; j < tamanhotabuleiro; j++) {
            tabuleiro[i][j] = 0; // Define água como 0
        }
    }
}

void criarcone(int matriz[habaltura][hablargura]) {
    for (int i = 0; i < habaltura; i++) {
        for (int j = 0; j < hablargura; j++) {
            matriz[i][j] = (j >= hablargura / 2 - i && j <= hablargura / 2 + i) ? 1 : 0;
        }
    }
}

void criarcruz(int matriz[habaltura][hablargura]) {
    for (int i = 0; i < habaltura; i++) {
        for (int j = 0; j < hablargura; j++) {
            matriz[i][j] = (i == habaltura / 2 || j == hablargura / 2) ? 1 : 0;
        }
    }
}

void criaroctaedro(int matriz[habaltura][hablargura]) {
    for (int i = 0; i < habaltura; i++) {
        for (int j = 0; j < hablargura; j++) {
            matriz[i][j] = (abs(habaltura / 2 - i) + abs(hablargura / 2 - j) <= habaltura / 2) ? 1 : 0;
        }
    }
}

void aplicahabilidade(int tabuleiro[tamanhotabuleiro][tamanhotabuleiro], int matriz[habaltura][hablargura], int origemX, int origemY) {
    for (int i = 0; i < habaltura; i++) {
        for (int j = 0; j < hablargura; j++) {
            int x = origemX + i - habaltura / 2;
            int y = origemY + j - hablargura / 2;
            if (x >= 0 && x < tamanhotabuleiro && y >= 0 && y < tamanhotabuleiro && matriz[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca área habilidade
            }
        }
    }
}

void posicaonavio(int tabuleiro[tamanhotabuleiro][tamanhotabuleiro], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna - 1 >= 0 && coluna + 1 < tamanhotabuleiro) {
            tabuleiro[linha][coluna - 1] = 3;
            tabuleiro[linha][coluna] = 3;
            tabuleiro[linha][coluna + 1] = 3;
        }
    } else if (orientacao == 'V') {
        if (linha - 1 >= 0 && linha + 1 < tamanhotabuleiro) {
            tabuleiro[linha - 1][coluna] = 3;
            tabuleiro[linha][coluna] = 3;
            tabuleiro[linha + 1][coluna] = 3;
        }
    }
}

void printftabuleiro(int tabuleiro[tamanhotabuleiro][tamanhotabuleiro]) {
    for (int i = 0; i < tamanhotabuleiro; i++) {
        for (int j = 0; j < tamanhotabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void armazenaposicao(int *valor, int limite, char *mensagem) {
    do {
        printf("%s (0-%d): ", mensagem, limite - 1);
        scanf("%d", valor);
    } while (*valor < 0 || *valor >= limite);
}

int main() {
    int tabuleiro[tamanhotabuleiro][tamanhotabuleiro];
    iniciatabuleiro(tabuleiro);
    
    printftabuleiro(tabuleiro);
    
    int cone[habaltura][hablargura];
    int cruz[habaltura][hablargura];
    int octaedro[habaltura][hablargura];
    
    criarcone(cone);
    criarcruz(cruz);
    criaroctaedro(octaedro);
    
    int linha, coluna;
    char orientacao;
    
    // escolher pos navio
    printf("Posicione o seu navio no mapa:\n");
    armazenaposicao(&linha, tamanhotabuleiro, "Escolha a linha");
    armazenaposicao(&coluna, tamanhotabuleiro, "Escolha a coluna");
    do {
        printf("Escolha a orientação (H para horizontal, V para vertical): ");
        scanf(" %c", &orientacao);
    } while (orientacao != 'H' && orientacao != 'V');
    posicaonavio(tabuleiro, linha, coluna, orientacao);
    
    // escolher pos habilidades
    printf("Posicione a sua habilidade Cruz:\n");
    armazenaposicao(&linha, tamanhotabuleiro, "Escolha a linha");
    armazenaposicao(&coluna, tamanhotabuleiro, "Escolha a coluna");
    aplicahabilidade(tabuleiro, cruz, linha, coluna);
    
    printf("Posicione a sua habilidade Cone:\n");
    armazenaposicao(&linha, tamanhotabuleiro, "Escolha a linha");
    armazenaposicao(&coluna, tamanhotabuleiro, "Escolha a coluna");
    aplicahabilidade(tabuleiro, cone, linha, coluna);
    
    printf("Posicione a sua habilidade Octaedro:\n");
    armazenaposicao(&linha, tamanhotabuleiro, "Escolha a linha");
    armazenaposicao(&coluna, tamanhotabuleiro, "Escolha a coluna");
    aplicahabilidade(tabuleiro, octaedro, linha, coluna);
    
    printftabuleiro(tabuleiro);
    
    return 0;
}
