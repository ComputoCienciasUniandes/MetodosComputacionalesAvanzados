
import numpy as np
import matplotlib.pyplot as plt



def model(x,param):
    n_param = len(param)
    y = 0
    for i in range(n_param):
        y += param[i] * x**i
    return y 
    
def loglikelihood(x_obs, y_obs, sigma_y_obs, param):
    d = y_obs -  model(x_obs, param)
    d = d/sigma_y_obs
    d = -0.5 * np.sum(d**2)
    return d

def logprior(param):
    p = 0.0
    n_param = len(param)
    for i in range(n_param):
        if param[i] < 20 and param[i]>-20 :
            p += 0.0
        else:
            p += np.inf
    return p


x_obs = np.array([-2.0,1.3,0.4,5.0,0.1, -4.7, 3.0, -3.5,-1.1])
y_obs = np.array([ -1.931,   2.38,   1.88,  -24.22,   3.31, -21.9,  -5.18, -12.23,   0.822])
sigma_y_obs = np.array([ 2.63,  6.23, -1.461, 1.376, -4.72,  1.313, -4.886, -1.091,  0.8054])

N = 50000
l_param = [np.random.random(3)]
sigma_param = [1.0, 0.5, 0.1]
n_param = len(sigma_param)
for i in range(1,N):
    propuesta  = l_param[i-1] + np.random.normal(size=n_param)*sigma_param
    logposterior_viejo = loglikelihood(x_obs, y_obs, sigma_y_obs, l_param[i-1]) + logprior(l_param[i-1])
    logposterior_nuevo = loglikelihood(x_obs, y_obs, sigma_y_obs, propuesta) + logprior(propuesta)

    r = min(1,np.exp(logposterior_nuevo-logposterior_viejo))
    alpha = np.random.random()
    if(alpha<r):
        l_param.append(propuesta)
    else:
        l_param.append(l_param[i-1])

l_param = np.array(l_param)
print(np.shape(l_param))

best = []
for i in range(n_param):
    best.append(np.mean(l_param[:,i]))

print(best)

x_model = np.linspace(x_obs.min(), x_obs.max(), 100)
y_model = model(x_model, best)

plt.errorbar(x_obs,y_obs, yerr=sigma_y_obs, fmt='o', label='obs')
plt.plot(x_model, y_model, label='model')
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.savefig('best_model.pdf')

