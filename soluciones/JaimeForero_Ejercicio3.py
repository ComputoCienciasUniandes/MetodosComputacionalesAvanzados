import matplotlib 
matplotlib.use('Agg')

import numpy as np
import matplotlib.pyplot as plt

def prior(p_a, f="flat"):
    n_points = len(p_a)
    if f=="flat":
        p = np.ones(n_points)
    return p

def likelihood(s, p_a):
    n_a = s.count('a')
    n_b = s.count('b')
    return (p_a)**n_a * (1-p_a)**n_b

def max_prob(p_a, pdf_p_a):
    ii = np.argmax(pdf_p_a)
    return p_a[ii]

def mean(p_a, pdf_p_a):
    return np.trapz(pdf_p_a*p_a, p_a)

def sigma(p_a, pdf_p_a):
    m = mean(p_a, pdf_p_a)
    s = np.trapz(pdf_p_a*p_a*p_a, p_a)
    return np.sqrt(s - m**2)

def posterior(s):
    n_points = 1000
    p_a = np.linspace(0.0, 1.0, n_points)

    p =  prior(p_a)
    l = likelihood(s, p_a)

    post = p * l # Bayes

    norm = np.trapz(post, p_a)
    post = post/norm

    mp = max_prob(p_a, post)
    m = mean(p_a, post)
    sig = sigma(p_a, post)

    values = 'Max Prob = {:.2f}, Mean = {:.2f}, Sigma={:.2f}'.format(mp, m, sig)

    
    plt.plot(p_a, post , label="data= {}".format(s))
    plt.title(values)
    plt.legend()
    plt.xlabel('$p_a$')
    plt.ylabel('$PDF (p_a|data)$')
    plt.savefig('posterior.pdf')
