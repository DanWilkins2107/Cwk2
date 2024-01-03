#include "ODEInterface.hpp"

// Set exact solution to zero by default
void ODEInterface::ComputeAnalyticSolution(const double t, double& u) const
{
    u = 0.0;
}

// Destructor
ODEInterface::~ODEInterface()
{
}
