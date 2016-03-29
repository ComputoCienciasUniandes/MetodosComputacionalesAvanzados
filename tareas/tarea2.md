# Tarea 1 (8.02.2016) 


Todos los notebooks deben encontrarse en un repositorio de GitHub.
Solamente se pueden utilizar librerias de Python que se hayan mostrado en clase.
La fecha límite de entrega es el Lunes 18 de Abril del 2016 a las 7AM. 

## Fundamentos de clasificacion

* (N/3 puntos) Siguiendo el libro de texto [Elements of Statistical
Learning - ](http://statweb.stanford.edu/~tibs/ElemStatLearn/) (*ESL*) que se
puede [bajar
gratuitamente](http://statweb.stanford.edu/~tibs/ElemStatLearn/printings/ESLII_print10.pdf).
Escriba un notebook de IPython / Jupyter que reproduzca las Figuras
2.1, 2.2, 2.3 y 2.4 de *ESL* siguiendo [este ejemplo escrito en
  ```R```](http://finiterank.github.io/TESL/tresmodelos.html) 

## Vino

* (N/3 puntos) 
Utilizando estos datos sobre
[vino](http://archive.ics.uci.edu/ml/datasets/Wine) escriba un
notebook  IPython / Jupyter  que clasifique de la mejor manera los datos usando: k-means
(cuantos clusters son el numero optimo),
PCA (cuantas componentes son las optimas) y random forests (cuantos
arboles son los optimos). Justifique cual de los tres metodos produce los
mejores resultados de clasificacion.



## P-values


* (N/3 puntos) El uso y el abuso de los p-values en estudios
  cientificos ha sido señalado hace varios años ([aqui un ejemplo reciente](http://www.nature.com/news/statisticians-issue-warning-over-misuse-of-p-values-1.19503)). Esto
  motivo a Nicholas Taleb a publicar un [video](https://www.youtube.com/watch?v=8qrfSh07rT0) y [un borrador de un
  paper](http://www.fooledbyrandomness.com/pvalues.pdf) donde muestra que en realidad los p-values para un experimento
  dado siguen una meta-distribucion. Es decir, que si se pudiera repetir
  un experimento varias veces, y se calcularan el p-value para cada
  iteracion, podria encontrar una distribucion para estos
  p-values. Taleb concluye: _There should be no surprise that a
previously deemed significant test fails during replication
–in fact it is the replication of results deemed significant
at a close margin that should be surprising_.
  Escriba un notebook de IPython-Jupyter que implemente un experimento
  numerico sencillo para mostrar la meta-distribucion de p-values.  


* N depende del número de integrantes, _n_, del grupo. Si _n_=1, N=140;
 si _n_=2, N=120, si _n_=3, N=100; si _n_=4, N=80; si _n_>4, N=0*