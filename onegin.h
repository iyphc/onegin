#include <stdio.h>
#include <stdlib.h>

size_t count_lines(char *input, int n);
size_t count_symbols(FILE *input);
void divideString(char* source, char** target, size_t size);
char* fileToString(FILE* source, size_t size);