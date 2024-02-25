#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente Cliente;

int carregarClientes(Cliente **clientes);
void salvarClientes(Cliente *clientes, int quantidade);
void adicionarClientes(Cliente **clientes, int *quantidade, int quantidade_nova);
void gnomeSort(Cliente *clientes, int n);

#endif