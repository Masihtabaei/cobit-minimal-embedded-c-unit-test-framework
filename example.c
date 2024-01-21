/**************************************************************************
 *  COPYRIGHT (C) Peter Raab  2019                                        *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  PROJECT       EBSy: Px - Basisproject                                 *
 *  MODULE        main.c                                                  *
 *  REVISION      2.0                                                     *
 **************************************************************************
 *  PURPOSE:                                                              *
 *   The main routine is the start of every C-program. The purpose of     *
 *   the main is to initialize the hardware and start the operation       *
 *   system.                                                              *
 *                                                                        *
 **************************************************************************
 *  REMARKS:                                                              *
 *                                                                        *
 *                                                                        *
 **************************************************************************
 *  CHANGE HISTORY:                                                       *
 *   Revision  Date         Author      Description                       *
 *     1.0      06.09.2019   P. Raab     creation                         *
 *     2.0      04.01.2021   P. Raab     port to stm32G474                *
 *                                                                        *
 *                                                                        *
 *************************************************************************/


/* ---------------- G L O B A L   D E F I N I T I O N S ---------------- */

/*  - I n c l u d e s                                                    */

#include <stdint.h>
#include "stm32g474xx.h"
#include "delay.h"
#include "cobit.h"

/* ----------- V A R I A B L E S   &  C O N S T A N T S  --------------- */



/* ------------- F u n c t i o n  P r o t o t y p e s  ----------------- */



/* ----------------------- F U N C T I O N S  -------------------------- */




/* --------------  S t a r t    o f    p r o g r a m  -----------------  */

// Defining a constant for storing number of the tests
const uint8_t number_of_tests = 5;

// Defining a test to check whether 5 and 5 are equal (for those who need to repeat their elementary school completely! Just kidding :) )
Test_Result_Info first_test()
{
	return cobit_assert("First Test Passed!", "First Test Failed!", 5 == 5);
}

// Defining a test to check whether 5 and 7 are equal (to annoy the Peano a little bit! Just kidding :) )
Test_Result_Info second_test()
{
	return cobit_assert("5 and 7 are equal! (sorry Peano)", "5 and 7 are for sure not equal!", 5 == 7);
}

// Defining a test to check whether the GPIOA_MODER has the value of 0
Test_Result_Info third_test()
{
	return cobit_assert("Third Test Passed!", "Third Test Failed!", GPIOA->MODER == 0);
}

// Defining a test to check whether GPIOA_MODER still has its default value
Test_Result_Info fourth_test()
{
	return cobit_assert("Fourth Test Passed!", "Fourth Test Failed!", GPIOA->MODER == 0xABFFFFFF);
}

// Defining a test to check whether the pin 0 of GPIOA is in output mode
Test_Result_Info is_gpioa_0_in_output_mode()
{
	return cobit_assert("GPIOA - Pin 0 is in output mode!", "GPIOA - Pin 0 is NOT in output mode!", (GPIOA->MODER & ((1 << 1) | (1 << 0))) == (1 << 1));
}

int main(void)
{
	// Enbaling the clock for GPIOA
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	// Manipulating the value of GPIOA so that the last test fails
	GPIOA->MODER &= ~(1 << 0);
	// Defining an array to store all test cases
	Test_Function test_functions[number_of_tests] = {first_test, second_test, third_test, fourth_test, is_gpioa_0_in_output_mode};
	// Running/executing all test cases
	run_all_cobit_tests(test_functions, number_of_tests);
	
	// Keeping the program running
	while(1);
}
