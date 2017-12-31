#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <valarray>
#include <vector>
#include <math.h>
#include <python2.7/Python.h>

typedef std::valarray<double> Vector;

extern const size_t n_dim;
extern double x0[];
extern double t0, t1, dt;
extern Vector x;

Vector dx_dt( const double t, const Vector x);

#endif
