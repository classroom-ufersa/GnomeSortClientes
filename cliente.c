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

// Função para salvar informações de clientes em um arquivo de texto.
void salvarClientes(Cliente *clientes, int quantidade) {
     // Abre o arquivo "clientes_ordenados.txt" para escrita.
    FILE *arquivo = fopen("clientes_ordenados.txt", "w");

    // Verifica se houve erro na abertura do arquivo.
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Escreve a quantidade de clientes no arquivo.
    fprintf(arquivo, "%d\n", quantidade);

    // Escreve as informações de cada cliente no arquivo.
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, " %s %s %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco);
    }

    // Fecha o arquivo.
    fclose(arquivo);
}


 