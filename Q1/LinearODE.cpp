#include "LinearODE.hpp"
#include <cmath>

// Overridden default constuctor
LinearODE::LinearODE()
{
}

// Constructor that takes a as a parameter
LinearODE::LinearODE(const double a)
{
    SetA(a);
}

// Function that sets mA
void LinearODE::SetA(const double a)
{
    mA = a;
}

// Function that computes the RHS of equation 12
void LinearODE::ComputeF(const double t, const double u, double& f) const
{
    f = mA * u + sin(t);
}

// Function that computes the exact answer for a value of t
void LinearODE::ComputeAnalyticSolution(const double t, double& u) const
{
    u = (exp(mA * t) - mA * sin(t) - cos(t)) / (pow(mA, 2) + 1);
}
