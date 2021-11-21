#include "onegin.h"
#include "string.h"
//ftell, fseek, fread

int comp(const void* p1, const void* p2) {
	return myStrcmp(*(const char**)p1, *(const char**)p2);
}

int main() {
	//Read file
	FILE *input = fopen("onegin.txt", "rb");
	int file_byte_size = count_symbols(input);
	//Convert file to char* array
	char* file_buffer = fileToString(input, file_byte_size);
	int lines_count = (int)count_lines(file_buffer, file_byte_size);
	//Split one char* array int a two-dimensional array of strings
	char** strings = (char**)calloc(lines_count, sizeof(char*));
	divideString(file_buffer, strings, file_byte_size);
	//sort two-dimesional array
	qsort(strings, lines_count, sizeof(char*), comp);
	//Вывод
	for(int i = 0; i < lines_count; i++) {
		printf("%s\n", strings[i]);
	}
	return 0;
}