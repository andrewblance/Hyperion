import numpy as np
import matplotlib         # These lines are for making it work with windows
matplotlib.use('Agg')
import matplotlib.pyplot as plt

data = np.genfromtxt('results.csv', delimiter = ',', dtype =None)

xdata = data[:,0]
ydata = data[:,6]

plt.plot(xdata, ydata)
plt.title('Hyperion eta versus time')
plt.xlabel('time (yr)')
plt.ylabel('radians')

plt.savefig("Results.png")
plt.show()
