#include <stdlib.h>
#include <string.h>
#include "phonebook_opt_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */



unsigned int bkdr_hash(const char* key)
{
    char* str = (char*)key;

    unsigned int seed = 31;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return hash;
}


entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */

    unsigned int hashvalue=bkdr_hash(lastName);
    hashvalue%=HASH_TABLE_SIZE;
    entry* ptr=&pHead[hashvalue];
    while (ptr != NULL) {
        if (strcasecmp(lastName, ptr->lastName) == 0)
            return ptr;
        ptr = ptr->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    entry* ptr=&e[bkdr_hash(lastName)%HASH_TABLE_SIZE];
    entry* tmp=ptr->pNext;
    ptr->pNext=(entry*)malloc(sizeof(entry));
    ptr=ptr->pNext;
    strcpy(ptr->lastName,lastName);
    ptr->pNext=tmp;

    return e;
}
