#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#ifndef PARSE_H
#define PARSE_H

#define FREE(x) free(x); x=NULL;
#define blocks(buffer, separator) (calc(buffer, separator).enc+1) // just help to calculate blocks

typedef struct {
    int* offsets;
    size_t enc;
} meta;

typedef struct{
    char* buff;
    size_t length;
} token;

typedef struct {
    token* tok;
    size_t length;
} node;

int is_digit(char);
node separate(char*, char);
int cut(char*, char*, int, int);
size_t len(char*);
char* cpy(char*, char*, size_t);
meta calc(char*, char);

#endif