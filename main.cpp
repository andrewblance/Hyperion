#include "header.h"
using namespace std;

int main()
{
    Vector dx1, dx2, dx3, dx4;
    double t = t0;
    double Tolerance = 1e-12;
    
    // create n vectors to store x results in
    vector< vector<double> > xx;
    for (int i=0; i<n_dim; i++)
    {
        vector<double> myvec;
        myvec.push_back(i);
        xx.push_back(myvec);
    }
    vector<float> tt;

    // open .csv file
    ofstream myfile;
    myfile.open("results.csv");
    
    // RK4 solver
    while (t < t1)
    {
        dx1 = dt * dx_dt(t         , x          );
    	dx2 = dt * dx_dt(t + 0.5*dt, x + 0.5*dx1);
    	dx3 = dt * dx_dt(t + 0.5*dt, x + 0.5*dx2);
    	dx4 = dt * dx_dt(t +     dt, x +     dx3);
        
        // Adds t & x[] to appropriate vectors
        for (int i=0; i<n_dim; i++)
        {
           xx[i].push_back(x[i]);
        }
	tt.push_back(t);

/*     // Broken???
    	if ( fabs(t-round(t)) < Tolerance)   // will print x & t to terminal if t is a round num
	{
	    cout << "For t = " << t << ", x[0] = " << x[0] << ", x[1] = " << x[1] << endl;
	}
*/
        x  += (1.0/6.0)*(dx1 + 2.0*dx2 + 2.0*dx3 + dx4);
	t  += dt;
    }

    // print results to csv
    int vec_size = tt.size();
    for (int n=0; n<vec_size; n++)
    {
        if (n_dim == 2)
        {
            myfile << tt[n] << "," << xx[0][n] << "," << xx[1][n] << endl;
        }
        if (n_dim == 4)
        {
	    myfile << tt[n] << "," << xx[0][n] << "," << xx[1][n] << "," << xx[2][n] << "," << xx[3][n] << endl;
        }
    }
    myfile.close();

    // open .py file to produce plot
    char filename[] = "plotter.py";
    FILE* fp;
    Py_Initialize();
    fp = fopen(filename, "r");
    PyRun_SimpleFile(fp, filename);
    Py_Finalize();

    return 0;
}
