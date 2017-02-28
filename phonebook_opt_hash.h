#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define HASH 1
#define HASH_TABLE_SIZE 8763

typedef struct __PERSON_DATA {
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} person;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    struct __PHONE_BOOK_ENTRY *pNext;
    struct __PERSON_DATA *data;
} entry;

unsigned int bkdr_hash(const char* key) ;
entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);

#endif
