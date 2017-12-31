import numpy as np
import matplotlib         # These lines are for making it work with windows
matplotlib.use('Agg')
import matplotlib.pyplot as plt

data = np.genfromtxt('results.csv', delimiter = ',', dtype =None)

xdata = data[:,1]
ydata = data[:,2]

plt.scatter(xdata, ydata)
plt.xlabel('x')
plt.ylabel('y')

plt.savefig("Results.png")
plt.show()
