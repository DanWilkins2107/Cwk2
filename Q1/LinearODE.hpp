#ifndef linear_ODE_header
#define linear_ODE_header

#include "ODEInterface.hpp"

class LinearODE : public ODEInterface
{
public:
    LinearODE();
    LinearODE(const double a);

    void SetA(const double a);

    void ComputeF(const double t, const double u, double& f);
    void ComputeAnalyticSolution( const double t, double& u );

protected: 
    double mA;
};

#endif