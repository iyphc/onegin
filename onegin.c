#include <stdio.h>
#include <stdlib.h>

size_t count_symbols(FILE *input) {
	fseek(input, 0, SEEK_END);
	size_t count = ftell(input);
	fseek(input, 0, SEEK_SET);
	return count;
}

size_t count_lines(char *input, int n) {
	size_t ret = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] == '\n') {
			ret++;
		}
	}
	return ret;
}

void divideString(char* source, char** target, size_t size) {
	int j = 1;
	target[0] = source;
	for(int i = 0; i < size; i++) {
		if (source[i] == '\n') {
			source[i] = '\0';
			target[j] = (source + i + 1); 
			j++;
		} 
	}
}

char* fileToString(FILE* source, size_t size) {
	char* file_buffer = (char*)calloc(size, sizeof(char));	
	fread(file_buffer, size, sizeof(char), source);
	return file_buffer;
}
