# RK4 Solver

## Introduction
Saturn's moon Hyperion allows an interesting oppurtunity to study the effects of chaotic behaviour. The aim of this project is to use a simplified model to look at Hyperion and gain insight into how a moons can chaotically tumble. In this repository is the files including Hyperions equations on motion, an RK4 solver and python script to analyse the data.

## Starting
To clone this repository:
```
git clone https://github.com/andrewblance/Hyperion
```

This program is divided over a few files. In ```dxdt.cpp``` the functions and all initial parameters are declared. Currently in this file are examples functions with 2, 4 and 6 variables - the latter representing the motion of Hyperion. The file ```main.cpp``` is where the code for the RK4 solver which is used to solve the equations is. This file also sends the results to a ```.csv``` file  which the two ```.py``` files can read. ```plotter.py``` is designed to take as input 1 ```.csv``` file and output a plot of one of the parameters against another. ```Lyap.py``` takes two ```.csv``` files as input and as a result can calculate the systems Lyapunov exponent. 
Ideally, to add a new function to this program only ```dxdt.cpp``` will need to be modified. However, if you want to set a range of values a parameter must stay within this can only be done through a modification to ```dxdt.cpp```.

## Preparing dxdt.cpp
   1. Write your function, ensuring any other functions currently in the file are commented out.
   2. Choose initial values and set the array ```x[]``` to the correct size.
   3. Set ```n_dim``` to appropriate value (eg. if your function's variables are ```x``` and ```Vx``` then ```n_dim``` should be set to 2, if you have ```x```, ```Vx```, ```y``` and ```Vy``` then ```n_dim``` is 4.)

If you also want to set a range a parameter must stay within (eg, if you want to restrict ```x``` to be between 1 and -1) then this is done in ```main.cpp```.

## Running 
Once the function and initial values have been set the program should be ready to run. To do this:
   1. run ```make```.
   2. run ```./Hyperion```
   3. You will be prompted to decide if you want to enable any restrictions on a parameter. The default restriction will ensure theta stays between pi and negative pi, this is required to solve the problem of Hyperions motion.

Doing this will create a ```.csv``` file containing the results. 

To produce plots one of the ```.py``` files can be modified and run. Calculating a value for the Lyapunov coefficient can also be done in ```Lyap.py```.

## Future Work
We aim at the moment to make the program print a select number of results directly to the terminal, so you could see how the results looked without opening the ```.csv```. Furthermore, it is a goal to change ```dxdt.cpp``` such that it is the only file need to be edited when adding, or changing, a function, ie, it would be nice if any restrictions on the parameters would not need to be declared in ```main.cpp```.






