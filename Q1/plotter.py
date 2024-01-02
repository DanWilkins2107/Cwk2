import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

# mpl.rcParams['legend.fontsize'] = 10

#Q1 Code
t,u = np.loadtxt("output_1di.dat", unpack=True)        

plt.figure(1)
plt.plot(t, u)
plt.xlabel("t")
plt.ylabel("u(t)")
plt.title("Approximation to ODE")

# dt,err = np.loadtxt("errors.dat", unpack=True)        

# ax2 = plt.subplot(212)
# ax2.loglog(dt, err, '.')
# plt.legend(['Numerical error'])
# ax2.grid(True)
# plt.xlabel("dt")
# plt.ylabel("Error")

plt.show()
