#include "LinearODE.hpp"
#include <cmath>

// Default constructor
LinearODE::LinearODE()
{
}

// Constructor that sets mA
LinearODE::LinearODE(const double a)
{
    SetA(a);
}

//Function to set the value of mA
void LinearODE::SetA(const double a)
{
    mA = a;
}

// Function that computes the RHS
void LinearODE::ComputeF(const double t, const double u, double& f) const
{   
    f = mA * u + sin(t);
}

// Public function to access mA
void LinearODE::GetA(double& a) const
{
    a = mA;
}

// Function to compute the exact solution for time t
void LinearODE::ComputeAnalyticSolution(const double t, double& u) const
{
    u = (exp(mA * t) - mA * sin(t) - cos(t)) / (pow(mA, 2) + 1);
}
