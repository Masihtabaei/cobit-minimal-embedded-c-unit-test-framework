#include "cobit.h"

int test_result_counter = 0;
char test_results[MAX_NUM_STRINGS][MAX_STR_LEN];

Test_Result_Info cobit_assert(char* successed_message, char* failed_message, bool test_to_be_done)
{
	
	Test_Result_Info test_result;
	if(test_to_be_done)
	{
		test_result.status = 1;
		test_result.message = successed_message;
	}
	else
	{
		test_result.status = 0;
		test_result.message = failed_message;
	}
	return test_result;
}

void run_all_cobit_tests(Test_Function test_functions[], int number_of_test_functions)
{
	for(int i = 0; i < number_of_test_functions; i++)
	{
		sprintf(test_results[test_result_counter++], "%s", test_functions[i]().message);	
	}
}
