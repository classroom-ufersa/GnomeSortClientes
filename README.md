# Gnome-Sort-Clientes
**Ordenação de strings com Gnome Sort**

**Componentes:**

* **Gustavo Kesley**
* **Fabricio Pereira**
* **Abnoan Gabriel**
* **Dinarte Filho**


## Funcionalidade do algoritmo:

### Função:

```c
void gnomeSort(Cliente *clientes, int n){
    int index = 0;
    while(index < n){
        if(index == 0){
            index++;
        }
        if(strcmp(clientes[index].nome, clientes[index - 1].nome) >= 0){
            index++;
        } else{
            Cliente temp = clientes[index];
            clientes[index] = clientes[index - 1];
            clientes[index - 1] = temp;
            index--;
        }
    }
}
```

### Explicando linha por linha:

1. **Função Gnome Sort:**

```c
void gnomeSort(Cliente *clientes, int n)
```

- ***`void` :*** Não retorna nenhum valor.
- ***`gnomeSort` :*** Nome da função.
- ***`Cliente *clientes` :*** Um ponteiro para um array de estruturas do tipo **`Cliente`**.
- ***`int n` :*** O número de elementos no array.

2. **Inicialização de Variável:**

```c
int index = 0;
```

- Inicializa a variável **`index`** com 0. Essa variável será usada como um índice durante o processo de ordenação.

3. **Loop Principal (while):**

```c
while(index < n){
```

- Inicia um loop enquanto o índice (**`index`**) for menor que o número de elementos no array.

4. **Condição para `index` igual a 0:**

```c
if(index == 0){
    index++;
}
```

- Se **`index`** for igual a 0, incrementa **`index`** para evitar problemas de acesso inválido, pois a condição seguinte usa **`index - 1`**.

5. **Condição de Ordenação:**

```c
if(strcmp(clientes[index].nome, clientes[index - 1].nome) >= 0){
    index++;
} else{
```

- Compara os nomes dos clientes usando **`strcmp`**. Se o resultado for maior ou igual a zero, significa que os nomes estão em ordem ou devem ser mantidos em ordem crescente. Nesse caso, incrementa **`index`**.

6. **Troca de Elementos em Caso de Desordem:**

```c
Cliente temp = clientes[index];
    clientes[index] = clientes[index - 1];
    clientes[index - 1] = temp;
    index--;
}
}
```

- Se os nomes estiverem fora de ordem, troca os elementos usando uma variável temporária (**`temp`**).
- Decrementa **`index`** para verificar se a troca afetou os elementos anteriores.
- O loop continua até que todos os elementos estejam ordenados, e a função é concluída.

```

💡 o Gnome Sort compara os nomes dos clientes e move-se para trás no array sempre que encontra elementos fora de ordem, trocando-os até que o array esteja ordenado.
d
```
