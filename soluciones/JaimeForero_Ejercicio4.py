import matplotlib 
matplotlib.use('Agg')

import numpy as np
import matplotlib.pyplot as plt


n_personas_obs = 2
edad_maxima_obs = 40

edad_final = np.arange(0, 500)
n_edades = len(edad_final)

n_intentos_por_edad = 10000


lista_edades_final = []
for i in range(n_edades):
    n_in = 0 
    for j in range(n_intentos_por_edad):
        a = np.int_(np.random.uniform(low=0, 
                                      high=edad_final[i], 
                                      size=n_personas_obs))
        if(a.max()==edad_maxima_obs):
            lista_edades_final.append(edad_final[i])


def max_prob(p_a, pdf_p_a):
    ii = np.argmax(pdf_p_a)
    return p_a[ii]

def mean(p_a, pdf_p_a):
    return np.trapz(pdf_p_a*p_a, p_a)

def sigma(p_a, pdf_p_a):
    m = mean(p_a, pdf_p_a)
    s = np.trapz(pdf_p_a*p_a*p_a, p_a)
    return np.sqrt(s - m**2)




distro, bins,_ = plt.hist(lista_edades_final, bins=edad_final, density=True)


mp = max_prob(bins[:-1], distro)
m = mean(bins[:-1], distro)
sig = sigma(bins[:-1], distro)
values = 'Max Prob = {:.2f}, Mean = {:.2f}, Sigma={:.2f}'.format(mp, m, sig)
plt.title(values)
plt.xlabel('Edad Maxima Posible')
plt.ylabel('PDF (Edad Maxima Posible|data)')
plt.savefig('posterior_edad_maxima.pdf')
