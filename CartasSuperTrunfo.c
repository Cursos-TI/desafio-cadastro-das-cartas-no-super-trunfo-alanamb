#include <stdio.h>

// Definindo uma estrutura para representar a carta
typedef struct {
    char codigo_cidade[5];
    char nome[20];
    unsigned long int populacao; 
    int pontos_turisticos;
    float area;
    float pib;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para cadastrar os dados de uma carta
void cadastrar_carta(Carta *carta, int numero_carta) {
    printf("\n--- Cadastro da Carta %d ---\n", numero_carta);
    printf("Código da cidade que deseja cadastrar:\n");
    scanf("%s", carta->codigo_cidade);

    printf("Adicione o nome da cidade %s:\n", carta->codigo_cidade);
    scanf("%s", carta->nome);

    printf("Adicione a quantidade de população da cidade:\n");
    scanf("%lu", &carta->populacao); 

    printf("Adicione a quantidade de pontos turísticos da cidade:\n");
    scanf("%d", &carta->pontos_turisticos);

    printf("Adicione a área da cidade em km2:\n");
    scanf("%f", &carta->area);

    printf("Adicione o PIB da cidade (em bilhões):\n");
    scanf("%f", &carta->pib);
}

// Função para calcular os atributos derivados (Densidade Populacional e PIB per Capita)
void calcular_atributos_derivados(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0.0; 
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao;
    } else {
        carta->pib_per_capita = 0.0; 
    }
}

// Função para calcular o Super Poder
void calcular_super_poder(Carta *carta) {
    float inverso_densidade = (carta->densidade_populacional > 0) ? (1.0 / carta->densidade_populacional) : 0.0;

    carta->super_poder = (float)carta->populacao + carta->area + carta->pib + (float)carta->pontos_turisticos + carta->pib_per_capita + inverso_densidade;
}


// Função para exibir os dados de uma carta
void exibir_carta(const Carta *carta, int numero_carta) {
    printf("\n--- Dados da Carta %d ---\n", numero_carta);
    printf("Código da cidade: %s\n", carta->codigo_cidade);
    printf("Nome: %s\n", carta->nome);
    printf("População: %lu\n", carta->populacao);
    printf("Quantidade de pontos turísticos: %d\n", carta->pontos_turisticos);
    printf("Área: %.2f km2\n", carta->area);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Densidade Populacional: %.2f hab/km2\n", carta->densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta->pib_per_capita);
    printf("Super Poder: %.2f\n", carta->super_poder);
}

// Função para comparar um atributo e imprimir o resultado
void comparar_atributo(const char *nome_atributo, float valor1, float valor2, int maior_vence) {
    int carta1_vence = 0;
    if (maior_vence) {
        if (valor1 > valor2) {
            carta1_vence = 1;
        }
    } else { 
        if (valor1 < valor2) {
            carta1_vence = 1;
        }
    }
    printf("%s: Carta %d venceu (%d)\n", nome_atributo, carta1_vence ? 1 : 2, carta1_vence);
}


int main() {
    Carta carta1, carta2;

    // Cadastro das duas cartas
    cadastrar_carta(&carta1, 1);
    cadastrar_carta(&carta2, 2);

    // Cálculo dos atributos derivados para ambas as cartas
    calcular_atributos_derivados(&carta1);
    calcular_atributos_derivados(&carta2);

    // Cálculo do Super Poder para ambas as cartas
    calcular_super_poder(&carta1);
    calcular_super_poder(&carta2);

    // Exibição completa dos dados das cartas
    exibir_carta(&carta1, 1);
    exibir_carta(&carta2, 2);

    // Comparação das Cartas
    printf("\n--- Comparação de Cartas ---\n");
    comparar_atributo("População", (float)carta1.populacao, (float)carta2.populacao, 1); // Maior vence
    comparar_atributo("Área", carta1.area, carta2.area, 1); // Maior vence
    comparar_atributo("PIB", carta1.pib, carta2.pib, 1); // Maior vence
    comparar_atributo("Pontos Turísticos", (float)carta1.pontos_turisticos, (float)carta2.pontos_turisticos, 1); // Maior vence
    comparar_atributo("Densidade Populacional", carta1.densidade_populacional, carta2.densidade_populacional, 0); // Menor vence
    comparar_atributo("PIB per Capita", carta1.pib_per_capita, carta2.pib_per_capita, 1); // Maior vence
    comparar_atributo("Super Poder", carta1.super_poder, carta2.super_poder, 1); // Maior vence

    return 0;
}