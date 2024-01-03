#include "LinearODE.hpp"
#include <cmath>

LinearODE::LinearODE()
{
}

LinearODE::LinearODE(const double a)
{
    SetA(a);
}

void LinearODE::SetA(const double a)
{
    mA = a;
}

void LinearODE::ComputeF(const double t, const double u, double& f) const {
    f = mA * u + sin(t);
}

void LinearODE::ComputeAnalyticSolution(const double t, double& u ) const {
    u = (exp(mA * t) - mA * sin(t) - cos(t))/(pow(mA, 2) + 1);
}

