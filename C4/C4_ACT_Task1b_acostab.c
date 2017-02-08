/* Activity 5.2.1 C4 ACT
 * File:    C4_ACT_Task1b_acostab.c
 * Date:    02/08/2017
 * By:      Brian Acosta
 *          acostab
 *          Cade Rhodine
 *          crhodine
 *          Jory Lyons
 *          lyons41
 *          Noah Stover 
 *          nstover
 *          Section: 1
 *          Team: 04
 *
 * ELECTRONIC SIGNATURE
 * Brian Acosta
 * Cade Rhodine
 * Jory Lyons
 * Noah Stovers
 *
 * The electronic signatures above indicate that the program
 * submitted for evaluation is the combined effort of all
 * team members and that each member of the team was an
 * equal participant in its creation. In addition, each
 * member of the team has a general understanding of
 * all aspects of the program development and execution.
 *
 * Calculate the dimensions of a circle of user defined radius
 */

#include <stdio.h>
#include <math.h>
#define PI 4.0 * atan(1.0)

int main (void){
    // declare variables
    double rad = 0;
    double circumf = 0;
    double area = 0;
    double eps = 0.00000001;
    
    //ask user for initial radius
    printf("Enter circle radius (between -1 and 0 to quit): ");
    scanf(" %lf", &rad);
    
    // robustly check if -1 < rad < 0 as loop condition
    while (!(rad < 0 && rad > -1) && fabs(rad) > eps && fabs(rad + 1) > eps){
        // calculate and print dimensions
        circumf = 2 * PI * rad;
        area = PI * pow(rad, 2);
        printf("\nArea: %.3lf\nCircumference: %.3lf", area, circumf);
        
        // prompt user for new radius
        printf("\n\nEnter circle radius (between -1 and 0 to quit): ");
        scanf(" %lf", &rad);
    }
    
    return 0;
}