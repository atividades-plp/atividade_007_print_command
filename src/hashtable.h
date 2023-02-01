#ifndef HASH_HEADER
#define HASH_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT 0

typedef int vartype;

typedef struct hnode
{
    char *key;
    int value;
    char *name;
    vartype type;
} hnode;

typedef struct hashtable
{
    int length; // current amount of elements
    int size;   // max amount of elements
    hnode **data;
} hashtable;

// Cria uma nova tabela hash
hashtable *new_hashtable(int size);

// Retorna o hash de uma chave
int get_hash(char *key, int size);

// Adiciona um novo nó a tabela hash
void add_hash_node(hashtable *table, int value, char *key, char *name, vartype type);

// Imprime os elementos de uma tabela hash
void print_hashtable(hashtable *table);

#endif