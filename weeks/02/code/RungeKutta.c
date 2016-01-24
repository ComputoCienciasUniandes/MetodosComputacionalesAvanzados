#include <stdio.h>
#include <math.h>

typedef double (*derivative)(double t, double y);
double RK2_step(double step, double t, double y, derivative dev);
double RK4_step(double step, double t, double y, derivative dev);
double func_y(double t, double y);
double exact_sol_y(double t);

int main(void){
  double y_RK2;
  double y_RK4;
  double t;
  int i;

  double T=2.0;
  double step=1E-2;
  int n_step = (int)(T/step);

  t=0.0;
  y_RK2=1.0;
  y_RK4=1.0;
  for(i=0;i<n_step;i++){    
    printf("%f %.15e %.15e %.15e\n", t, exact_sol_y(t), y_RK2, y_RK4);
    y_RK2 += RK2_step(step, t, y_RK2, func_y);
    y_RK4 += RK4_step(step, t, y_RK4, func_y);
    t += step;
  }
  
  return 0;
}

double RK2_step(double step, double t, double y, derivative dev){
  double k1, k2;
  double y_step;
  k1 = dev(t,y);
  k2 = dev(t+step, y + k1*step);
  y_step = 0.5*(k1+k2)*step;
  return y_step;
}

double RK4_step(double step, double t, double y, derivative dev){
  double k1, k2, k3, k4;
  double y_step;
  k1 = dev(t,y);
  k2 = dev(t + step*0.5, y + k1*step*0.5);
  k3 = dev(t + step*0.5, y + k2*step*0.5);
  k4 = dev(t + step, y + k3*step);
  y_step = (k1/6.0 + k2/3.0 + k3/3.0 + k4/6.0)*step;
  return y_step;
}

double func_y(double t, double y){
  double v;
  v = y + t*t ;
  return v;
}

double exact_sol_y(double t){
  return 3.0*exp(t) - t*t -2*t -2;
}




