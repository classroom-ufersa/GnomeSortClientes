#include "cliente.h"

// Estrutura de dados para armazenar os dados de um cliente
struct cliente {
    char codigo[10];
    char nome[50];
    char endereco[100];
};

// Função para carregar clientes a partir de um arquivo
int carregarClientes(Cliente **clientes){
    FILE *arquivo = fopen("clientes_ordenados.txt", "a+"); // Abre o arquivo "clientes_ordenados.txt" para leitura e escrita

    int quantidade; // Variável para armazenar a quantidade de clientes

    if (fscanf(arquivo, "%d", &quantidade) != 1) { // Le a quantidade de clientes no arquivo
        fclose(arquivo);
        return 0;
    }
   
    if (quantidade <= 0) { // Se a quantidade de clientes for inválida, retorna 0
        fclose(arquivo);
        return 0;
    }

    *clientes = (Cliente *)malloc(quantidade * sizeof(Cliente)); // Aloca dinamicamente memória para armazenar os clientes
    
    // Loop para ler dados de cada cliente do arquivo
    for(int i = 0; i < quantidade; i++){
        fscanf(arquivo, "%s %s %[^\n]", (*clientes)[i].codigo, (*clientes)[i].nome, (*clientes)[i].endereco); // Lê código, nome e endereço de cada cliente e armazena na estrutura
    }

    fclose(arquivo); // Fecha o arquivo após a leitura

    return quantidade; // Retorna a quantidade total de clientes lidos
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

void adicionarClientes(Cliente **clientes, int *quantidade, int quantidade_nova){*clientes = (Cliente *)realloc(*clientes, (*quantidade + quantidade_nova) * sizeof(Cliente)); // aloca dinamicamente memória para armazenar os novos clientes

    // Loop para adicionar informações para os novos clientes
    for(int i = 0; i < quantidade_nova; i++){
        sprintf((*clientes)[*quantidade + i].codigo, "C%04d", *quantidade + i + 1); // Gera um código único para o novo cliente (C + número sequencial)
        printf("Informe o nome do novo cliente %d: ", *quantidade + i + 1);
        scanf(" %[^\n]", (*clientes)[*quantidade + i].nome); 
        printf("Informe o endereco do novo cliente %d: ", *quantidade + i + 1);
        scanf(" %[^\n]", (*clientes)[*quantidade + i].endereco);
        printf("\n");
    }

    *quantidade += quantidade_nova; // Atualiza a quantidade total de clientes
}

// Função Gnome Sort para ordenar um array de clientes pelo nome
void gnomeSort(Cliente *clientes, int n) {
    int index = 0;  // Inicializa o índice para percorrer o array

    // Enquanto ainda houver elementos não ordenados
    while (index < n) {

        // Se o índice for 0, incrementa-o
        if (index == 0) {
            index++;
        }

        // Compara os nomes dos clientes em posições adjacentes
        if (strcmp(clientes[index].nome, clientes[index - 1].nome) >= 0) {
          // Se estiverem em ordem crescente ou iguais, avança para o próximo índice
            index++;
        } else {
            // Se os nomes estiverem fora de ordem, troca-os de posição
            Cliente temp = clientes[index];
            clientes[index] = clientes[index - 1];
            clientes[index - 1] = temp;
            index--;
        }
    }
}
