import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

t,u = np.loadtxt("output.dat", unpack=True)        

mpl.rcParams['legend.fontsize'] = 10

plt.figure(1)
ax1 = plt.subplot(211)
ax1.plot(t, u)
plt.xlabel("t")
plt.ylabel("u(t)")
plt.title("Approximation to ODE")

dt,err = np.loadtxt("errors.dat", unpack=True)        

ax2 = plt.subplot(212)
ax2.loglog(dt, err, '.')
plt.legend(['Numerical error'])
ax2.grid(True)
plt.xlabel("dt")
plt.ylabel("Error")

plt.show()
