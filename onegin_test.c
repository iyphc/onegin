#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "onegin_test.h"
#include "onegin.h"
#include "string.h"

void run_all_tests() {
	assert(test_count_symbols() == OK);
	assert(test_count_lines() == OK);
	assert(test_formatString() == OK);
	assert(test_buildString() == OK);
	assert(test_comparator() == OK);
}

Errors test_count_symbols(){
	FILE *input = fopen("test.txt", "rb");
	if (input == NULL) {
		fclose(input);
        printf("\nI don't wanna do it more. Crashed.\n\n");
        return failure;
    }
	int file_byte_size = count_symbols(input);	
	int cur_count = 49;
	if (file_byte_size != cur_count) {
		fclose(input);
		printf("I don't wanna do it more. Crashed.");
		return failure;
	}
	fclose(input);
	return OK;
}

Errors test_count_lines() {
	FILE *input = fopen("test.txt", "rb");
	int file_byte_size = count_symbols(input);
	char* file_buffer = fileToString(input, file_byte_size);
	int lines_count = (int)count_lines(file_buffer, file_byte_size);
	int cur_count = 19;
	if (input == NULL || file_byte_size == 0 || file_buffer == NULL || lines_count == 0) {
		fclose(input);
        printf("\nI don't wanna do it more. Crashed.\n\n");
        return failure;
    }
	if (lines_count != cur_count) {
		fclose(input);
		printf("I don't wanna do it more. Crashed.");
		return failure;
	}
	fclose(input);
	return OK;
}

Errors test_formatString() {
	char string[] = "hello\nworld\n";
	int length = formatString(string, 12);
	if (myStrcmp(string, "hello\0world\0") != 0 || length != 1) {
		printf("\nI don't wanna do it more. Crashed.\n\n");
		return failure;
	}
	return OK;
}

Errors test_buildString() {
	char string[] = "hello\0world\0";
	char** cur_strings = (char**)calloc(2, sizeof(char*));
	cur_strings = buildString(string, cur_strings, 12);
	if (cur_strings == NULL) {
        printf("\nI don't wanna do it more. Crashed.\n\n");
        return failure;
    }
	if (myStrcmp(cur_strings[0], "hello") || myStrcmp(cur_strings[1], "world")) {
		printf("\nI don't wanna do it more. Crashed.\n\n");
		return failure;
	}
	return OK;
}

Errors test_comparator() {
	char* str1 = myStrdup("abcd");
	char* str2 = myStrdup("abcd");
	if (comp(&str1, &str2) != 0) {
		printf("\nI don't wanna do it more. Crashed.\n\n");
		return failure;
	}
	free(str2);
	str2 = myStrdup("lbcd");
	if (comp(&str1, &str2) != -11) {
		printf("\nI don't wanna do it more. Crashed.\n\n");
		return failure;
	}
	if (comp(&str2, &str1) != 11) {
		printf("\nI don't wanna do it more. Crashed.\n\n");
		return failure;
	}
	free(str1);
	free(str2);
	return OK;
}
