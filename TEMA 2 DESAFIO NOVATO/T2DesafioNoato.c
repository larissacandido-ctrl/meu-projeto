
//desafio free fire - Tema 2
// Nivel Novato.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor para armazenar os itens
Item mochila[MAX_ITENS];
int qtdItens = 0;

// Função para inserir um item na mochila
void inserirItem() {
    if (qtdItens >= MAX_ITENS) {
        printf("\n Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n--- Adicionar Novo Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome); // lê string com espaço

    printf("Tipo do item (arma, municao, cura, etc.): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[qtdItens] = novo;
    qtdItens++;

    printf("\n Item '%s' adicionado com sucesso!\n", novo.nome);
}

// Função para remover um item da mochila
void removerItem() {
    if (qtdItens == 0) {
        printf("\n Mochila vazia. Nenhum item para remover.\n");
        return;
    }

    char nome[30];
    printf("\n--- Remover Item ---\n");
    printf("Digite o nome do item a remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            // Desloca os itens seguintes para preencher a posição
            for (int j = i; j < qtdItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            qtdItens--;
            printf("\n Item '%s' removido com sucesso!\n", nome);
            return;
        }
    }

    printf("\n Item '%s' nao encontrado na mochila.\n", nome);
}

// Função para listar os itens
void listarItens() {
    printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", qtdItens, MAX_ITENS);
    printf("--------------------------------------------------\n");
    printf("NOME\t\t| TIPO\t\t| QUANTIDADE\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < qtdItens; i++) {
        printf("%-15s | %-10s | %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("--------------------------------------\n");
}


int main() {
    int opcao;

    do {
        printf("\n=====================================\n");
        printf(" MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
        printf("=====================================\n");
        printf("Itens na Mochila: %d/%d\n", qtdItens, MAX_ITENS);
        printf("1. Adicionar Item (Loot)\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens na Mochila\n");
        printf("0. Sair\n");
        printf("--------------------------------------\n");
        printf("Escolha uma opcao:1 ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 0: printf("\nSaindo do jogo... ate a proxima! \n"); break;
            default: printf("\n Opção invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
