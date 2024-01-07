#ifndef ODEINTERFACEHEADERDEF
#define ODEINTERFACEHEADERDEF

#include "Vector.hpp"
#include "Matrix.hpp"


// Interface class for fisrt order ODE IVPs

class ODEInterface
{

  public:
    // Compute right-hand side (pure virtual)
    virtual void ComputeF(const double t, const Vector u, Vector& f) const = 0;

    // Compute analytical solution
    virtual void ComputeAnalyticSolution(const double t, Vector& u) const;

    // Apply Dirichlet Boundary Conditions
    virtual void ApplyDirichlet(const double t, Vector& u) = 0;

    virtual void ComputeMatrix(Matrix& A) const = 0;

    // Virtual destructor
    virtual ~ODEInterface();
};

#endif
