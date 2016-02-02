#ifndef DEFS_H
#define DEFS_H

#define FALSE 0
#define TRUE 1
#define EPSILON 1E-12

void allocate();
void initialize();
double cMax();
void boundaryConditions(double **U);
void upwindGodunovStep();
void LaxFriedrichsStep();
void LapidusViscosity();

extern double L;                    // length of shock tube
extern double gama;               // ratio of specific heats
extern int N;                     // number of grid points

extern double CFL;                // Courant-Friedrichs-Lewy number
extern double nu;                 // artificial viscosity coefficient

extern double **U;                      // solution with 3 components
extern double **newU;                   // new solution
extern double **F;                      // flux with 3 components
extern double *vol;                     // for Roe solver

extern double h;                        // lattice spacing
extern double tau;                      // time step

extern int step;


#endif /*DEFS_H*/
