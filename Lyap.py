import numpy as np
import matplotlib         # These lines are for making it work with windows
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from scipy.stats import linregress 
from scipy.optimize import curve_fit
from pylab import *


data1 = np.genfromtxt('eUNr0.csv'  , delimiter = ',', dtype =None)
data2 = np.genfromtxt('eUNr001.csv', delimiter = ',', dtype =None)

psi1 = data1[:,5]
psi2 = data2[:,5]

diff = np.abs(psi1 - psi2)
fdiff = diff[:45000]

xdata = data1[:,0]
fxdata = xdata[:45000]

def func(xdata,a, b):
    return a*np.exp(b*xdata)
popt, pcov = curve_fit(func,fxdata, fdiff, p0=(1,0.1))
print popt
perr = np.sqrt(np.diag(pcov))
print perr


plt.plot(xdata, diff)
plt.rc('text', usetex=True)
plt.title(r'Hyperion $\Delta\theta$ versus time ($\Delta\theta_0 = 0.01$)', fontsize=20)
plt.text(6,0.000008,r'Elliptical Orbit ($\theta$ unrestricted)',horizontalalignment='center',fontsize=18)
plt.yscale('log')
plt.xlabel("time (yr)", fontsize = 18)
plt.ylabel(r"$\Delta\theta$ (radians)", fontsize = 18)
plt.plot(fxdata,func(fxdata,popt[0],popt[1]), label=r'$\lambda =$ %.2f $\pm$ %.2f'%(popt[1], perr[1]))
plt.legend(loc =4)

plt.savefig('results.png')
