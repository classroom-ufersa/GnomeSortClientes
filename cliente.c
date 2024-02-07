#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
struct cliente{
    char nome[50];
    char endereco[100];
    int cod_cliente;
};

void PreEncherCliente(struct cliente *cliente){
    printf("Nome do cliente: ");
    scanf(" [^\n]", cliente->nome);

    printf("Endereco: ");
    scanf(" [^\n]", cliente->endereco);
}

