#include <stdio.h>
#include <assert.h>

typedef enum {
	OK,
	failure
} Errors; 

Errors test_count_symbols();
Errors test_count_lines();
Errors test_formatString();
Errors test_buildString();
Errors test_comparator();
void run_all_tests();

