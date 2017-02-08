# Tarea 1 (8.02.2016) 


Todos los códigos deben encontrarse en un repositorio de GitHub con un
Makefile que compile, ejecute el código en C y prepare las gráficas
con el código de Python. La fecha límite de entrega es el Lunes 29
de Febrero del 2016 a las 7AM.

## Shocktube

* (N/2 puntos) Escriba un código en C que resuelva el problema del shock-tube con
 un esquema de Godunov de primer orden utilizando alguna solución aproximada del problema de Riemann para calcular los flujos. Utilice las mismas variables que
 se inicializaron en el [ejemplo con el esquema
 Lax-Friedrichs](https://github.com/ComputoCienciasUniandes/MetodosComputacionalesAvanzados/blob/master/weeks/03/code/shocktube.c).  
  
* (N/2 puntos) Escriba código en Python que compare las solucion numérica con la
 solución analítica para el tiempo final.

## Problema de los tres cuerpos

* (N/2 puntos) Escriba un código en C que implemente un integrador simpléctico y un
  RK4 para generar datos que reproduzcan las gráficas 9 a 17 de [este
  documento](http://www.oberlin.edu/math/Research/FractalsNbodyB.pdf). 

* (N/2 puntos) Escriba un código en Python que utilice los datos
  producidos por el código en C para producir las gráficas.


*N depende del número de integrantes, _n_, del grupo. Si _n_=1, N=70;
 si _n_=2, N=60, si _n_=3, N=50; si _n_=4, N=40; si _n_>4, N=0*