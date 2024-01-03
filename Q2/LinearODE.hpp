#ifndef linear_ODE_header
#define linear_ODE_header

#include "ODEInterface.hpp"

class LinearODE : public ODEInterface
{
public:
    LinearODE();
    LinearODE(const double a);

    void SetA(const double a);

    void ComputeF(const double t, const double u, double& f) const;
    void ComputeG(const double t, const double u, double& g) const;
    void ComputeAnalyticSolution( const double t, double& u ) const;
    void GetA(double& a) const;

protected: 
    double mA;
};

#endif