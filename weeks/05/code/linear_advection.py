import numpy as np
import matplotlib.pyplot as plt

def initial(delta_x=5.0):
    L = 300.0    
    N = L/delta_x + 1
    x = np.linspace(0.0, L, N)
    u = np.zeros(N)
    ii = (x>=50) & (x<=110)
    u[ii] = 100 * np.sin(np.pi * (x[ii]-50)/60.0)
    return x, u

def FTFS(u, t_max=0.45, delta_t=0.015, delta_x=5.0, a =  300.0):
    N_t = int(t_max/delta_t)
    u_final = u.copy()
    for i in range(N_t):
        u_final[1:-1] = u[1:-1] - (a*delta_t/delta_x)*(u[2:]-u[1:-1])
        u = u_final.copy()
    return u_final


def FTCS(u, t_max=0.45, delta_t=0.015, delta_x=5.0, a =  300.0):
    N_t = int(t_max/delta_t)
    u_final = u.copy()
    for i in range(N_t):
        u_final[1:-1] = u[1:-1] - 0.5*(a*delta_t/delta_x)*(u[2:]-u[0:-2])
        u = u_final.copy()
    return u_final

x, u_init = initial()
u_final_A = FTFS(u_init,a=-40.0)

x, u_init = initial()
u_final_B = FTCS(u_init, a=-40.0)

plt.plot(x,u_init)
plt.plot(x, u_final_A)
plt.plot(x, u_final_B)

plt.show()
