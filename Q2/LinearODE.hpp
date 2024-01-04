#ifndef linear_ODE_header
#define linear_ODE_header

#include "ODEInterface.hpp"

class LinearODE : public ODEInterface
{
  public:
    // Overwritten default constructor
    LinearODE();
    // Constructor that takes in value of mA
    LinearODE(const double a);

    // SetA
    void SetA(const double a);

    // Function to Compute F
    void ComputeF(const double t, const double u, double& f) const;

    // Function to get the exact solution for time t
    void ComputeAnalyticSolution(const double t, double& u) const;

    // Function to access mA
    void GetA(double& a) const;

  protected:
    double mA;
};

#endif