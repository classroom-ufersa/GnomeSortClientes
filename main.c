#include "cliente.h"

int main() {
    clock_t inicio, fim;
    double tempo_de_execucao;

    int quantidade_existente = 0;
    Cliente *clientes = NULL;

    quantidade_existente = carregarClientes(&clientes);

    int quantidade_nova;
    printf("Informe a quantidade de novos clientes a serem cadastrados: ");
    scanf("%d", &quantidade_nova);

    adicionarClientes(&clientes, &quantidade_existente, quantidade_nova);
    inicio = clock();
    gnomeSort(clientes, quantidade_existente);
    fim = clock();
    salvarClientes(clientes, quantidade_existente);

    free(clientes);

    tempo_de_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo_de_execucao);

    return 0;
}