/* ACT C4 5.2.1
 * File: C4_ACT_Task3a_lyons41.c
 * Date: 15 February 2017
 * By:  Brian Acosta
 *      acostab
 *      Jory Lyons
 *      lyons41  
 *      Cade Rhodine
 *      crhodine
 *      Noah Stover
 *      nstover
 *      
 * Section: 1
 * Team: 4
 *
 * ELECTRONIC SIGNATURE
 * Brian Acosta
 * Jory Lyons
 * Cade Rhodine
 * Noah Stover
 *
 * The electronic signatures above indicate that the program
 * submitted for evaluation is the combined effort of all
 * team members and that each member of the team was an
 * equal participant in its creation. In addition, each
 * member of the team has a general understanding of
 * all aspects of the program development and execution.
 *
 * This program calculates the factorial of a number.
 */

// gcc -Wall -Werror -lm C4_ACT_Task3a_lyons41.c -o task
 
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