#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Struct para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para exibir um menu e retornar a opção válida
int exibirMenu(const char* titulo, const char* opcoes[], int numOpcoes, int opcaoRemovida) {
    int opcao;
    bool entradaValida = false;

    while (!entradaValida) {
        printf("\n%s\n", titulo);
        for (int i = 0; i < numOpcoes; i++) {
            if (i != opcaoRemovida) {
                printf("%d. %s\n", i + 1, opcoes[i]);
            }
        }
        printf("Opção (1 a %d): ", numOpcoes);
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        if (opcao < 1 || opcao > numOpcoes || opcao == opcaoRemovida + 1) {
            printf("Opção inválida! Tente novamente.\n");
        } else {
            entradaValida = true;
        }
    }
    return opcao;
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta, int numeroCarta) {
    printf("\n--- Carta %d ---\n", numeroCarta);

    printf("Digite a letra do estado: ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (3 letras): ");
    scanf("%3s", carta->codigo);

    getchar(); // Limpa o buffer
    printf("Digite o nome da cidade: ");
    fgets(carta->cidade, 50, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0'; // Remove a quebra de linha

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em trilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite os pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculos automáticos
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + carta->pib_per_capita + (1 / carta->densidade);
}

int main() {
    Carta carta1, carta2;
    char continuar;

    // Cadastro inicial das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    do {
        // Atributos disponíveis para comparação
        const char* atributos[] = {
            "População",
            "Área",
            "PIB",
            "Pontos Turísticos",
            "PIB per capita",
            "Densidade Demográfica",
            "Super Poder"
        };

        // Menu para escolher o primeiro atributo
        int opcao1 = exibirMenu(
            "ESCOLHA O PRIMEIRO ATRIBUTO:",
            atributos, 
            7, 
            -1
        );

        // Menu para escolher o segundo atributo (dinâmico)
        int opcao2 = exibirMenu(
            "ESCOLHA O SEGUNDO ATRIBUTO (DIFERENTE DO PRIMEIRO):",
            atributos, 
            7, 
            opcao1 - 1
        );

        // Valores dos atributos selecionados
        float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;

        // Obtém valores do primeiro atributo
        switch(opcao1) {
            case 1: valor1_carta1 = carta1.populacao; valor1_carta2 = carta2.populacao; break;
            case 2: valor1_carta1 = carta1.area; valor1_carta2 = carta2.area; break;
            case 3: valor1_carta1 = carta1.pib; valor1_carta2 = carta2.pib; break;
            case 4: valor1_carta1 = carta1.pontos_turisticos; valor1_carta2 = carta2.pontos_turisticos; break;
            case 5: valor1_carta1 = carta1.pib_per_capita; valor1_carta2 = carta2.pib_per_capita; break;
            case 6: valor1_carta1 = carta1.densidade; valor1_carta2 = carta2.densidade; break;
            case 7: valor1_carta1 = carta1.super_poder; valor1_carta2 = carta2.super_poder; break;
        }

        // Obtém valores do segundo atributo
        switch(opcao2) {
            case 1: valor2_carta1 = carta1.populacao; valor2_carta2 = carta2.populacao; break;
            case 2: valor2_carta1 = carta1.area; valor2_carta2 = carta2.area; break;
            case 3: valor2_carta1 = carta1.pib; valor2_carta2 = carta2.pib; break;
            case 4: valor2_carta1 = carta1.pontos_turisticos; valor2_carta2 = carta2.pontos_turisticos; break;
            case 5: valor2_carta1 = carta1.pib_per_capita; valor2_carta2 = carta2.pib_per_capita; break;
            case 6: valor2_carta1 = carta1.densidade; valor2_carta2 = carta2.densidade; break;
            case 7: valor2_carta1 = carta1.super_poder; valor2_carta2 = carta2.super_poder; break;
        }

        // Comparação individual (Densidade: menor vence)
        int resultado1 = (opcao1 == 6) ? 
            (valor1_carta1 < valor1_carta2 ? 1 : (valor1_carta1 > valor1_carta2 ? -1 : 0)) :
            (valor1_carta1 > valor1_carta2 ? 1 : (valor1_carta1 < valor1_carta2 ? -1 : 0));

        int resultado2 = (opcao2 == 6) ? 
            (valor2_carta1 < valor2_carta2 ? 1 : (valor2_carta1 > valor2_carta2 ? -1 : 0)) :
            (valor2_carta1 > valor2_carta2 ? 1 : (valor2_carta1 < valor2_carta2 ? -1 : 0));

        // Soma para desempate
        float soma_carta1 = valor1_carta1 + valor2_carta1;
        float soma_carta2 = valor1_carta2 + valor2_carta2;

        // Exibição do resultado
        printf("\n=== RESULTADO ===\n");
        printf("Carta 1: %s (%s)\n", carta1.cidade, carta1.codigo);
        printf("Carta 2: %s (%s)\n", carta2.cidade, carta2.codigo);

        printf("\nAtributos comparados:\n");
        printf("1. %s: Carta 1 = %.2f | Carta 2 = %.2f\n", atributos[opcao1 - 1], valor1_carta1, valor1_carta2);
        printf("2. %s: Carta 1 = %.2f | Carta 2 = %.2f\n", atributos[opcao2 - 1], valor2_carta1, valor2_carta2);

        printf("\nSoma dos atributos:\n");
        printf("Carta 1: %.2f | Carta 2: %.2f\n", soma_carta1, soma_carta2);

        // Decisão final
        if (soma_carta1 > soma_carta2) {
            printf("\n🏆 Carta 1 vence!\n");
        } else if (soma_carta2 > soma_carta1) {
            printf("\n🏆 Carta 2 vence!\n");
        } else {
            printf("\n🤝 Empate!\n");
        }

        // Ranking de atributos (opcional)
        printf("\n📊 Ranking de Atributos (Maior Soma):\n");
        printf("1. %s: %.2f\n", atributos[opcao1 - 1], valor1_carta1 + valor1_carta2);
        printf("2. %s: %.2f\n", atributos[opcao2 - 1], valor2_carta1 + valor2_carta2);

        // Pergunta se deseja continuar
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpa o buffer

    } while (tolower(continuar) == 's');

    printf("\nFim do jogo! Obrigado por jogar Super Trunfo! 🎉\n");
    return 0;
}