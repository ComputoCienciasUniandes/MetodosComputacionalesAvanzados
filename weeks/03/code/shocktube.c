#include <stdio.h>
#include <stdlib.h>
#include "steps.h"
#include "riemann.h"

/*
  C adaptation from C++ code written by Richard J. Gonsalves.
*/ 

typedef void (*solver)(void);
void solve(solver stepAlgorithm, double tMax, char *filename, int plots);

int main()
{
  solve(LaxFriedrichsStep, 1.0, "LaxFriedrichs", 5);
  //   solve(upwindGodunovStep, 1.0, "UpwindGodunov", 5);
}


void solve(solver stepAlgorithm, double tMax, char *filename, int plots)
{
    initialize();

    double t = 0.0;
    int step = 0;
    int plot = 0;
    FILE *out;
    char filename_tmp[1024];
    int j;
    double rho_avg = 0.0, u_avg = 0.0, e_avg = 0.0, P_avg = 0.0;
    double rho, u, e, P;

    tau = CFL * h / cMax();
    while(plot<=plots) {

      sprintf(filename_tmp, "%s_step_%d.dat", filename, plot);
      if(!(out = fopen(filename_tmp, "w"))){
	fprintf(stderr, "problem opening file %s\n", filename);
	exit(1);
      }
      // write solution in plot files and print       
      double rho_avg = 0.0, u_avg = 0.0, e_avg = 0.0, P_avg = 0.0;
      for (j = 0; j < N; j++) {
	rho = U[j][0];
	u = U[j][1] / U[j][0];
	e = U[j][2];
	P = (U[j][2] - U[j][1] * U[j][1] / U[j][0] / 2)
	  * (gama - 1.0);
	rho_avg += rho;
	u_avg += u;
	e_avg += e;
	P_avg += P;
	fprintf(out, "%d\t%f\t%f\t%f\t%f\n", j, rho, u, e, P);
      }

      fclose(out);    
      if (rho_avg != 0.0) rho_avg /= N;
      if (u_avg != 0.0)   u_avg /= N;
      if (e_avg != 0.0)   e_avg /= N;
      if (P_avg != 0.0)   P_avg /= N;
      fprintf(stdout,"Step %d Time %f\tRho_avg %f\t u_avg %f\t e_avg %f\t P_avg %f\n", 
	      step, t,rho_avg,u_avg,e_avg,P_avg);
      plot++;

      while (t < tMax * plot / (double)(plots)) {
	boundaryConditions(U);
	tau = CFL * h / cMax();
	stepAlgorithm();
	t += tau;
	step++;
      }
    }
}


