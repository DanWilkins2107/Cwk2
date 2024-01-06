#include "ODEInterface.hpp"


// Set exact solution to a vector of size 1 by default
void ODEInterface::ComputeAnalyticSolution( const double t, Vector& u ) const
{
  u = Vector(1);
}


// Destructor
ODEInterface::~ODEInterface()
{
}
