#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

const double W = 2.98768765; // omega, in rad/s
const double k  = 0.1;
const double m  = 2;
  const double TA = 0.0;
  const double TB = 10.0;
  const double H  = 0.1;
  const int NSTEPS = (TB)/H;
void rk4(double ta, double tb, double h, std::vector<double> & y);
double f(double t, const std::vector<double> & y, int id);

int main (void)
{
  const double N  = 2;
  const double TA = 0;
  const double TB = 100;
  const double H  = 0.01;
  std::vector<double> y = {1.0, 2.0,3.0,4.0,5.0 }; // {x0, v0} 

  rk4(TA, TB, H, y);

  return 0;
}



void rk4(double ta, double tb, double h, std::vector<double> & y)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(y.size());
  k2.resize(y.size());
  k3.resize(y.size());
  k4.resize(y.size());
  aux.resize(y.size());

  const int N = (tb-ta)/h;
  for (int nt = 0; nt < N; ++nt) {
    double t = ta + h*nt;
    // k1
    for(int ii = 0; ii < y.size(); ++ii) {
      k1[ii] = h*f(t, y, ii);
    }
    // k2 aux
    for(int ii = 0; ii < y.size(); ++ii) {
      aux[ii] = y[ii] + k1[ii]/2;
    }
    //k2
    for(int ii = 0; ii < y.size(); ++ii) {
      k2[ii] = h*f(t + h/2, aux, ii);
    }
    // k3 aux
    for(int ii = 0; ii < y.size(); ++ii) {
      aux[ii] = y[ii] + k2[ii]/2;
    }
    //k3
    for(int ii = 0; ii < y.size(); ++ii) {
      k3[ii] = h*f(t + h/2, aux, ii);
    }
    // k4 aux
    for(int ii = 0; ii < y.size(); ++ii) {
      aux[ii] = y[ii] + k3[ii];
    }
    //k4
    for(int ii = 0; ii < y.size(); ++ii) {
      k4[ii] = h*f(t + h, aux, ii);
    }
    // write new y
    for(int ii = 0; ii < y.size(); ++ii) {
      y[ii] = y[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
    std::cout << t << "\t" << y[0] << "\t" << y[1] << "\t" << y[2]<< "\t" << y[3]<< "\t" << y[4] <<std::endl;
  }
}

double f(double t, const std::vector<double> & y, int id)
{
  if (0 == id) {
 
    return (-k*(2*y[0]-y[1]))/m;
  }
  else if (1 == id) {
    return (k*(y[2]-2*y[1]+y[0]))/m ;
  }
  else if (2 == id) {
    return (k*(y[3]-2*y[2]+y[1]))/8;
  }
  else if (3 == id) {
    return (k*(y[4]-2*y[3]+y[2]))/m; 
  }
  else if (4 == id) {
    return (k*(y[3]-2*y[4]))/m; 
  }
   else {
    std::cerr << "ERROR!!!!!!!! Id does not exists -> " << id << std::endl;
   exit(1);
     }
}
