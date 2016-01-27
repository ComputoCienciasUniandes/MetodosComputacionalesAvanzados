#include <stdio.h>
#include <math.h>


void RK4_step(double * x_step, double * v_step, double delta_t, double t, 
	      double x, double v);
void leapfrog_step(double * x_step, double  * v_step, double delta_t, 
		   double t, double x, double v);
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

    RK4_step(&x_step, &v_step, delta_t, t, x_RK4, v_RK4);
    x_RK4 += x_step;
    v_RK4 += v_step;

    leapfrog_step(&x_step, &v_step, delta_t, t, x_LF, v_LF);
    x_LF += x_step;
    v_LF += v_step;

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

void leapfrog_step(double * x_step, double  * v_step, double delta_t, double t, double x, double v){
  double step_x;
  double step_v;
  /*kick*/
  step_v = deriv_v(t,x,v) * delta_t * 0.5;

  /*drift*/
  step_x = (v + step_v) * delta_t;

  /*kick*/
  step_v = step_v + deriv_v(t, x + step_x, v) * delta_t * 0.5;

  *x_step = step_x;
  *v_step = step_v;
}

void RK4_step(double * x_step, double  * v_step, double delta_t, double t, double x, double v){
  double k1, k2, k3, k4;
  double l1, l2, l3, l4;

  k1 = deriv_x(t,x,v);  
  l1 = deriv_v(t,x,v);  

  k2 = deriv_x(t + delta_t*0.5, x + k1*delta_t*0.5, v + l1*delta_t*0.5);
  l2 = deriv_v(t + delta_t*0.5, x + k1*delta_t*0.5, v + l1*delta_t*0.5) ;

  k3 = deriv_x(t + delta_t*0.5, x + k2*delta_t*0.5, v + l2*delta_t*0.5);
  l3 = deriv_v(t + delta_t*0.5, x + k2*delta_t*0.5, v + l2*delta_t*0.5);

  k4 = deriv_x(t + delta_t, x + k3*delta_t, v + l3*delta_t);
  l4 = deriv_v(t + delta_t, x + k3*delta_t, v + l3*delta_t);

  *x_step = (k1/6.0 + k2/3.0 + k3/3.0 + k4/6.0)*delta_t;
  *v_step = (l1/6.0 + l2/3.0 + l3/3.0 + l4/6.0)*delta_t;
}
