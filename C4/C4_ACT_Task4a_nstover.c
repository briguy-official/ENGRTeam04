
/* TITLE
 * File: C1_ACT_Task4a_nstover.c
 * Date: 18 January 2017
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
 * This program finds the temperature over time
 */
 
 #include <stdio.h>
 #include <math.h>
 
 double proportional(double expectedValue,double currentValue,double pValue);
 
 int main(void){
	 double intTemp;
	 double desiredTemp;
	 double pValue;
	 double currentTemp;
	 double margin = 5.0;
	 double change;
	 
	 printf("Input Initial temperature: ");
	 scanf("%lf", &intTemp);
	 
	 printf("Input Desired temperature: ");
	 scanf(" %lf", &desiredTemp);
	 
	 printf("Input P value: ");
	 scanf(" %lf", &pValue);
	 
	 currentTemp = intTemp;
	 while (fabs(currentTemp - desiredTemp) > margin){
		 change = proportional(desiredTemp, currentTemp, pValue);
		 currentTemp = currentTemp + change - 3;
		 printf("%.3lf\n", currentTemp);
	 }
	 return 0;
 } 
 
 double proportional(double expectedValue,double currentValue,double pValue){
	 double error;
	 double output;
	 error = expectedValue - currentValue;
	 output = error * pValue;
	 return output;
 }
 