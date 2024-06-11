#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUTOS 100
#define MAX_NOME 50
typedef struct {
    int codigo;
    char nome[MAX_NOME];
    int quantidade;
    float preco;
} Produto;
Produto estoque[MAX_PRODUTOS];
int total_produtos = 0;
void adicionarProduto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível adicionar mais produtos.\n");
        return;
    }
    Produto novo_produto;
    printf("Digite o código do produto: ");
    scanf("%d", &novo_produto.codigo);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo_produto.nome); // Use %[^\n] to read the entire line
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo_produto.quantidade);
    printf("Digite o preço do produto: ");
    scanf("%f", &novo_produto.preco);
    estoque[total_produtos] = novo_produto;
    total_produtos++;
    printf("Produto adicionado com sucesso!\n");
}
void atualizarQuantidade() {
    int codigo, nova_quantidade;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Digite a nova quantidade: ");
            scanf("%d", &nova_quantidade);
            estoque[i].quantidade = nova_quantidade;
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}
void exibirProdutos() {
    if (total_produtos == 0) {
        printf("Estoque vazio!\n");
        return;
    }
    printf("Lista de produtos no estoque:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("Código: %d\n", estoque[i].codigo);
        printf("Nome: %s\n", estoque[i].nome);
        printf("Quantidade: %d\n", estoque[i].quantidade);
        printf("Preço: %.2f\n", estoque[i].preco);
        printf("------------------------\n");
    }
}
void buscarProduto() {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d\n", estoque[i].codigo);
            printf("Nome: %s\n", estoque[i].nome);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Preço: %.2f\n", estoque[i].preco);
            return;
        }
    }
    printf("Produto não encontrado!\n");
}
int main() {
    int opcao;
    while (1) {
        printf("\nSistema de Gerenciamento de Estoque\n");
        printf("1. Adicionar produto\n");
        printf("2. Atualizar quantidade\n");
        printf("3. Exibir produtos\n");
        printf("4. Buscar produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                atualizarQuantidade();
                break;
            case 3:
                exibirProdutos();
                break;
            case 4:
                buscarProduto();
                break;
            case 5:
                printf("Saindo do programa...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}
