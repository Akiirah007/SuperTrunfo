#include <stdio.h>

int main() {
    // Declaração das variáveis
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nomecity1[50], nomecity2[50];
    unsigned long int populacao1, populacao2;
    int pontosturistico1, pontosturistico2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2, pibpercapita1, pibpercapita2;
    float superPoder1, superPoder2;

    printf("\n==============================\n");
    printf("      *** SUPER TRUNFO ***     \n");
    printf("==============================\n");

    // =================== CARTA 1 ===================
    printf("\n--- Carta 01 ---\n");

    printf("Digite a letra do estado: ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta: ");
    scanf("%s", codigo1);

    getchar(); // Limpa o buffer antes de fgets()
    printf("Digite o nome da cidade: ");
    fgets(nomecity1, 50, stdin);

    printf("Digite a quantidade de população: ");
    scanf("%lu", &populacao1);  // População como unsigned long int

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontosturistico1);

    printf("Digite a área em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB: ");
    scanf("%f", &pib1);

    getchar(); // Limpa o buffer antes de fgets()

    // =================== CARTA 2 ===================
    printf("\n--- Carta 02 ---\n");

    printf("Digite a letra do estado: ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta: ");
    scanf("%s", codigo2);

    getchar(); // Limpa o buffer antes de fgets()
    printf("Digite o nome da cidade: ");
    fgets(nomecity2, 50, stdin);

    printf("Digite a quantidade de população: ");
    scanf("%lu", &populacao2);  // População como unsigned long int

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &pontosturistico2);

    printf("Digite a área em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    // =================== CÁLCULOS ===================
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibpercapita1 = pib1 / populacao1;
    pibpercapita2 = pib2 / populacao2;

    // Calculando o Super Poder
    superPoder1 = (float)(populacao1 + area1 + pib1 + pontosturistico1 + pibpercapita1 + (1 / densidade1));
    superPoder2 = (float)(populacao2 + area2 + pib2 + pontosturistico2 + pibpercapita2 + (1 / densidade2));

    // =================== RESULTADOS ===================
    printf("\n==============================\n");
    printf("      *** RESULTADOS ***      \n");
    printf("==============================\n");

    // Exibição dos resultados de cada carta
    printf("\n--- Carta 01 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s", nomecity1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("Pontos turísticos: %d\n", pontosturistico1);
    printf("PIB: R$ %.2f\n", pib1);
    printf("Densidade populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pibpercapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n--- Carta 02 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s", nomecity2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("Pontos turísticos: %d\n", pontosturistico2);
    printf("PIB: R$ %.2f\n", pib2);
    printf("Densidade populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pibpercapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // =================== COMPARAÇÕES ===================
    printf("\n--- Comparação dos Atributos ---\n");

    printf("População: Carta 1 vence? %d\n", (populacao1 > populacao2));
    printf("Área: Carta 1 vence? %d\n", (area1 > area2));
    printf("PIB: Carta 1 vence? %d\n", (pib1 > pib2));
    printf("Pontos turísticos: Carta 1 vence? %d\n", (pontosturistico1 > pontosturistico2));
    printf("PIB per capita: Carta 1 vence? %d\n", (pibpercapita1 > pibpercapita2));
    printf("Densidade populacional: Carta 1 vence? %d\n", (densidade1 < densidade2));  // Menor densidade vence
    printf("Super Poder: Carta 1 vence? %d\n", (superPoder1 > superPoder2));

    // =================== COMPARAÇÃO DE POPULAÇÃO =================== 
    //usando if

    printf("\n--- Comparação de População ---\n");

    if (populacao1 > populacao2) {
    printf("Carta 1 (%s) vence em população!\n", nomecity1);
    } else if (populacao2 > populacao1) {
    printf("Carta 2 (%s) vence em população!\n", nomecity2);
    } else {
    printf("As duas cartas têm a mesma população!\n");
    }


    printf("\n==============================\n");
    printf("   Cadastro concluído! ✅     \n");
    printf("==============================\n");

    return 0;
}
