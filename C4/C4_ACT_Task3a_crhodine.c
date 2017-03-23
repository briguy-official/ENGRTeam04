/* Activity: C4 ACT
 * File:    C4_ACT_Task3a_crhodine.c
 * Date:    Feb 8, 2017
 * By:      Cade Rhodine
 *          crhodine
 *			Jory Lyons
 *			lyons41
 *			Brian Acosta
 *			acostab
 *			Noah Stover
 *			nstover
 * Section: H01
 * Team:     04
 *
 * ELECTRONIC SIGNATURE
 * Cade Nicolas Rhodine
 * Jory Lyons
 * Brian Acosta
 * Noah Stover
 *
 * The electronic signature above indicates that the program 
 * submitted for evaluation is my individual work. I have
 * a general understanding of all aspects of its development
 * and execution.
 *
 * Perform arithmetic operations, create valid identifiers,
 * implement the use of expressions, and explain the differences 
 * between various data types in Python.*/
 
#include <stdio.h>

int MyFactorial(int num, int factorial);

int main(void){
	int num = 0.0;
	int factorial = 0.0;
	
	factorial = 1;
	printf("Enter Number: ");
	scanf("%d", &num);
	factorial = MyFactorial(num, factorial);
	
    printf("The factorial of %d is %d.\n", num, factorial);
return 0;
}

int MyFactorial (int num, int factorial){
	while (num > 1){
		factorial = factorial * num;
		num = num - 1;
		
	}
	return factorial;
}