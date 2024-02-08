// BRANCH CRIADA PARA TESTE DE FUNCIONALIDADES //
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>


// Estrutura do endereco do cliente
struct Endereco{
    char nome_da_rua[20], barirro[20], cidade[20];
    int numero_da_casa, CEP;
};

// Estrutura do cliente
struct cliente{
    char nome[50];
    int cod_cliente;

    struct Endereco endereco;
};

// Função para preencher os dados do cliente
void PreEncherCliente(struct cliente *cliente){
    printf("Nome do cliente: ");
    scanf(" [^\n]", cliente->nome);

    printf("Insira seu endereco conforme pedido abaixo: \n");
    printf("Nome da cidade em que reside: \n");
    scanf(" [^\n]", &cliente->endereco.cidade);

    printf("Nome da rua: \n");
    scanf(" [^\n]", &cliente->endereco.nome_da_rua);

    printf("Nome do Bairro: \n");
    scanf(" [^\n]", &cliente->endereco.barirro);

    printf("Numero da casa: \n");
    scanf("%d", &cliente->endereco.numero_da_casa);

    printf("Insira o CEP: \n");
    scanf("%d", &cliente->endereco.CEP);
}

 