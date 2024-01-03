#ifndef ODEINTERFACEHEADERDEF
#define ODEINTERFACEHEADERDEF

// Interface class for fisrt order ODE IVPs

class ODEInterface
{

  public:
    // Compute right-hand side (pure virtual)
    virtual void ComputeF(const double t, const double u, double& f) const = 0;

    // Compute g(t) (pure virtual)
    virtual void ComputeG(const double t, const double u, double& g) const = 0;

    // Get A in linearODEs
    virtual void GetA(double& a) const = 0;

    // Compute analytical solution
    virtual void ComputeAnalyticSolution(const double t, double& u) const;

    // Virtual destructor
    virtual ~ODEInterface();
};

#endif
