#include "cobit.h"

// Defining the previously declared variable for keeping track of test results generated and initializing with 0
int test_result_counter = 0;
// Defining the previously declared array for storing the output messages (as results) of tests
char test_results[MAX_NUM_STRINGS][MAX_STR_LEN];

/*
	Defining the previously declared assert function
	which should test a case (an assertion) and return the result.

	Parameter(s):
		- char* successed_message (the message that will be shown if the test succeeded)
		- char* failed_message (the message that will be shown if the test faild)
		- bool test_to_be_done (the case/assertion to test)
	Return-Value(s):
		- Test_Result_Info (the resulf of the test executed)
*/ 
Test_Result_Info cobit_assert(char* successed_message, char* failed_message, bool test_to_be_done)
{
	// Instantiating the struct to store result of the test
	Test_Result_Info test_result;
	// Checking if the assertion is true
	if(test_to_be_done)
	{
		// Setting the status of the result so that indicates that the assertion was true
		test_result.status = 1;
		// Assigning the corresponding message
		test_result.message = successed_message;
	}
	else
	{
		// Setting the status of the result so that indicates that the assertion was wrong
		test_result.status = 0;
		// Assigning the corresponding message
		test_result.message = failed_message;
	}

	// Returning the result
	return test_result;
}

/*
	Defining the previously declared assert function
	which should test a case (an assertion) and return the result.

	Parameter(s):
		- Test_Function test_functions[] (the array containg all tests [functions representing the tests])
		- int number_of_test_functions (the size of the array containing all tests)
	Return-Value(s):
		- void
*/ 
void run_all_cobit_tests(Test_Function test_functions[], int number_of_test_functions)
{
	// Iterating over the array of tests
	for(int i = 0; i < number_of_test_functions; i++)
	{
		// Executing/running all the tests and displaying their result
		sprintf(test_results[test_result_counter++], "%s", test_functions[i]().message);	
	}
}
