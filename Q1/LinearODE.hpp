#ifndef linear_ODE_header
#define linear_ODE_header

#include "ODEInterface.hpp"

class LinearODE : public ODEInterface
{
  public:
    // Overridden default constructor
    LinearODE();
    // Constructor that takes in the value of a
    LinearODE(const double a);

    // Function that sets the value of a
    void SetA(const double a);

    // Function that computes the RHS of Equation 12
    void ComputeF(const double t, const double u, double& f) const;
    // Function that computes the exact answer for a value of t
    void ComputeAnalyticSolution(const double t, double& u) const;

  // Variables private as LinearODE is not a base class for any derived classes
  private:
    double mA;
};

#endif