import numpy as np
import matplotlib.pyplot as plt

def f(x, l=10):
    if(np.isscalar(x)):# esto va a funcionar si entra un numero (escalar)
        if x>1E-6:
            y = l*(1/x**2)*np.exp(-l/x)
        else:
            y = 0.0
    else: # esto funciona si es un array
        y = l*(1/x**2)*np.exp(-l/x)
        ii = x<1E-6
        y[ii] = 0
    return y

def metropolis(N=100000):
    lista = [np.random.random()]
    sigma_delta = 4.0

    for i in range(1,N):
        propuesta  = lista[i-1] + np.random.normal(loc=0.0, scale=sigma_delta)
        r = min(1,f(propuesta)/f(lista[i-1]))
        alpha = np.random.random()
        if(alpha<r):
            lista.append(propuesta)
        else:
            lista.append(lista[i-1])
            
    return np.array(lista)

cadena = metropolis()

x = np.linspace(cadena.min(),cadena.max(),1000)
plt.plot(x, f(x))
plt.hist(cadena, density=True, bins=200)
plt.xlim([0,100])
plt.xlabel('x')
plt.ylabel('PDF(x)')
plt.savefig('metropolis.pdf')
