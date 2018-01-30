import numpy as np
import matplotlib         # These lines are for making it work with windows
matplotlib.use('Agg')
import matplotlib.pyplot as plt

data = np.genfromtxt('results.csv', delimiter = ',', dtype =None)
columns = len(data[1,:])

xdata = data[:,0]
ydata = data[:,5]

plt.rc('text', usetex=True)
plt.plot(xdata, ydata)
plt.title(r'Hyperion $\theta$ versus time ($\theta_0 = 0$)', fontsize=20)
plt.text(4.5,3.6,'Circular Orbit', horizontalalignment='center', fontsize=18)

plt.xlabel('time (yr)', fontsize=18)
plt.ylabel(r'$\theta$ (radians)', fontsize=18)

plt.savefig("Results.png")
plt.show()
