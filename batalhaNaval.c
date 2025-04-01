#include <stdio.h>

int inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    return 0;
}

int validarPosicaoNavio(int tabuleiro[10][10], int linha, int coluna, int direcao, int tamanhoNavio) {
    // Verifica o navio dentro do tabuleiro e se não há sobreposição
    if (direcao == 0) { // Horizontal
        if (coluna + tamanhoNavio > 10) return 0; // Verifica se o navio não ultrapassa horizontal
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Verifica se já tem navio na posição
        }
    } else { // Vertical
        if (linha + tamanhoNavio > 10) return 0; // Verifica se o navio não ultrapassa vertical
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica se já tem navio na posição
        }
    }
    return 1; // tudo ok
}

int posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int direcao, int tamanhoNavio) {
    if (!validarPosicaoNavio(tabuleiro, linha, coluna, direcao, tamanhoNavio)) {
        return 0; // se tiver erro posicao
    }

    // Posiciona o navio
    for (int i = 0; i < tamanhoNavio; i++) {
        if (direcao == 0) { // Horizontal
            tabuleiro[linha][coluna + i] = 3;  // Coloca o navio na linha especificada
            tabuleiro[linha + i][coluna] = 3;  // Coloca o navio na coluna especificada
        }
    }
    return 1; // Sucesso
}

int imprimirTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    int tabuleiro[10][10];
    int tamanhoNavio = 3;
    inicializarTabuleiro(tabuleiro);

    //tabuleiro inicial com todos os valores como 0
    printf("Tabuleiro Inicial:\n");
    imprimirTabuleiro(tabuleiro);
    
    // variáveis para coordenadas dos navios
    int linhaH, colunaH;
    int linhaV, colunaV;
    
    // Pergunta as coordenadas do navio horizontal
    printf("\nDigite as coordenadas para o navio horizontal:\n");
    printf("Linha (0-9): ");
    scanf("%d", &linhaH);
    printf("Coluna (0-9): ");
    scanf("%d", &colunaH);
    
    // Posicionahorizontal
    if (!posicionarNavio(tabuleiro, linhaH, colunaH, 0, tamanhoNavio)) {
        printf("Erro ao posicionar o navio horizontal! Verifique as coordenadas e tente novamente.\n");
        return 1;
    }
    
    // Perguntar ao usuário as coordenadas do navio vertical
    printf("\nDigite as coordenadas para o navio vertical:\n");
    printf("Linha (0-9): ");
    scanf("%d", &linhaV);
    printf("Coluna (0-9): ");
    scanf("%d", &colunaV);
    
    // Posicionar o navio vertical
    if (!posicionarNavio(tabuleiro, linhaV, colunaV, 1, tamanhoNavio)) {
        printf("Erro ao posicionar o navio vertical! Verifique as coordenadas e tente novamente.\n");
        return 1;
    }

    // Exibir o tabuleiro após o posicionamento dos navios
    printf("\nTabuleiro com os Navios Posicionados:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
