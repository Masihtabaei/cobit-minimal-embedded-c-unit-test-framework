#ifndef COBIT_H
#define COBIT_H
#include <stdbool.h>
#include <stdio.h>

// Defining a macro for defining the maximum length of each line of the output message (= number of columns)
#define MAX_STR_LEN 50
// Defining a macro for defining the maximum number of lines serving as output messages
#define MAX_NUM_STRINGS 5

// Declaring a variable for keeping track of test results generated (definition delegated to the source file)
extern int test_result_counter;
// Declaring an array for storing the output messages (as results) of tests (definition delegated to the source file)
extern char test_results[MAX_NUM_STRINGS][MAX_STR_LEN];

// Defining a struct as a type with two members storing message and status of a test
typedef struct test_result_info
{
	char *message;
	bool status;
} Test_Result_Info;

// Defining a function pointer as a type for test functions which return the test result
typedef Test_Result_Info (*Test_Function)(void);

// Declaring a function (prototype) which should execute/run all of the tests available
void run_all_cobit_tests(Test_Function test_functions[], int number_of_test_functions);
// Declaring a function (prototype) which should test a case (an assertion) and return the result 
Test_Result_Info cobit_assert(char *successed_message, char *failed_message, bool test_to_be_done);

#endif
