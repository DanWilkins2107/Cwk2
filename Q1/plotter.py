import matplotlib as mpl
from scipy.integrate import odeint
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

# mpl.rcParams['legend.fontsize'] = 10

#Q1i Code ---------------------------------
def exactUVals(t):
    return (np.exp(-1*t) + np.sin(t) - np.cos(t)) / 2

t,u = np.loadtxt("output_1di.dat", unpack=True)
t_exact = np.linspace(0, 10, 1001)
u_exact = exactUVals(t_exact)  

plt.figure(1)
plt.plot(t_exact, u_exact, color="blue", label="Exact solution")
plt.plot(t, u, color="red", label="Approximation")
plt.legend()
plt.xlabel("t")
plt.ylabel("u(t)")
plt.title("Approximation to ODE")

print(t_exact[-1], u_exact[-1])
print(t[-1], u[-1])

#Q1ii Code ---------------------------------

dt,err = np.loadtxt("output_1dii_errors.dat", unpack=True)      
plt.figure(2)
plt.loglog(dt, err, '.')
plt.grid(True)
plt.xlabel("log(Step Size)")
plt.ylabel("log(Error)")
plt.title("Errors for Various Step Sizes")

plt.show()
