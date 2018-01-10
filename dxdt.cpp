#include "header.h"
using namespace std;

// Choose Initial Values
double init_dist = 1., init_Vel = 1.;
double eccentricity = 0.365;
double a = init_dist / (1. + eccentricity);
double GMs = 4.*pow(M_PI,2);

double x_init = a * (1 + eccentricity), Vx_init = 0., 
       y_init = 0., Vy_init = init_Vel * sqrt( GMs*(1.-eccentricity) / (a * (1.+eccentricity)) ),
       z_init = 0., Vz_init = 0.;
double x0[] = { x_init, Vx_init,
                y_init, Vy_init, 
                z_init, Vz_init };
double t0 = 0., t1 = 9., dt = 0.0001;

const size_t n_dim = 6;
Vector x( x0, n_dim );

// Example of n_dim=2 function
/*
Vector dx_dt( const double t, const Vector x)
{
    Vector output(n_dim);
    output[0] = x[1];
    output[1] = 1;
    return output;
}
*/

// Example of n_dim=4 function
/*
int kappa = 1;
int exponent = 2;
Vector dx_dt( const double t, const Vector x)
{
    double r = sqrt(pow(x[0],2) + pow(x[2],2));
    Vector output(n_dim);

    output[0] = x[1];
    output[1] = -kappa*x[0] / pow(r, exponent+1);
    output[2] = x[3];
    output[3] = -kappa*x[2] / pow(r, exponent+1);
    return output;
}
*/

// Example of n_dim=6 function (Chaotic Tumbling of Hyperion)
int exponent = 2;

Vector dx_dt( const double t, const Vector x)
{           
    double r = sqrt(pow(x[0],2) + pow(x[2],2));
    Vector output(n_dim);

    output[0] = x[1];
    output[1] = -GMs * x[0] / pow(r, exponent+1);
    output[2] = x[3];
    output[3] = -GMs * x[2] / pow(r, exponent+1);
    output[4] = x[5];
    output[5] = - (3.*GMs/pow(r,5)) * (x[0]*sin(x[4]) - x[2]*cos(x[4])) * (x[0]*cos(x[4]) + x[2]*sin(x[4]));
    
    return output;
}





