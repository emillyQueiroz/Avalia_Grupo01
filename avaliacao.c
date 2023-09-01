//Anabelly Sthephany Paiva Montibeller;
// Emilly ELiada Queiroz da Fonseca; 
// João Vitor de Lima Antunes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular a união
void uniao(int *conjunto1, int tam1, int *conjunto2, int tam2) {

    printf("União: ");
    for (int i = 0; i < tam1; i++) {
        printf("%d ", conjunto1[i]);
    }

    for (int j = 0; j < tam2; j++) {
        int pertence = 0;
        for (int i = 0; i < tam1; i++) {
            if (conjunto2[j] == conjunto1[i]) {
                pertence = 1;
                break;
            }
        }
        if (!pertence) {
            printf("%d ", conjunto2[j]);
        }
    }

    printf("\n");
}

// Função para calcular a interseção 
void intersecao(int *conjunto1, int tam1, int *conjunto2, int tam2) {
    int i, j;

    printf("Interseção: ");
    for (i = 0; i < tam1; i++) {
        for (j = 0; j < tam2; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                printf("%d ", conjunto1[i]);
                break;
            }
        }
    }

    printf("\n");
}

// Função para calcular a diferença
void diferenca(int *conjunto1, int tam1, int *conjunto2, int tam2) {
    int i, j;

    printf("Diferença: ");
    for (i = 0; i < tam1; i++) {
        int pertence = 0;
        for (j = 0; j < tam2; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                pertence = 1;
                break;
            }
        }
        if (!pertence) {
            printf("%d ", conjunto1[i]);
        }
    }
    printf("\n");
}

// Função para calcular o produto cartesiano 
void cartesiano(int *conjunto1, int tam1, int *conjunto2, int tam2) {
    int i, j;

    printf("Produto Cartesiano:\n");
    for (i = 0; i < tam1; i++) {
        for (j = 0; j < tam2; j++) {
            printf("(%d, %d) ", conjunto1[i], conjunto2[j]);
        }
    }
    printf("\n");
}

int main() {
    FILE *arquivo;
    char linha[256]; 
  
    arquivo = fopen("texto3.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1; 
    }

    fgets(linha, sizeof(linha), arquivo);
    int numOperacoes = atoi(linha);

    for (int op = 0; op < numOperacoes; op++) {

        fgets(linha, sizeof(linha), arquivo);
        char operacao = linha[0];

        fgets(linha, sizeof(linha), arquivo);
        char *token = strtok(linha, ",\n");
        int tam1 = 0;
        int conjunto1[100];
        while (token != NULL) {
            conjunto1[tam1++] = atoi(token);
            token = strtok(NULL, ",\n");
        }

        fgets(linha, sizeof(linha), arquivo);
        token = strtok(linha, ",\n");
        int tam2 = 0;
        int conjunto2[100];
        while (token != NULL) {
            conjunto2[tam2++] = atoi(token);
            token = strtok(NULL, ",\n");
        }

        switch (operacao) {
            case 'U':
                uniao(conjunto1, tam1, conjunto2, tam2);
                break;
            case 'I':
                intersecao(conjunto1, tam1, conjunto2, tam2);
                break;
            case 'D':
                diferenca(conjunto1, tam1, conjunto2, tam2);
                break;
            case 'C':
                cartesiano(conjunto1, tam1, conjunto2, tam2);
                break;
            default:
                printf("Operação desconhecida: %c\n", operacao);
                break;
        }
    }

    fclose(arquivo);

    return 0;
}
