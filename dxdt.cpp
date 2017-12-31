#include "header.h"
using namespace std;

// Choose Initial Values
double x_init = 0., y_init = 0., Vx_init = -0.5, Vy_init = 0. ; 
double x0[] = { x_init, y_init };
double t0 = 0., t1 = 5., dt = 0.1;

const size_t n_dim = 2;
Vector x( x0, n_dim);

// Write your function!

/*
Vector dx_dt( const double t, const Vector x)
{
    int kappa = 1;
    int exponent = 2;
    double r = sqrt(pow(x[0],2.0) + pow(x[1],2.0));
    Vector output(n_dim);
    output[0] = x[2];
    output[1] = x[3];
    output[2] = -kappa*x[0] / ( pow(r, exponent+1));
    output[3] = -kappa*x[1] / ( pow(r, exponent+1));
    return output;
}
*/

Vector dx_dt( const double t, const Vector x)
{
    Vector output(n_dim);
    output[0] = x[1];
    output[1] = 1;
    return output;
}


