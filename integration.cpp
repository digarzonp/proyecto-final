#include "simulation.h"



void initial_conditions(std::vector<Particle> & balls)
{

  
  const int NX=1.0;
  for(int id=0; id<balls.size(); ++id){
  balls[id].Rx =id*NX ;
  balls[id].Vx = 0.0;
 
  }
}
  
void compute_force(std::vector<Particle> & balls)
{
  for(auto & body : balls){
    
    
    body.Fx += -2*k*balls[N].Rx+k*balls[N-1].Rx;
  }
}


void start_integration(std::vector<Particle> & balls)
{
  for(auto & body : balls){
    body.Vx -= 0.5*body.Fx*DT/body.mass;
  }
}

//void integrate(std::vector<Particle> & balls)
//{
  // use simple leap-frog
  //  for(auto & body : balls){
  //body.Vx += body.Fx*DT/body.mass;
  //body.Rx += body.Vx*DT;
  //
  //}
  void rk4(double ta, double tb, double h, std::vector<Particle> & balls)
{
  std::vector<double> k1, k2, k3, k4, aux;
  k1.resize(balls.size());
  k2.resize(balls.size());
  k3.resize(balls.size());
  k4.resize(balls.size());
  aux.resize(balls.size());

  const int N = (tb-ta)/h;
  for (int nt = 0; nt < N; ++nt) {
    double t = ta + h*nt;
    // k1
    for(int ii = 0; ii < balls.size(); ++ii) {
      k1[ii] = h*f(t, balls, ii);
    }
    // k2 aux
    for(int ii = 0; ii < balls.size(); ++ii) {
      aux[ii] = balls[ii] + k1[ii]/2;
    }
    //k2
    for(int ii = 0; ii < balls.size(); ++ii) {
      k2[ii] = h*f(t + h/2, aux, ii);
    }
    // k3 aux
    for(int ii = 0; ii < balls.size(); ++ii) {
      aux[ii] = balls[ii] + k2[ii]/2;
    }
    //k3
    for(int ii = 0; ii < balls.size(); ++ii) {
      k3[ii] = h*f(t + h/2, aux, ii);
    }
    // k4 aux
    for(int ii = 0; ii < balls.size(); ++ii) {
      aux[ii] = balls[ii] + k3[ii];
    }
    //k4
    for(int ii = 0; ii < balls.size(); ++ii) {
      k4[ii] = h*f(t + h, aux, ii);
    }
    // write new y
    for(int ii = 0; ii < balls.size(); ++ii) {
      balls[ii] = balls[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }
    std::cout << t << "\t" << balls[ii].Rx << "\t" << balls[ii].Vx << std::endl;
  }
}


double f(double t, const std::vector<Particle> & balls, int id)
{
  if (0 == id) {
    return balls[1];
  }
  else if (1 == id) {
    return (-2*k*balls[N].Rx+k*balls[N-1].Rx)/mass;
  }
  else {
    std::cerr << "ERROR!!!!!!!! Id does not exists -> " << id << std::endl;
    exit(1);
  }
}

  
// }
//}

// void print_info(const std::vector<Particle> & balls, const double & time)
// {
//   // here we print something useful
//   // for now is just a test
//   std::cout.precision(16);
//   std::cout.setf(std::ios::scientific);

//   std::cout << time
//             << "\t" << balls[0].Rx
//             << "\t" << balls[0].Ry 
//             << "\t" << balls[0].Rz 
//             << "\t" << balls[0].Vx 
//             << "\t" << balls[0].Vy 
//             << "\t" << balls[0].Vz 
//             << "\n";
// }
///void print(const std::vector<Particle> & balls)

// for(int i=0; i< n;i++)
// {
//  for(int a=0; a< 100;a++)
//	{
//    std::cout<< DT*a<< "\t" << balls[i].Rx << "\n";
//	}

//	}
//}
