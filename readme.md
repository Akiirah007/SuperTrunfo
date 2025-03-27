📌 Descrição do Projeto
Super Trunfo em C é um jogo interativo de cartas onde o jogador compara atributos de duas cidades (como população, área, PIB, etc.) para determinar qual carta vence.

🔥 Recursos Implementados
✅ Cadastro de Cartas: Insira dados de duas cidades (nome, população, área, etc.).
✅ Menu Dinâmico: Escolha dois atributos diferentes para comparação.
✅ Regras Especiais:

Densidade Demográfica: Menor valor vence.

Outros atributos: Maior valor vence.
✅ Soma de Atributos: Desempate baseado na soma dos dois atributos escolhidos.
✅ Loop de Jogo: Jogue quantas vezes quiser sem reiniciar o programa.
✅ Validação de Entradas: Proteção contra entradas inválidas.


📝 Explicação do Código
1. Estrutura da Carta (struct Carta)
Armazena todos os dados de uma cidade:

typedef struct {
    char estado;               // Ex: 'S' (São Paulo)
    char codigo[4];            // Ex: "SP1"
    char cidade[50];           // Ex: "São Paulo"
    unsigned long populacao;   // Ex: 12345678
    float area;                // Ex: 1521.11 (km²)
    // ... (outros atributos)
} Carta;

==========================================================================================

2. Funções Principais
exibirMenu
O que faz: Mostra um menu e valida a escolha do usuário.

Parâmetros:

titulo: Texto do menu (ex: "Escolha o primeiro atributo").

opcoes[]: Lista de opções (ex: ["População", "Área", ...]).

opcaoRemovida: Remove uma opção já escolhida.

cadastrarCarta
O que faz: Preenche os dados de uma carta e calcula campos automáticos (densidade, PIB per capita, etc.).

=============================================================================================================

3. Lógica do Jogo
Cadastro Inicial:
Carta carta1, carta2;
cadastrarCarta(&carta1, 1);
cadastrarCarta(&carta2, 2);

Escolha de Atributos:

O jogador seleciona dois atributos diferentes (ex: População e Área).

Comparação:

Atributo 1: Maior valor vence (exceto Densidade, onde menor vence).

Atributo 2: Mesma regra.

Desempate:

Soma os valores dos dois atributos. A carta com a maior soma vence.

4. Loop de Jogo
Pergunta se o jogador quer continuar (s/n).

Repete o jogo enquanto a resposta for 's'.

==========================================================================

📊 Exemplo de Saída

=== RESULTADO ===  
Carta 1: São Paulo (SP1)  
Carta 2: Rio de Janeiro (RJ1)  

Atributos comparados:  
1. População: Carta 1 = 12.3M | Carta 2 = 6.7M  
2. Área: Carta 1 = 1521 km² | Carta 2 = 1200 km²  

Soma dos atributos:  
Carta 1: 13.821M | Carta 2: 7.9M  

🏆 Carta 1 vence!  