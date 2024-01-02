#ifndef ODEINTERFACEHEADERDEF
#define ODEINTERFACEHEADERDEF

// Interface class for first order ODE IVPs

class ODEInterface
{

public:
    // Compute right-hand side (pure virtual)
    virtual void ComputeF(const double t, const double u, double& f) const = 0;

    // Compute analytical solution
    virtual void ComputeAnalyticSolution(const double t, double& u) const;

    // Virtual destructor
    virtual ~ODEInterface();
};

#endif
