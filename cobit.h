#ifndef COBIT_H
#define COBIT_H
#include <stdbool.h>
#include <stdio.h>

#define MAX_STR_LEN 50
#define MAX_NUM_STRINGS 5

extern int test_result_counter;
extern char test_results[MAX_NUM_STRINGS][MAX_STR_LEN];



struct test_result_info {
		char* message;
		bool status;
};
 
typedef struct test_result_info Test_Result_Info;
typedef Test_Result_Info (*Test_Function)(void);

void myFunction(int parameter);
void run_all_cobit_tests(Test_Function test_functions[], int number_of_test_functions);
Test_Result_Info cobit_assert(char* successed_message, char* failed_message, bool test_to_be_done);

#endif
