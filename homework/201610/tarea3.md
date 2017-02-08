# Tarea 3 (18.04.2016) 

Todos los códigos deben estar en un repositorio de Github.
La fecha límite de entrega es el Viernes 13 de Mayo del 2016 a las 7AM.  

## Colapso gravitacional esférico

* (N/2 puntos) Escribir un código en C que calcule la evolución
  de un sistema de N-cuerpos durante  5 tiempos dinámicos. 
  El código debe tener un makefile acompañante que muestre cómo se
  debe compilar y ejecutar el código. 
  El código debe tomar al menos dos parámetros de entrada: 
  * N. el número total de cuerpos.  
  * épilon. la distancia típica de suavizado del potencial
  gravitacional.   
  El código debe producir al comienzo y al final de la evolución
  temporal un archivo con 8 columnas y N líneas guardando: posiciones,
  velocidades, energía cinética y energía potencial.
  El código debe conservar la energía total a un nivel del 50%.

## Estimación de parámetros

* (N/2 puntos) Escribir un código de python que implemente MCMC para
  estimar los parámetros que decriben el perfil de densidad resultante
  del sistema. El programa debe tomar como entrada el nombre del
  archivo que contiene las posiciones, velocidades y energías de las
  partículas. Debe producir como resultado una gráfica con el perfil
  de densidad estimado y el la función que describe el perfil de
  densidad, el programa también debe escribir en pantalla los valores
  de los parámetros con su incertidumbre asociada.


### Nota
N=100 para todos los grupos. Hay un bono de 0 a 40 puntos que se da
dependiendo del tiempo que tarde en correr el programa. El programa
más rápido tendrá los 40 puntos de bono.
