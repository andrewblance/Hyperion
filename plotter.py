import numpy as np
import matplotlib         # These lines are for making it work with windows
matplotlib.use('Agg')
import matplotlib.pyplot as plt

data = np.genfromtxt('results.csv', delimiter = ',', dtype =None)
columns = len(data[1,:])

title_input = input("What is the title of the plot? ")

print("Lets choose the axis for the plot!")
if columns == 3:
    print("The options are: ")
    print("0: time, 1: x, 2: Vx")
if columns == 5: 
    print("The options are: ")
    print("0: time, 1: x, 2: Vx, 3: y, 4: Vy")
if columns == 7:
    print("The options are: ")
    print("0: time, 1: x, 2: Vx, 3: y, 4: Vy, 5: z, 6: Vz")

xinput = input("What data do you want shown on the x axis? ")
x_label = input("What is the label for the x axis? ")
xdata = data[:,xinput]

yinput = input("What data do you want shown on the y axis? ")
y_label = input("What is the label for the y axis? ")
ydata = data[:,yinput]

plt.plot(xdata, ydata)
plt.title(title_input)
plt.xlabel(x_label)
plt.ylabel(y_label)

plt.savefig("Results.png")
plt.show()
