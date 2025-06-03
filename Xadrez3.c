#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento do Bispo
void moverBispo(int casas) {
    if (casas <= 0) return;
    printf("Cima, Direita\n");
    moverBispo(casas - 1);
}

// Implementação alternativa do Bispo com loops aninhados
void moverBispoAninhado(int casas) {
    for (int i = 0; i < casas; i++) {
        for (int j = 0; j < 1; j++) { // Loop interno para representar a diagonal
            printf("Cima, Direita\n");
        }
    }
}

// Função recursiva para o movimento da Rainha
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função para o movimento complexo do Cavalo
void moverCavalo() {
    // Movimento em L: 2 casas para cima e 1 para direita
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            if (i < 2) {
                printf("Cima\n");
                continue; // Continua para as primeiras 2 casas
            }
            printf("Direita\n");
            break; // Sai após o movimento final
        }
    }
}

int main() {
    // Movimento da Torre usando recursão (5 casas)
    printf("Movimento da Torre (5 casas para a direita) - Recursivo:\n");
    moverTorre(5);
    
    printf("\n");
    
    // Movimento do Bispo usando recursão (5 casas)
    printf("Movimento do Bispo (5 casas na diagonal) - Recursivo:\n");
    moverBispo(5);
    
    printf("\n");
    
    // Movimento do Bispo usando loops aninhados (5 casas)
    printf("Movimento do Bispo (5 casas na diagonal) - Loops Aninhados:\n");
    moverBispoAninhado(5);
    
    printf("\n");
    
    // Movimento da Rainha usando recursão (8 casas)
    printf("Movimento da Rainha (8 casas para a esquerda) - Recursivo:\n");
    moverRainha(8);
    
    printf("\n");
    
    // Movimento do Cavalo com loops complexos (2 cima, 1 direita)
    printf("Movimento do Cavalo (2 casas para cima e 1 para direita) - Loops Complexos:\n");
    moverCavalo();
    
    return 0;
}