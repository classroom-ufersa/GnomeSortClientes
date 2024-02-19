#include "cliente.h"

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int quantidade_existente = 0;
    Cliente *clientes = NULL;

    quantidade_existente = carregarClientes(&clientes);

    int quantidade_nova;
    printf("Informe a quantidade de novos clientes a serem cadastrados: ");
    scanf("%d", &quantidade_nova);

    