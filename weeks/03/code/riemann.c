#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "riemann.h"

/*
  Translated from a C++ Riemann solver written by Richard
  J. Gonsalves,  which in turn is rewrite of a Riemann solver
  found in Laney's textbook Computational Gasdynamics (Cambridge
  University Press.)     
 */ 

inline double fg(double x) {
    const double gamma = 1.4;
    const double g2 = (gamma + 1) / (2 * gamma);
    return (x-1) / sqrt(g2 * (x - 1) + 1);
}

void Riemann(double *U1, double *U4, double *F) {
  int i;

  const double gamma = 1.4;
  const double g1 = (gamma - 1) / (2 * gamma);
  const double g2 = (gamma + 1) / (2 * gamma);
  const double g3 = (gamma + 1) / (gamma - 1);
  const double tol = 1e-10;
  
    // compute primitive variables
  double rho1 = U1[0];
  double u1 = U1[1] / rho1;
  double p1 = (U1[2] - rho1 * u1 * u1 / 2) * (gamma - 1);
  double rho4 = U4[0];
  double u4 = U4[1] / rho4;
  double p4 = (U4[2] - rho4 * u4 * u4 / 2) * (gamma - 1);

  // switch states if necessary so high pressure is on left
  int revflag = FALSE;
  if (p4 < p1) {
    double swap = p1; p1 = p4; p4 = swap;
    swap = u1; u1 = -u4; u4 = -swap;
    swap = rho1; rho1 = rho4; rho4 = swap;
    revflag = TRUE;
  }

  F[0] = 0.0;
  F[1] = 0.0;
  F[2] = 0.0;
}
