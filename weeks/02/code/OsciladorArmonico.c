#include <stdio.h>
#include <math.h>


void RK4_step(double delta_t, double t, double *x, double *v);
void leapfrog_step(double delta_t, double t, double *x, double *v);
double deriv_x(double t, double x, double v);
double deriv_v(double t, double x, double v);

int main(){
  double x_RK4, x_LF;
  double v_RK4, v_LF;
  double t;

  double T=1E5;
  double delta_t=1E-1;
  int n_step = (int)(T/delta_t);
  double x_step = 0.0;
  double v_step = 0.0;
  int i;

  t=0.0;
  x_RK4=1.0;
  v_RK4=0.0;
  x_LF=1.0;
  v_LF=0.0;
  
  for(i=0;i<n_step;i++){    
    printf("%f %.15e %.15e %.15e %.15e \n", t, x_RK4, v_RK4, x_LF, v_LF);
    RK4_step(delta_t, t, &x_RK4, &v_RK4);
    leapfrog_step(delta_t, t, &x_LF, &v_LF);
    t += delta_t;
  }

  return 0;
}

double deriv_x(double t, double x, double v){
  return v;
}

double deriv_v(double t, double x, double v){
  return -x;
}

void leapfrog_step(double delta_t, double t, double *x, double *v){
  double x_in;
  double v_in;
  x_in = *x;
  v_in = *v;

  /*kick*/
  v_in += 0.5 * deriv_v(t,x_in,v_in) * delta_t;
  /*drift*/
  x_in += 1.0 * v_in * delta_t;
  /*kick*/
  v_in += 0.5 * deriv_v(t, x_in, v_in) * delta_t;


  *x = x_in;
  *v = v_in;
}

void RK4_step(double delta_t, double t, double *x, double *v){
  double k1, k2, k3, k4;
  double l1, l2, l3, l4;
  double x_in;
  double v_in;
  x_in = *x;
  v_in = *v;


  k1 = deriv_x(t,x_in,v_in);  
  l1 = deriv_v(t,x_in,v_in);  

  k2 = deriv_x(t + delta_t*0.5, x_in + k1*delta_t*0.5, v_in + l1*delta_t*0.5);
  l2 = deriv_v(t + delta_t*0.5, x_in + k1*delta_t*0.5, v_in + l1*delta_t*0.5) ;

  k3 = deriv_x(t + delta_t*0.5, x_in + k2*delta_t*0.5, v_in + l2*delta_t*0.5);
  l3 = deriv_v(t + delta_t*0.5, x_in + k2*delta_t*0.5, v_in + l2*delta_t*0.5);

  k4 = deriv_x(t + delta_t, x_in + k3*delta_t, v_in + l3*delta_t);
  l4 = deriv_v(t + delta_t, x_in + k3*delta_t, v_in + l3*delta_t);

  x_in += (k1/6.0 + k2/3.0 + k3/3.0 + k4/6.0)*delta_t;
  v_in += (l1/6.0 + l2/3.0 + l3/3.0 + l4/6.0)*delta_t;

  *x = x_in;
  *v = v_in;
}
