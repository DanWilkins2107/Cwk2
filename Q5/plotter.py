from mpl_toolkits import mplot3d
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import matplotlib.pyplot as plt
import numpy as np

xmin =   0;
xmax =   1;
tmin =   0;
tmax =   1;

# Load spatial nodes
x = np.loadtxt('x_nodes.dat')
nx = x.size;

# Load solution
data  = np.loadtxt('time_history.dat')

# Time points
t = data[:,0]

# Spatio-temporal grid
X, T = np.meshgrid(x, t)

# Spatio-temporal profile
U = data[:,1::]

# Plot initial and final state
plt.figure(1)
plt.plot(x, data[0,1::], '.-', label='u(x,t0)')
plt.plot(x, data[-1,1::], '.-', label='u(x,T)')
plt.xlim(xmin,xmax)
plt.xlabel("x")
plt.ylabel("u")
legend = plt.legend()

## 3D Plot of u(x,t)
fig = plt.figure(2)
ax = plt.axes(projection='3d')
surf = ax.plot_surface(X, T, U, rstride=1, cstride=1, cmap=cm.coolwarm,
                       linewidth=0.005, antialiased=False)
plt.title("Solution")
ax.set_xlabel("x")
ax.set_ylabel("t")
ax.set_zlabel("u(x,t)")

# Colormap of u(x,t)
fig = plt.figure(3)
ax = plt.pcolor(X, T, U)
plt.xlim(xmin,xmax)
plt.ylim(tmin,tmax)
plt.xlabel("x")
plt.ylabel("t")
cb = fig.colorbar(ax)
cb.set_label("u(x,t)")

plt.show()

