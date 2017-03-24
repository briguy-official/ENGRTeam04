/* ACT C4 5.2.1
 * File: C4_ACT_Task2a_lyons41.c
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
 * This program calculates a matrix given the amount of rows and columns.  
 */

// gcc -Wall -Werror -lm C4_ACT_Task2a_lyons41.c -o task

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
	
	for (i = 1; i <= numRows; ++i){
		printf("%d", i);
		for(j = i; j < i + numColumns-1;){
			printf(" %d", ++j);
		}
	    printf("\n");
	}
	return 0;
}