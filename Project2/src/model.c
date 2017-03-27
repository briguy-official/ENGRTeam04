/* Proj2_SolarHydro_Team04
 * File: Proj2_SolarHydro_Team04.c
 * Date: 23 March 2017
 * By:      Brian Acosta
 *          acostab
 *          Cade Rhodine
 *          crhodine
 *          Jory Lyons
 *          lyons41
 *          Noah Stover 
 *          nstover
 *      
 * Section: 1
 * Team: 4
 *
 * ELECTRONIC SIGNATURE
 * Jory Lyons
 *
 * The electronic signatures above indicate that the program
 * submitted for evaluation is the combined effort of all
 * team members and that each member of the team was an
 * equal participant in its creation. In addition, each
 * member of the team has a general understanding of
 * all aspects of the program development and execution.
 *
 * This program calculates the Cost/Efficiency Analysis of the system.
 */

// gcc -Wall -Werror -lm Proj2_SolarHydro_Team04.c -o Proj2

#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 4.0 * atan(1.0)

int main(void){
    const int Eout = 120; //MWh  energy out
    const double g = 9.81; //m/s^2  gravity
    const int rho =  1000; //kg/m^3  density of water
    
    // Inputs
    double etaP = 0.0; //   pump efficiency
    double etaT = 0.0; //   turbine efficiency
    double D = 0.0; //m   pipe diameter
    double L = 0.0; //m   pipe length
    double f = 0.0; //   pipe friction factor
    double depth = 0.0; //   reservoir depth
    double H = 0.0; //m   elevation of bottom of reservoir
    double Qpump = 0.0; //m^3/s   volumetric flow rate of pump
    double Qturbine = 0.0; //m^3/s   volumetric flow rate of turbine
    double K1 = 0.0; //   bend coefficient 1
    double K2 = 0.0; //   bend coefficient 2
      
    double fPUp = 0.0; //pipe friction up
    double fPDown = 0.0; //pipe friction down
    
    // Outputs
    double A = 0.0; //m^2   reservoir surface area CONSTANT
    double Ein = 0.0; //MWh input energy
    double etaS = 0.0; //   system efficiency
    double timeIn = 0.0; //   time to fill 
    double timeOut = 0.0; //   time to empty 
    
    // Assumptions
    /* 
    Reservoir is completely filled when Eout is equal to the desired 120MWh
    Pumps output constant volume of water per second (may differ between pumps)
    Turbines will always accept as input a constant volume of water per second 
    Pipes are full of water at accounting (thus, it will have no effect)
    account for the depth of the reservoir when calculating potential energy
    Mass is at heigh of 0.5 * depth
    */
    
    double v = 0.0; //m/s   velocity CONSTANT
    double vUp = 0.0; 
    double vDown = 0.0;
    double m = 0.0; //kg   mass stored in reservoir
    double Eloss = 0.0;
    
    double cost = 0.0; //dollars
  
    printf("Pump Efficiency: ");
    scanf(" %lf", &etaP);
    
    printf("Turbine efficiency: ");
    scanf(" %lf", &etaT);
  
    printf("Pipe diameter: ");
    scanf(" %lf", &D);
  
    printf("Pipe length: ");
    scanf(" %lf", &L);
    
    printf("Pipe friction factor: ");
    scanf(" %lf", &f);
      
    printf("Reservoir depth: ");
    scanf(" %lf", &depth);
           
    printf("Elevation of Bottom of Reservoir: ");
    scanf(" %lf", &H);
  
  	printf("Volumetric Flow Rate of Pump: ");
    scanf(" %lf", &Qpump);
           
    printf("Volumetric Flow Rate of Turbine: ");
    scanf(" %lf", &Qturbine);

    printf("Bend Coefficient 1: ");
    scanf(" %lf", &K1);
    
    printf("Bend Coefficient 2: ");
    scanf(" %lf", &K2);
  
    
  
    switch depth { // cost from height of reservoir walls
        case depth >= 20.0:
            cost += ((depth-17.5)*(340-250)*(2.5));
            //break;
        case depth >= 17.5:
            cost += ((depth-15)*(250-180)*(2.5));
            //break;
        case depth >= 15.0:
            cost += ((depth-12.5)*(180-135)*(2.5));
            //break;  
        case depth >= 12.5:
            cost += ((depth-10)*(135-95)*(2.5));
            //break;
        case depth >= 10.0:
            cost += ((depth-7.5)*(95-60)*(2.5));
            //break;
        case depth >= 7.5:
            cost += ((depth-7.5)*(95-60)*(2.5));
            //break;
        case depth >= 5.0:
            cost += ((depth-5.0)*(60-30)*(2.5));
            break;
    }
    
    //on ground (2m) = 500 dollars / meter
    //off ground = onground + 250 * area from ground
    
    printf("Reservoir Surface Area: %lf \n");
  	printf("Input Energy: %lf \n");
  	printf("System Efficiency: %lf \n");
  	printf("Time to Fill: %lf \n"); // msut be less than 12 hours
  	printf("Time to Empty: %lf \n);
  
    return 0;
}