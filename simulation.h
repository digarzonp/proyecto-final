#include "resorte.h"
#include<vector>
#include<random>
#include<iostream>

const double TA = 0;
const double TB = 16.4;
const double H  = 0.01;
const double L=1000;
const double N=3; // número de partículas
const double k=2; // constante de elasticidad interna
const double K=3; // constante de elasticidad de los extremos 
const double G=-9.8; // m/s^2
const double NSTEPS=1800; // número de intervalos 
const double DT=0.001; // segundos
const double u=0.03; // coeficiente de fricción 
const double mass=1.0;
// declaración de funciones


void initial_conditions(std::vector<Particle> & balls);
void compute_force(std::vector<Particle> & balls);
void start_integration(std::vector<Particle> & balls);
void integrate(std::vector<Particle> & balls);
void print_info(const std::vector<Particle> & balls, const double & time);
void rk4(double ta, double tb, double h, std::vector<double> & y);
double f(double t, const std::vector<double> & y, int id);
//void print(const std::vector<Particle> & balls);
