/* Activity C4 ACT
 * File:    C4_ACT_Task2b_crhodine
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
 * between various data types in Python.
 */


#include <stdio.h>

int main(void){
	double numRows = 0.0;
	double numColumns = 0.0;
	int i = 0;
	int j = 0;
	
	printf("Number of rows: ");
	scanf("%lf", &numRows);
	printf("Number of columns: ");
	scanf("%lf", &numColumns);
	
	i = 1;
	j = 1;
	while (i <= numRows){
		printf("%d", i);
		j = i;
		while(j < i + numColumns-1){
			printf(" %d", ++j);
		}
	    printf("\n");
		i = i + 1;
	}
	return 0;
}