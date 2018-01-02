#include "header.h"
using namespace std;

// Choose Initial Values
double x_init = 1., y_init = 0., Vx_init = 0., Vy_init = 2*M_PI , theta_init = 0., w_init = 0.; 
double x0[] = { x_init, y_init, Vx_init, Vy_init, theta_init, w_init };
double t0 = 0., t1 = 9., dt = 0.0001;

const size_t n_dim = 6;
Vector x( x0, n_dim );

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

Vector dx_dt( const double t, const Vector x)
{
    Vector output(n_dim);
    output[0] = x[1];
    output[1] = 1;
    return output;
}
z*/

Vector dx_dt( const double t, const Vector x)
{
    double GMs = 4.*pow(M_PI,2);
    double kappa = 1.;
    double exponent = 2;
    double r = sqrt(pow(x[0],2) + pow(x[1],2));
    Vector output(n_dim);

    output[0] = x[2];   
    output[1] = x[3];
    output[2] = -GMs* kappa*x[0] / pow(r, exponent+1.);
    output[3] = -GMs* kappa*x[1] / pow(r, exponent+1.);
    output[4] = x[5];
    output[5] = - (3.*GMs/pow(r,5)) * (x[0]*sin(x[4]) - x[1]*cos(x[4])) * (x[0]*cos(x[4]) + x[1]*sin(x[4]));
    
    return output;
}





