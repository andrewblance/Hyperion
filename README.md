# RK4 Solver

## Introduction


## Starting
To clone this repository:
```
git clone https://github.com/andrewblance/Hyperion
```

This program is divided over a few files. In ```dxdt.cpp``` the functions and all initial parameters are declared. Currently in this file are examples functions with 2, 4 and 6 variables - the latter representing the motion of Hyperion. The file ```main.cpp``` is where the code for the RK4 solver is. This file also sends the results to a ```.csv``` file and initialises ```plotter.py```. 
Ideally, to add a new function to this program only ```dxdt.cpp``` will need to be modified. However, if you want to set a range of values a parameter must stay within this can only be done through a modification to ```dxdt.cpp```.

## Preparing dxdt.cpp
   1. Write your function, ensuring any other functions currently in the file are commented out.
   2. Choose initial values.
   3. Set ```n_dim``` to appropriate value (eg. if your function's variables are ```x``` and ```Vx``` then ```n_dim``` should be set to 2, if you have ```x```, ```Vx```, ```y``` and ```Vy``` then ```n_dim``` is 4.)
   4. Set the array ```x[]``` to the correct size.

If you also want to set a range a parameter must stay within (eg, if you want to restrict ```x``` to be between 1 and -1) then this is done in ```main.cpp```.

To choose what is being plotted modifications can be made to ```plotter.py```.

## Running 
Once the function and initial values have been set the program should be ready to run. To do this:
   1. run ```make```.
   2. run ```./Hyperion```

Doing this should create a ```.csv``` file containing the results and the plot specified in the ```.py``` file.

## Future Work
We aim at the moment to make the program print a select number of results directly to the terminal, so you could see how the results looked without opening the ```.csv```. Also we would like to update the program to allow the user to select certain initial parameters by entering them into the terminal instead of having to declare them in ```dxdt.cpp```. Furthermore, it is a goal to change ```dxdt.cpp``` such that it is the only file need to be edited when adding, or changing, a function.






