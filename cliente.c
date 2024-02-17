#include "cliente.h"

// Função para carregar clientes a partir de um arquivo
int carregarClientes(Cliente **clientes){
    // Abre o arquivo "clientes_ordenados.txt" em modo de leitura
    FILE *arquivo = fopen("clientes_ordenados.txt", "r");
    
    // Verifica se a abertura do arquivo foi bem-sucedida
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    int quantidade;
    
    // Lê a quantidade de clientes do arquivo
    fscanf(arquivo, "%d", &quantidade);

    // Aloca dinamicamente memória para armazenar os clientes
    *clientes = (Cliente *)malloc(quantidade * sizeof(Cliente));
    
    // Loop para ler dados de cada cliente do arquivo
    for(int i = 0; i < quantidade; i++){
        // Lê código, nome e endereço de cada cliente e armazena na estrutura
        fscanf(arquivo, "%s %s %[^\n]", (*clientes)[i].codigo, (*clientes)[i].nome, (*clientes)[i].endereco);
    }

    // Fecha o arquivo após a leitura
    fclose(arquivo);

    // Retorna a quantidade total de clientes lidos
    return quantidade;
}



// Função para preencher os dados do cliente
void PreEncherCliente(struct cliente *cliente){
    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente->nome);

    printf("Insira seu endereco conforme pedido abaixo: \n");
    printf("Nome da cidade em que reside: \n");
    scanf(" %[^\n]", cliente->endereco.cidade);

    printf("Nome da rua: \n");
    scanf(" %[^\n]", cliente->endereco.nome_da_rua);

    printf("Nome do Bairro: \n");
    scanf(" %[^\n]", cliente->endereco.barirro);

    printf("Numero da casa: \n");
    scanf("%d", &cliente->endereco.numero_da_casa);

    printf("Insira o CEP: \n");
    scanf("%d", &cliente->endereco.CEP);
}

void ImprimirCliente(struct cliente *cliente){
    printf("=========== Dados do cliente ===========\n");
    printf("Nome do cliente: %s\n", cliente->nome);
    printf("Cidade: %s\n", cliente->endereco.cidade);
    printf("Rua: %s\n", cliente->endereco.nome_da_rua);
    printf("Bairro: %s\n", cliente->endereco.barirro);
    printf("Numeo da casa: %d\n", cliente->endereco.numero_da_casa);
    printf("CEP: %d\n", cliente->endereco.CEP);
    printf("=======================================\n");
}

 