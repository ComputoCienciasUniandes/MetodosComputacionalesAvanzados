# Tarea 2 (28.03.2016) 

Todos los notebooks deben encontrarse en un repositorio de GitHub.
Solamente se pueden utilizar librerias de Python que se hayan demostrado en clase.
La fecha límite de entrega es el Lunes 18 de Abril del 2016 a las 7AM. 

## Fundamentos de clasificación

* (N/3 puntos) Siguiendo el libro de texto [Elements of Statistical
Learning - ](http://statweb.stanford.edu/~tibs/ElemStatLearn/) (*ESL*) que se
puede [bajar gratuitamente](http://statweb.stanford.edu/~tibs/ElemStatLearn/printings/ESLII_print10.pdf).
Escriba un notebook de IPython / Jupyter que reproduzca las Figuras
2.1, 2.2, 2.3 y 2.4 de *ESL* siguiendo [este ejemplo escrito en ```R```](http://finiterank.github.io/TESL/tresmodelos.html) 

## Vino

* (N/3 puntos) 
Utilizando estos datos sobre
[vino](http://archive.ics.uci.edu/ml/datasets/Wine) escriba un
notebook  de IPython / Jupyter  que clasifique de la mejor manera los
datos usando: k-means (¿cuántos clusters son el numero óptimo?),
PCA (¿cuántas componentes son las óptimas?) y random forests (¿cuántos
árboles son las óptimos?). Justifique cuál de los tres metodos produce los
mejores resultados de clasificación en este caso.



## P-values

* (N/3 puntos) El uso y el abuso de los p-values en estudios
  científicos ha sido señalado desde hace varios años ([aqui un
  ejemplo
  reciente](http://www.nature.com/news/statisticians-issue-warning-over-misuse-of-p-values-1.19503)). 
Esto  motivó a Nicholas Taleb a publicar un [video](https://www.youtube.com/watch?v=8qrfSh07rT0) y [un borrador de un
  paper](http://www.fooledbyrandomness.com/pvalues.pdf) donde muestra que en realidad los p-values para un experimento
  dado siguen una meta-distribucion. Es decir, que si se pudiera repetir
  un experimento varias veces, y se calculara el p-value para cada
  iteración, podría encontrarse una distribucion para estos
  p-values. Taleb concluye: 
```There should be no surprise that a
previously deemed significant test fails during replication
–in fact it is the replication of results deemed significant
at a close margin that should be surprising.```
Escriba un notebook de IPython-Jupyter que implemente un experimento
  numérico sencillo para mostrar la meta-distribucion de
  p-values y caracterizar las propiedades (mínimo, máximo, media) en
  función del número de experimentos.  

### Nota
N depende del número de integrantes, _n_, del grupo. Si _n_=1, N=140;
 si _n_=2, N=120, si _n_=3, N=100; si _n_=4, N=80; si _n_>4, N=0*