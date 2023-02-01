#include "hashtable.h"

hnode *new_hash_node(int value, char *key, char *name, vartype type)
{
    hnode *nnode = (hnode *)malloc(sizeof(hnode));
    nnode->value = value;
    nnode->name = (char *)malloc(strlen(name));
    nnode->key = (char *)malloc(strlen(key));
    nnode->type = type;
    strcpy(nnode->name, name);
    strcpy(nnode->key, key);
    return nnode;
}

hashtable *new_hashtable(int size)
{
    hashtable *nhash = (hashtable *)malloc(sizeof(hashtable));
    nhash->data = (hnode **)malloc(sizeof(hnode) * size);
    nhash->length = 0;
    nhash->size = size;
    for (int index = 0; index < size; index++)
        nhash->data[index] = NULL;
    return nhash;
}

int get_hash(char *key, int size)
{
    int key_as_int = 0;
    for (int index = 0; index < strlen(key); index++)
        key_as_int += (int)key[index];
    return ((key_as_int * key_as_int) * 64) % size;
}

int linear_hashing(char *key, int size, int collisions)
{
    return (get_hash(key, size) + collisions) % size;
}

void add_hash_node(hashtable *table, int value, char *key, char *name, vartype type)
{
    if (table->data == NULL || table->length == table->size)
        return;
    hnode *nnode = new_hash_node(value, key, name, type);
    int collisions = 0;
    while (table->data[linear_hashing(key, table->size, collisions)] != NULL)
        collisions++;
    table->data[linear_hashing(key, table->size, collisions)] = nnode;
    table->length++;
}

void print_hashtable(hashtable *table)
{
    if (table->data == NULL)
        return;
    for (int index = 0; index < table->size; index++)
    {
        printf("Indice %d: ", index);
        if (table->data[index] == NULL)
            printf("Vazio.\n");
        else
            printf("{key=%s,value=%d,name=%s,type=%d}\n",
                   table->data[index]->key,
                   table->data[index]->value,
                   table->data[index]->name,
                   table->data[index]->type);
    }
}

hnode *find(hashtable *table, char *key)
{
    if (table == NULL || table->length == 0)
        return NULL;
    int collisions = 0;
    while (collisions < table->size)
    {
        hnode *node = table->data[linear_hashing(key, table->size, collisions)];
        if (node != NULL && strcmp(node->key, key) == 0)
            return node;
        collisions++;
    }
    return NULL;
}

// int main()
// {
//     hashtable *table = new_hashtable(10);
//     add_hash_node(table, 10, "variable1", "variavel1", INT);
//     print_hashtable(table);

//     hnode *node = find(table, "variable2");

//     if (node == NULL)
//         printf("Não existe");
//     else
//         printf("Existe");

//     return 0;
// }