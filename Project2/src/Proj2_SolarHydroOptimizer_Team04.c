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
#include <float.h>

#define PI 4.0 * atan(1.0)

double efficiency(double etaP, double etaT, double D, double L, double f, 
                  double depth, double H, double Qpump, double Qturbine, 
                  double K1, double K2, double K3, double MAX_AREA, double* SA);
int main(void){
    // constants
    int PUMPING_COSTS[5];
    int TURBINE_COSTS[5];
    double FITTING_COSTS_1[13];
    double FITTING_COSTS_2[13];
    double FITTING_COSTS_3[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double K1;
    double K2;
    double K3;
    double L;
    double H;
   
    double PIPE_COSTS[13][6] =
    {   {1.00, 1.20, 1.44, 2.16, 2.70, 2.97}, 
        {1.20, 1.44, 1.72, 2.58, 2.23, 3.55}, 
        {2.57, 3.08, 3.70, 5.55, 6.94, 7.64},
        {6.30, 7.56, 9.07, 14.0, 17.0, 19.0},
        {14.0, 16.0, 20.0, 29.0, 37.0, 40.0},
        {26.0, 31.0, 37.0, 55.0, 69.0, 76.0},
        {43.0, 52.0, 63.0, 94.0, 117.0, 129.0},
        {68.0, 82.0, 98.0, 148.0, 185.0, 203.0},
        {102.0, 122.0, 146.0, 219.0, 274.0, 302.0},
        {144.0, 173.0, 208.0, 311.0, 389.0, 428.0},
        {197.0, 237.0, 284.0, 426.0, 533.0, 586.0},
        {262.0, 315.0, 378.0, 567.0, 708.0, 779.0},
        {340.0, 408.0, 490.0, 735.0, 919.0, 1101.0} };
        
    const double ETA_P[] = {0.8, 0.83, 0.86, 0.89, 0.92};
    const double PIPE_FRICTIONS[] = {0.05, 0.03, 0.02, 0.01, 0.0005, 0.002};
    const double PIPE_DIAMETERS[] = {0.1, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 
                                    2.0, 2.25, 2.5, 2.75, 3.0};
    const double ETA_T[] = {0.83, 0.86, 0.89, 0.92, 0.94};
    double ACCESS_COST;
    double PREP_COST;
    double EXTRA_COST;
    double MAX_AREA;
    
    // things that will vary
    int zone;
    // int pipeCost = 0.0;
    // int turbineCost = 0.0;
    // double fitCost1 = 0.0;
    // double fitCost2 = 0.0;
    // double fitCost3 = 0.0;
    double k1 = 0.0;
    double k2 = 0.0;
    double k3 = 0.0;
    double D = 0.0;
    double f = 0.0;
    double etaP = 0.0;
    double etaT = 0.0;
    double depth = 0.0;
    double Qpump = 0.0;
    double Qturbine = 0.0;
    
    double etaS;
    double minCostPerEff = DBL_MAX;
    double cost;
    double optimalEtaS;
    double optimalCost;
    double costPerEff;
    double SA;
    
    // Counters
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int numCalcs = 0;
    
    printf("Enter zone: ");
    scanf(" %d", &zone);
    
    switch (zone) {
        case 1 :
            PUMPING_COSTS[0] = 242; PUMPING_COSTS[1] = 290; 
            PUMPING_COSTS[2] = 348; PUMPING_COSTS[3] = 418;
            PUMPING_COSTS[4] = 502;
            
            TURBINE_COSTS[0] = 436; TURBINE_COSTS[1] = 532; 
            TURBINE_COSTS[2] = 627; TURBINE_COSTS[3] = 753;
            TURBINE_COSTS[4] = 903;
            

            FITTING_COSTS_1[0] = 1.05; FITTING_COSTS_1[1] = 1.57; 
            FITTING_COSTS_1[2] = 5.17; FITTING_COSTS_1[3] = 15;
            FITTING_COSTS_1[4] = 34; FITTING_COSTS_1[5] = 65; 
            FITTING_COSTS_1[6] = 112; FITTING_COSTS_1[7] = 178; 
            FITTING_COSTS_1[8] = 265; FITTING_COSTS_1[9] = 377;
            FITTING_COSTS_1[10] = 516; FITTING_COSTS_1[11] = 687; 
            FITTING_COSTS_1[12] = 892; 
            
            FITTING_COSTS_2[0] = 1.05; FITTING_COSTS_2[1] = 1.57; 
            FITTING_COSTS_2[2] = 5.17; FITTING_COSTS_2[3] = 15;
            FITTING_COSTS_2[4] = 34; FITTING_COSTS_2[5] = 65; 
            FITTING_COSTS_2[6] = 112; FITTING_COSTS_2[7] = 178; 
            FITTING_COSTS_2[8] = 265; FITTING_COSTS_2[9] = 377;
            FITTING_COSTS_2[10] = 516; FITTING_COSTS_2[11] = 687; 
            FITTING_COSTS_2[12] = 892; 

            L = 68;
            H = 30;
            K1 = .15;
            K2 = .15;
            K3 = 0;
            MAX_AREA = 360000;
            PREP_COST = .25;
            ACCESS_COST = 40000;
            EXTRA_COST = 8000;
            break;
            
        case 2 :
            PUMPING_COSTS[0] = 472; PUMPING_COSTS[1] = 566; 
            PUMPING_COSTS[2] = 679; PUMPING_COSTS[3] = 815;
            PUMPING_COSTS[4] = 978;
            
            TURBINE_COSTS[0] = 849; TURBINE_COSTS[1] = 1019; 
            TURBINE_COSTS[2] = 1222; TURBINE_COSTS[3] = 1467;
            TURBINE_COSTS[4] = 1760;
            
            FITTING_COSTS_1[0] = 1.05; FITTING_COSTS_1[1] = 1.57; 
            FITTING_COSTS_1[2] = 5.17; FITTING_COSTS_1[3] = 15;
            FITTING_COSTS_1[4] = 34; FITTING_COSTS_1[5] = 65; 
            FITTING_COSTS_1[6] = 112; FITTING_COSTS_1[7] = 178; 
            FITTING_COSTS_1[8] = 265; FITTING_COSTS_1[9] = 377;
            FITTING_COSTS_1[10] = 516; FITTING_COSTS_1[11] = 687; 
            FITTING_COSTS_1[12] = 892; 
            
            FITTING_COSTS_2[0] = 1.16; FITTING_COSTS_2[1] = 1.73; 
            FITTING_COSTS_2[2] = 5.70; FITTING_COSTS_2[3] = 16;
            FITTING_COSTS_2[4] = 38; FITTING_COSTS_2[5] = 72; 
            FITTING_COSTS_2[6] = 124; FITTING_COSTS_2[7] = 196; 
            FITTING_COSTS_2[8] = 292; FITTING_COSTS_2[9] = 415;
            FITTING_COSTS_2[10] = 569; FITTING_COSTS_2[11] = 757; 
            FITTING_COSTS_2[12] = 983; 
           
            L = 188;
            H = 100;
            K1 = .15;
            K2 = .22;
            K3 = 0;
            MAX_AREA = 20156;
            PREP_COST = .5;
            ACCESS_COST = 100000;
            EXTRA_COST = 2000;
            break;
            
        case 3 :
            PUMPING_COSTS[0] = 322; PUMPING_COSTS[1] = 387; 
            PUMPING_COSTS[2] = 464; PUMPING_COSTS[3] = 557;
            PUMPING_COSTS[4] = 668;
            
            TURBINE_COSTS[0] = 580; TURBINE_COSTS[1] = 696; 
            TURBINE_COSTS[2] = 835; TURBINE_COSTS[3] = 1002;
            TURBINE_COSTS[4] = 1202;
            
            FITTING_COSTS_1[0] = 1.0; FITTING_COSTS_1[1] = 1.49; 
            FITTING_COSTS_1[2] = 4.93; FITTING_COSTS_1[3] = 14;
            FITTING_COSTS_1[4] = 32; FITTING_COSTS_1[5] = 62; 
            FITTING_COSTS_1[6] = 107; FITTING_COSTS_1[7] = 169; 
            FITTING_COSTS_1[8] = 252; FITTING_COSTS_1[9] = 359;
            FITTING_COSTS_1[10] = 492; FITTING_COSTS_1[11] = 654; 
            FITTING_COSTS_1[12] = 849; 
            
            FITTING_COSTS_2[0] = 1.0; FITTING_COSTS_2[1] = 1.49; 
            FITTING_COSTS_2[2] = 4.93; FITTING_COSTS_2[3] = 14;
            FITTING_COSTS_2[4] = 32; FITTING_COSTS_2[5] = 62; 
            FITTING_COSTS_2[6] = 107; FITTING_COSTS_2[7] = 169; 
            FITTING_COSTS_2[8] = 252; FITTING_COSTS_2[9] = 359;
            FITTING_COSTS_2[10] = 492; FITTING_COSTS_2[11] = 654; 
            FITTING_COSTS_2[12] = 849; 
            
            FITTING_COSTS_3[0] = 1.1; FITTING_COSTS_3[1] = 1.64; 
            FITTING_COSTS_3[2] = 5.43; FITTING_COSTS_3[3] = 16;
            FITTING_COSTS_3[4] = 39; FITTING_COSTS_3[5] = 69; 
            FITTING_COSTS_3[6] = 118; FITTING_COSTS_3[7] = 187; 
            FITTING_COSTS_3[8] = 278; FITTING_COSTS_3[9] = 396;
            FITTING_COSTS_3[10] = 542; FITTING_COSTS_3[11] = 721; 
            FITTING_COSTS_3[12] = 936; 
            
            L = 126;
            H = 65;
            K1 = .1;
            K2 = .1;
            K3 = .2;
            MAX_AREA = 39761;
            PREP_COST = 1.2;
            ACCESS_COST = 150000;
            EXTRA_COST = 0;
            break;
    }
    
    for (i = 0; i < 13; i++){ // Diameter counter
        for(j = 1; j < 20; j++){ // Depth counter
            for(k = 0; k < 5; k++){ // Counter for etaT
                for(l = 0; l < 5; l++){ //counter for etaP
                    for(a = 0; a < 6; a++){ //pipe friction counter
                        for(b = 0; b < 100; b++){ // pump flow rate counter
                            for(c = 0; c < 100; c++){ //turbine flow rate counter
                            numCalcs ++;
                            etaS = 
                                efficiency(
                                    ETA_P[l], 
                                    ETA_T[k], 
                                    PIPE_DIAMETERS[i],
                                    L,
                                    PIPE_FRICTIONS[a], 
                                    j, // depth
                                    H, 
                                    b, //Qpump
                                    c, //Qturbine
                                    K1, 
                                    K2,
                                    K3,
                                    MAX_AREA,
                                    &SA);
                                    
                            //printf("%lf\n", etaS);
                            
                            if (etaS < 0){
                                continue;
                            }
                            
                            // COST ASSUMPTIONS:
                            // No extenuating circumstances (i.e. moving bodies)
                            // all reservoirs are circles
                            cost = b * PUMPING_COSTS[l] + c * TURBINE_COSTS[k] +
                                   PIPE_COSTS[i][a] * L + FITTING_COSTS_1[i] +
                                   FITTING_COSTS_2[i] + FITTING_COSTS_3[i] +
                                   ACCESS_COST + PREP_COST * SA + EXTRA_COST;
                            
                            if (j >= 20.0) {
                                cost += ((j-17.5)*(340-250)*(2.5));
                            }
                            if (j >= 17.5) {
                                cost += 2 * PI * sqrt(SA / PI) *
                                ((j-15)*(250-180)*(2.5));
                            }
                            if (j >= 15.0) {
                                cost += 2 * PI * sqrt(SA / PI) *
                                ((j-12.5)*(180-135)*(2.5));
                            }
                            if (j >= 12.5) {
                                cost += 2 * PI * sqrt(SA / PI) *
                                ((j-10)*(135-95)*(2.5));
                            }
                            if (j >= 10.0) {
                                cost += 2 * PI * sqrt(SA / PI) *
                                ((j-7.5)*(95-60)*(2.5));
                            }
                            if (j >= 7.5) {
                                cost += 2 * PI * sqrt(SA / PI) *
                                ((j-7.5)*(95-60)*(2.5));
                            }
                            if (j >= 5.0) {
                                cost += 2 * PI * sqrt(SA / PI) *
                                ((j-5.0)*(60-30)*(2.5));
                            }
                            
                            cost += 100000;
                            
                            costPerEff = cost / etaS;
                            
                            if (minCostPerEff > costPerEff){
                                minCostPerEff = costPerEff;
                                optimalCost = cost;
                                optimalEtaS = etaS;
                                etaP = ETA_P[l]; 
                                etaT = ETA_T[k];
                                D = PIPE_DIAMETERS[i];
                                f = PIPE_FRICTIONS[a]; 
                                depth = j; // depth 
                                Qpump = b; //Qpump
                                Qturbine = c; //Qturbine
                                k1 = K1; 
                                k2 = K2;
                                k3 = K3;
                            }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("Cost: %.2lf\n", optimalCost);
    printf("Efficiency: %.2lf\n", optimalEtaS);
    printf("Cost to Efficiency ratio: %.2lf\n", minCostPerEff);
    printf("Pump efficiency: %.2lf\n", etaP);
    printf("Turbine efficiency: %.2lf\n", etaT);
    printf("Pipe diameter: %.2lf\n", D);
    printf("Pipe friction: %.4lf\n", f);
    printf("Depth: %.2lf\n", depth);
    printf("Pump Vol FLow Rate: %.2lf\n", Qpump);
    printf("Turbine Vol Flow Rate: %.2lf\n", Qturbine);
    printf("K1: %.2lf\n", k1);
    printf("K2: %.2lf\n", k2);
    printf("K3: %.2lf\n", k3);
    printf("H: %.2lf\n", H);
    printf("Combinations checked: %d\n", numCalcs);
    
    return 0;
}

double efficiency(double etaP, double etaT, double D, double L, double f, 
                  double depth, double H, double Qpump, double Qturbine, 
                  double K1, double K2, double K3, double MAX_AREA, double* SA){

    const double E_OUT = 120 * 3600 * 1e6; //Joules energy out
    const double G = 9.81; //m/s^2  gravity
    const int RHO =  1000; //kg/m^3  density of water
    const int MAX_TIME = 12; //hours
    
    double A = 0; //area of reservoir
    double Ein = 0.0; //MWh input energy
    double etaS = 0.0; //   system efficiency
    double timeIn = 0.0; //   time to fill
    double timeOut = 0.0; //   time to empty    
    
    // Assumptions
    /*
    Reservoir is completely filled when E_OUT is equal to the desired 120MWh
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
    
    // intermediate calculations
    pipeArea = PI * D * D / 4.0;
    vDown = Qturbine / pipeArea;
    vDownSq = vDown * vDown;
    vUp = Qpump / pipeArea;
    vUpSq = vUp * vUp;
    effElev = H + (depth / 2.0);
    
    m = (E_OUT + E_OUT * ((1.0 / etaT) - 1.0)) / 
        (G * effElev - (vDownSq / 2.0) * (K1 + K2 + K3 + (f * L / D)));
    
    timeIn = ((m / RHO) / Qpump) / 3600;
    timeOut = ((m / RHO) / Qturbine) / 3600;
    A = m / (RHO * depth);
    
    if (timeIn > MAX_TIME || timeOut > MAX_TIME || A > MAX_AREA){
        return -1; // flags an invalid parameter setup
    }
    
    *SA = A;
    Ein = (1.0 / etaP) * m * (G * effElev + (vUpSq / 2.0) * 
          (K1 + K2 + K3 + (f * L / D)));
        
    etaS = E_OUT / Ein;
    
    if (etaS > 1.0){
        return -1;
    }
    
    return etaS;
}