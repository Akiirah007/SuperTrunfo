#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        return (linha >= 0) && (linha + tamanho - 1 < TAMANHO_TABULEIRO) && 
               (coluna >= 0) && (coluna < TAMANHO_TABULEIRO);
    } else {
        return (linha >= 0) && (linha < TAMANHO_TABULEIRO) && 
               (coluna >= 0) && (coluna + tamanho - 1 < TAMANHO_TABULEIRO);
    }
}

// Função para verificar sobreposição de navios
bool semSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            if (tabuleiro[i][coluna] != AGUA) {
                return false;
            }
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            if (tabuleiro[linha][j] != AGUA) {
                return false;
            }
        }
    }
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                    int linha, int coluna, int tamanho, bool vertical) {
    if (vertical) {
        for (int i = linha; i < linha + tamanho; i++) {
            tabuleiro[i][coluna] = NAVIO;
        }
    } else {
        for (int j = coluna; j < coluna + tamanho; j++) {
            tabuleiro[linha][j] = NAVIO;
        }
    }
}

// Função para criar a matriz de habilidade em formato de Cone
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cone apontando para baixo - a largura aumenta com a linha
            if (j >= centro - i && j <= centro + i && i <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em formato de Cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cruz - linha central ou coluna central
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em formato de Octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Losango - soma das distâncias ao centro <= raio
            int distVertical = abs(i - centro);
            int distHorizontal = abs(j - centro);
            if (distVertical + distHorizontal <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                      int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                      int linha_centro, int coluna_centro) {
    int offset = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linha_tab = linha_centro - offset + i;
            int coluna_tab = coluna_centro - offset + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAMANHO_TABULEIRO &&
                coluna_tab >= 0 && coluna_tab < TAMANHO_TABULEIRO) {
                // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = HABILIDADE;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n");
    printf("Legenda: 0=Água | 3=Navio | 5=Habilidade\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios (coordenadas fixas)
    posicionarNavio(tabuleiro, 2, 3, TAMANHO_NAVIO, false); // Navio horizontal
    posicionarNavio(tabuleiro, 5, 7, TAMANHO_NAVIO, true);  // Navio vertical
    
    // Cria as matrizes de habilidades
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);
    
    // Aplica as habilidades ao tabuleiro (coordenadas fixas)
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone centrado em (4,4)
    aplicarHabilidade(tabuleiro, cruz, 2, 6);      // Cruz centrada em (2,6)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);  // Octaedro centrado em (7,2)
    
    // Imprime o tabuleiro
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}