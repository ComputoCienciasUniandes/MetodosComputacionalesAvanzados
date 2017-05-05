Los datos de `proper_yam_final_results.csv` provienen de [este repositorio](https://github.com/saint-germain/planetas_datos/blob/master/README.md).

Las columnas corresponden a

| Column Name   | Meaning       | Importance (*)  | Initial parameter? |
| ------------- |:-------------:| :-----:| ----------|
| ident     	| unique system identifier | high | Y |
| it   		  	 | iteration index      |   none | Y |
| t 			   	     | simulation time (yr)      | low    | Y |
| a(i)				       		  | planet semi-major axis (AU)| high		| |
| emegas(i)					    | planet gas mass (M_earth) | medium | |
| emepla(i)/emet| planet solid mass (M_earth)| high | |
| rplanet(i)/radtie| planet solid radius | low | |
| emestar	     	    | stellar mass (g) | high | Y |
| rc            | disk outer cutoff radius (AU) | high | Y |
| qest | Toomre Q at min radius | none | Y |
| sigmag_0 | maximum dust surface density (g/cm^3) | high | Y |
| emed | disk mass (M_sun) | high | Y |
| gama | surface density power law exponent | none |Y 
| apert | perturbation amplitude | high|Y 
| fpert | perturbation length scale | none |Y 
| constmigI | type I migration rate | none |Y 
| emetal | metallicity wrt solar | high |Y 
| taugas | gas dissipation timescale (yr) | high | Y 

Cada sistema corresponde a una estrella.