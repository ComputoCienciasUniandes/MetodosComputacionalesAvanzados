
import matplotlib 
matplotlib.use('Agg')

import numpy as np
import matplotlib.pyplot as plt



def model(param):
    """
    Modelo de alcance maximo dado param[0] (angulo) y param[1] (velocidad)
    """
    y = (np.sin(2.0*param[0])*param[1]**2)/9.8
    return y 
    
def loglikelihood(y_obs, sigma_y_obs, param):
    """
    Log de la verosimilitud de los alcances observados (y_obs, sigma_y_obs)
    dados los parametros param[0] (angulo) y param[1] (velocidad).
    """
    d = y_obs -  model(param)
    d = d/sigma_y_obs
    d = -0.5 * np.sum(d**2)
    return d

def logprior(param):
    """
    Logprior para param[0] (angulo) y param[1] (velocidad)
    """
    if param[0] > 0 and param[0] < np.pi/2.0 and param[1]>0 and param[1]<1000:
        p = 0.0
    else:        
        p = -np.inf
    return p


y_obs = np.array([880.0, 795.0, 782.0, 976.0, 178.0])
sigma_y_obs = 5.0 * np.ones(len(y_obs))

N = 100000
l_param = [np.array([np.pi/4.0, 10.0])]
sigma_param = np.array([0.1, 1.0])
n_param = len(sigma_param)
for i in range(1,N):
    propuesta  = l_param[i-1] + np.random.normal(size=n_param)*sigma_param
    logposterior_viejo = loglikelihood(y_obs, sigma_y_obs, l_param[i-1]) + logprior(l_param[i-1])
    logposterior_nuevo = loglikelihood(y_obs, sigma_y_obs, propuesta) + logprior(propuesta)

    r = min(1,np.exp(logposterior_nuevo-logposterior_viejo))
    alpha = np.random.random()
    if(alpha<r):
        l_param.append(propuesta)
    else:
        l_param.append(l_param[i-1])

l_param = np.array(l_param)
l_param = l_param[N//10:,:] # descartamos el primer 10% de la cadena

v_medio  = np.mean(l_param[:,1])
v_sigma = np.std(l_param[:,1])
title = "$v = {:.1f} \pm {:.1f} $ km/s".format(v_medio, v_sigma)

_ = plt.hist(l_param[:,1], bins=20, density=True)
plt.title(title)
plt.xlabel("$v_0$ (km/s)")
plt.ylabel("PDF ($v_0$|observaciones)")
plt.savefig('Ejercicio8.pdf')
plt.clf()

plt.scatter(l_param[:,0], l_param[:,1], s=1.0, alpha=0.1)
plt.xlabel(r'$\theta$ (radianes)')
plt.ylabel(r'$v_0$ (m/s)')
plt.savefig('vel_theta.pdf')

