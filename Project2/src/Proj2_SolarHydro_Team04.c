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
* This program calculates the Cost/Efficiency Analysis of the system.
*/

// gcc -Wall -Werror -lm Proj2_SolarHydro_Team04.c -o Proj2

#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 4.0 * atan(1.0)

int main(void){
    const double Eout = 120 * 3600 * 1e6; //Joules energy out
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
    double K3 = 0.0; //   bend coefficient 3
    double K4 = 0.0; //   bend coefficient 4
    double A = 0; //area of reservoir
    
    // Outputs
    // double A = 0.0; //m^2   reservoir surface area CONSTANT
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
    
    double vUp = 0.0;   
    double vUpSq = 0.0;
    double vDown = 0.0; 
    double vDownSq = 0.0;
    double pipeArea = 0.0;
    long double m = 0.0; //kg   mass stored in reservoir
    double effElev = 0.0;
    double width = 0.0; //width of bottom of tank
    double length = 0.0; //lenght of bottom of tank
    int property = 0; //number of property (1, 2, 3)
    // double Eloss = 0.0;
    
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
    
    printf("Bend Coefficient 3: ");
    scanf(" %lf", &K3);
    
    printf("Bend Coefficient 4: ");
    scanf(" %lf", &K4);
    
    
    // intermediate calculations
    pipeArea = PI * D * D / 4.0;
    vDown = Qturbine / pipeArea;
    vDownSq = vDown * vDown;
    vUp = Qpump / pipeArea;
    vUpSq = vUp * vUp;
    effElev = H + (depth / 2.0);
    
    /* m = (Eout + (Eout * ((1/etaT) - 1))) / (g * effElev - (fPDown
        * L * vDownSq / (2 * D)) - ((K1 * vDownSq / 2) + (K2 * vDownSq / 2)));
        //old equation */ 
    
    m = (Eout + Eout * ((1.0 / etaT) - 1.0)) / 
        (g * effElev - (vDownSq / 2.0) * (K1 + K2 + K3 + K4 + (f * L / D)));
    
    Ein = (1.0 / etaP) * m * (g * effElev + (vUpSq / 2.0) * 
          (K1 + K2 + (f * L / D)));
        
    etaS = Eout / Ein;
    timeIn = (m / rho) / Qpump;
    timeOut = (m / rho) / Qturbine;
       
    //on ground (2m) = 500 dollars / meter
    //off ground = onground + 250 * area from ground
    A = m / (rho * depth);
    
    // BEGINNING OF COST
    if (depth >= 20.0) {
        cost += ((depth-17.5)*(340-250)*(2.5));
    }
    if (depth >= 17.5) {
        cost += ((depth-15)*(250-180)*(2.5));
    }
    if (depth >= 15.0) {
        cost += ((depth-12.5)*(180-135)*(2.5));
    }
    if (depth >= 12.5) {
        cost += ((depth-10)*(135-95)*(2.5));
    }
    if (depth >= 10.0) {
        cost += ((depth-7.5)*(95-60)*(2.5));
    }
    if (depth >= 7.5) {
        cost += ((depth-7.5)*(95-60)*(2.5));
    }
    if (depth >= 5.0) {
        cost += ((depth-5.0)*(60-30)*(2.5));
    }   
    cost *= length * width; //cost of walls
    cost += 100000; //+cost of pump house
    switch (property) {
        case 1:
            cost += 40000; //road
            break;
        case 2:
            cost += 100000; //road
            break;
        case 3:
            cost += 150000; //road
            break;
    }

    Ein /= 3600.0 * 1000000.0;
    timeIn /= 3600;
    timeOut /= 3600;
    
    printf("\nPipe Area: %.2lf\n", pipeArea);
    printf("Velocity up: %.2lf\n", vUp);
    printf("Velocity down: %.2lf\n", vDown);
    printf("Effective elevation: %.2lf\n", effElev);
    printf("Energy Out in Joules: %.2le\n\n", ((Ein * etaS) * 3600 * 1e6));
    
    printf("Mass stored in reservoir: %.2Le\n", m);
    printf("Area of Reservoir: %.2le\n", A);
    printf("Input Energy: %.2lf \n", Ein);
    printf("System Efficiency: %.2lf \n", etaS);
    printf("Time to Fill: %.2lf \n", timeIn); // must be less than 12 hours
    printf("Time to Empty: %.2lf \n", timeOut);
    
    return 0;
}